#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from pymavlink import mavutil
from custom_msgs.msg import ImuData, AccelData, GyroData

# ==============================================================================
# -- MavLink ---------------------------------------------------------------
# ==============================================================================
class MavLinkConfigurator:
    def __init__(self, com= '/dev/ttyACM0', baud= 115200):
        # Create the connection
        self.master = mavutil.mavlink_connection(com, baud)
        # Wait a heartbeat before sending commands
        self.master.wait_heartbeat()

    def end_connection(self):
        self.master.close()

    
    def request_message(self, mess_type= 'HIGHRES_IMU'):
        try:
            mes = self.master.recv_match(type= mess_type, blocking= True)
            if mes.msgname == mess_type:
                return mes
            else:
                return self.request_message(mess_type)
        except:
            return None

    def request_message_interval(self, message_id: int, frequency_hz: float):
        self.master.mav.command_long_send(
            self.master.target_system, self.master.target_component,
            mavutil.mavlink.MAV_CMD_SET_MESSAGE_INTERVAL, 0,
            message_id, # The MAVLink message ID
            1e6 / frequency_hz, # The interval between two messages in microseconds. Set to -1 to disable and 0 to request default rate.
            0, 0, 0, 0, # Unused parameters
            0, # Target address of message stream (if message has target address fields). 0: Flight-stack default (recommended), 1: address of requestor, 2: broadcast.
        )

    def tune(self, tune= "t200 o2 a8 a4"):
        target_system = self.master.target_system
        target_component = self.master.target_component

        # Podział melodii na dwie części, jeśli jest dłuższa niż 30 znaków
        tune1 = tune[:30]
        tune2 = tune[30:]

        # Wysłanie wiadomości
        self.master.mav.play_tune_send(
            target_system,
            target_component,
            tune1.encode(),
            tune2.encode()
        )

    def show_me_everything(self):
        while True:
            mes = self.master.recv_msg()
            if mes:
                print(mes)               

# ==============================================================================
# -- DataColection ---------------------------------------------------------------
# ==============================================================================
class MainData:
    def __init__(self):
        self.connection = MavLinkConfigurator()
        freq = 100

        self.connection.request_message_interval(105, freq) # HIGHRES_IMU request at 100 Hz

        self.connection.tune()

    
    def do_magic(self):
        msg = ImuData()
        msg.accel = AccelData()
        msg.gyro = GyroData()

        data = self.connection.request_message()

        msg.timestamp = data.time_usec
        msg.accel.x = data.xacc
        msg.accel.y = data.yacc
        msg.accel.z = data.zacc
        msg.gyro.x = data.xgyro
        msg.gyro.y = data.ygyro
        msg.gyro.z = data.zgyro
        
        return msg
        #print(data.time_usec)

# ==============================================================================
# -- Node ---------------------------------------------------------------
# ==============================================================================
class imuReaderNode(Node): 
    def __init__(self):
        super().__init__("imu_reader")  
        self.get_logger().info("Node init complete")
        
        self.public_data = MainData()

        self.publisher_ = self.create_publisher(ImuData, "imu_data", 100)

        self.timer_ = self.create_timer(0.001, self.timer_function)

    def timer_function(self):
        msg = self.public_data.do_magic()
        self.publisher_.publish(msg)
        
    

# ==============================================================================
# -- Main ---------------------------------------------------------------
# ==============================================================================
def main(args=None):
    rclpy.init(args=args)
    node = imuReaderNode() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
