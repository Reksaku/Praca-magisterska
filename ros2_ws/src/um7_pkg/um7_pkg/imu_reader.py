#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rsl_comm_py import UM7Serial
from custom_msgs.msg import ImuData, AccelData, GyroData
import time

G_force = 9.80665
#G_force = 9.81228 # Warsaw g value

# ==============================================================================
# -- DataColection ---------------------------------------------------------------
# ==============================================================================
class MainData:
    def __init__(self):
        self.um7 = UM7Serial(port_name='/dev/ttyAMA0')
        self.um7.calibrate_accelerometers = 1
        time.sleep(0.5)
        self.um7.creg_com_rates2 = 255
    
    def do_magic(self, publisher):
        msg = ImuData()
        msg.accel = AccelData()
        msg.gyro = GyroData()

        for packet in self.um7.recv_all_proc_broadcast(num_packets=1000, flush_buffer_on_start=True):
            msg.timestamp = int(packet.accel_proc_time*1000000)
            msg.accel.x = float(packet.accel_proc_x * G_force)
            msg.accel.y = float(packet.accel_proc_y * G_force)
            msg.accel.z = float(packet.accel_proc_z * G_force)
            msg.gyro.x = float(packet.gyro_proc_x*3.1416/360)
            msg.gyro.y = float(packet.gyro_proc_y*3.1416/360)
            msg.gyro.z = float(packet.gyro_proc_z*3.1416/360)
            publisher.publish(msg)
        
        

        # for packet in self.um7.recv_all_raw_broadcast(1):
        #     msg.timestamp = int(packet.accel_raw_time*1000)
        #     msg.accel.x = float(packet.accel_raw_x/806)
        #     msg.accel.y = float(packet.accel_raw_y/806)
        #     msg.accel.z = float(packet.accel_raw_z/806)
        #     msg.gyro.x = float(packet.gyro_raw_x/806)
        #     msg.gyro.y = float(packet.gyro_raw_y/806)
        #     msg.gyro.z = float(packet.gyro_raw_z/806)
        # print(dir(packet))
        # return msg
        #print(data.time_usec)



class UM7Node(Node):
    def __init__(self):
        super().__init__("imu_reader")
        self.get_logger().info("Node init complete")

        self.public_data = MainData()

        self.publisher_ = self.create_publisher(ImuData, "imu_data", 100)

        self.timer_ = self.create_timer(1/100, self.timer_function)

    def timer_function(self):
        self.public_data.do_magic(self.publisher_)



def main(args=None):
    rclpy.init(args=args)
    node = UM7Node()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
