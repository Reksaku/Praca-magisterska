#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from custom_msgs.msg import ImuData, EstimatorData, PossitionData
import numpy as np
import math
from datetime import datetime


# G_force = 9.80665
G_force = 9.81228 # Warsaw g value


global real_object
position = np.array([0, 0, 0]) # X, Y and Z axis
speed = np.array([0, 0, 0]) # X, Y and Z axis
acceleration = np.array([0, 0, 0]) # X, Y and Z axis
angle = np.array([0, 0, 0]) # roll, pitch and yaw in rad
real_object = [position, speed, acceleration, angle]
IMU_data = [np.array([0, 0, 0]), np.array([0, 0, 0]), 0] #accelerator and gyroscope data


class EstimatorClass():
    def __init__(self):
        print("Estimator class init")        

    def Estimate_angle(self, gyroscope, angle, dt):
        roll = angle[0] + gyroscope[0] * dt
        pitch = angle[1] + gyroscope[1] * dt
        yaw = angle[2] + gyroscope[2] * dt
        
        angle = [roll, pitch, yaw]

        return angle
    
    def Estimate_angle_cheat(self, gyroscope, angle, dt):
        new_angle = [0, 0, 0]
        for i in range(0,3):
            if abs(gyroscope[i]) >= 0.005:
                new_angle[i] = angle[i] + gyroscope[i] * dt
            else:
                new_angle[i] = angle[i]

        return new_angle

    def Estimate_velocity(self,velocity, acceleration, dt):
        velocity = velocity + acceleration * dt * [1, 1, -1]
        
        velocity = np.asarray(velocity).flatten()
        return velocity
    
    def Estimate_velocity_cheat(self,velocity, acceleration, dt):
        temp = [0, 0, 0]
        for i in range(0,3):
            if abs(acceleration[i]) >= 0.005:
                temp[i] = velocity[i] + acceleration[i]*dt
            else:
                temp[i] = velocity[i]

        temp = np.asarray(temp).flatten()
        return temp

    def Estimate_position(self, velocity, position, dt):
        position = position + velocity*dt

        position = np.asarray(position).flatten()
        
        return position

    # Przekształcenie przyśpieszeń z IMU do układu globalnego
    def Calculate_acceleration(self, acceleration, angle):
        roll = -angle[0]
        pitch = -angle[1]
        yaw = -angle[2]

        gravity_force = np.array([0, 0, G_force])

        R_x = np.matrix([[1, 0, 0], 
                       [0, math.cos(roll), -math.sin(roll)], 
                       [0, math.sin(roll), math.cos(roll)]])
        
        R_y = np.matrix([[math.cos(pitch), 0, math.sin(pitch)],
                        [0, 1, 0],
                        [-math.sin(pitch), 0, math.cos(pitch)]])
        
        R_z = np.matrix([[math.cos(yaw), -math.sin(yaw), 0],
                         [math.sin(yaw), math.cos(yaw), 0],
                         [0, 0, 1]])
        
        Euler_matrix_zy = np.dot(R_z, R_y)
        Euler_matrix = np.dot(Euler_matrix_zy, R_x)
        
        local_G_force = np.dot(gravity_force, Euler_matrix)
        local_G_force = np.asarray(local_G_force).flatten()
        local_acceleration = acceleration - np.array([local_G_force[0], local_G_force[1], local_G_force[2]])
        local_acceleration = np.asarray(local_acceleration).flatten()
        return local_acceleration
    
    
    def Update_status(self, position, velocity, acceleration, angle):
        global real_object 
        real_object = [position, velocity, acceleration, angle]

    def do_magic(self, object, data, dt, tester= False):
        position = object[0]
        velocity = object[1]
        angle = object[3]
        acceleration_data = data[0]
        gyroscope_data = data[1]


        angle = self.Estimate_angle(gyroscope_data, angle, dt)

        acceleration = self.Calculate_acceleration(acceleration_data, angle)

        if tester == False: 
            velocity = self.Estimate_velocity(velocity, acceleration, dt)
        else:
            velocity = self.Estimate_velocity_cheat(velocity, acceleration, dt)

        position = self.Estimate_position(velocity, position, dt)

        self.Update_status(position, velocity, acceleration, angle)


class MyEstimator(Node):
    def __init__(self):
        super().__init__("estimator_node") 
        self.estimator = EstimatorClass()
        self.last_timestamp = 0
        self.subscription = self.create_subscription(
            ImuData,
            'imu_data',
            self.listener_callback,
            100)
        self.subscription  # zapobiega usunięciu subskrypcji przez garbage collector
        self.publisher_ = self.create_publisher(EstimatorData, "estimation_data", 100)

    def listener_callback(self, msg):
        if self.last_timestamp == 0:
            self.last_timestamp = msg.timestamp
        dt = (msg.timestamp - self.last_timestamp)/1000000
        self.last_timestamp = msg.timestamp
        if dt > 0.02:
            return
        global real_object
        IMU_data = [[msg.accel.x, msg.accel.y, msg.accel.z], [msg.gyro.x, msg.gyro.y, msg.gyro.z], msg.timestamp]
        self.estimator.do_magic(real_object, IMU_data, dt)

        self.get_logger().info('dt: %f, Estymata: "%f, %f, %f"' % (dt, real_object[1][0], real_object[1][1], real_object[1][2]))
        
        data = EstimatorData()
        data.possition = PossitionData()
        data.possition.x = real_object[0][0]
        data.possition.y = real_object[0][1]
        data.possition.z = real_object[0][2]
        data.timestamp = 0

        self.publisher_.publish(data)


def main(args=None):
    rclpy.init(args=args)
    node = MyEstimator() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
