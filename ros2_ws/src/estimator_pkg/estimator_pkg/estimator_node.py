#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from custom_msgs.msg import ImuData, EstimatorData, DataXYZ
from example_interfaces.msg import String
import numpy as np
import math
from datetime import datetime
from scipy.signal import firwin, lfilter


G_force = 9.80665
#G_force = 9.81228 # Warsaw g value


global real_object
position = np.array([0, 0, 0]) # X, Y and Z axis
speed = np.array([0, 0, 0]) # X, Y and Z axis
acceleration = np.array([0, 0, 0]) # X, Y and Z axis
angle = np.array([0, 0, 0]) # roll, pitch and yaw in rad
real_object = [position, speed, acceleration, angle]
IMU_data = [np.array([0, 0, 0]), np.array([0, 0, 0]), 0] #accelerator and gyroscope data


# ==============================================================================
# -- Lowpass filter ---------------------------------------------------------------
# ==============================================================================

class RealTimeFilter:
    def __init__(self, filter):
        if filter == "highpass":
            # Parametry filtru
            self.passband = 0.0025 # Znormalizowana częstotliwość graniczna pasma przepustowego
            # Oblicz współczynniki filtru
            self.n = 5
            self.taps = firwin(self.n, self.passband, pass_zero='highpass', fs=400)   
            
        elif filter == "lowpass":
            # Parametry filtru
            self.passband = 0.025 - 0.01 # Znormalizowana częstotliwość graniczna pasma przepustowego
            # Oblicz współczynniki filtru
            self.n = 20
            self.taps = firwin(self.n, self.passband, pass_zero='lowpass', fs=400)

        elif filter == "lowpass_calib":
            # Parametry filtru
            self.passband = 0.025 - 0.015 # Znormalizowana częstotliwość graniczna pasma przepustowego
            # Oblicz współczynniki filtru
            self.n = 100
            self.taps = firwin(self.n, self.passband, pass_zero='lowpass', fs=400)

        
        # Bufor danych (przechowuje N ostatnich próbek)
        self.buffer = []
        for i in range(0,6):
            if i != 2:
                self.buffer.append(np.zeros(len(self.taps) - 1))  # stan początkowy
            else:
                self.buffer.append(np.zeros(len(self.taps) - 1) - G_force)

        
        self.filtered_sample = [0, 0, G_force, 0, 0, 0]

    def process_sample(self, new_sample):
        for i in range(0,6):
            # Aktualizuj bufor: dodaj nową próbkę na koniec
            input_signal = np.concatenate([self.buffer[i], [new_sample[i]]])
            
            # Filtruj (użyj tylko ostatniej próbki wyjściowej)
            output_signal = lfilter(self.taps, 1.0, input_signal)
            self.filtered_sample[i] = output_signal[-1]
            
            # Zaktualizuj bufor dla następnego cyklu
            self.buffer[i] = input_signal[1:]
        
        return self.filtered_sample

    def filter_data(self, IMU_data):

        temp_struct = [IMU_data[0][0], IMU_data[0][1], IMU_data[0][2], IMU_data[1][0], IMU_data[1][1], IMU_data[1][2]]
        temp_struct = self.process_sample(temp_struct)
        IMU_data[0][0] = temp_struct[0]
        IMU_data[0][1] = temp_struct[1]
        IMU_data[0][2] = temp_struct[2]
        IMU_data[1][0] = temp_struct[3]
        IMU_data[1][1] = temp_struct[4]
        IMU_data[1][2] = temp_struct[5]
        return IMU_data

# ==============================================================================
# -- Estymator ---------------------------------------------------------------
# ==============================================================================

class EstimatorClass():
    def __init__(self):
        print("Estimator class init")        

    def Estimate_angle(self, gyroscope, angle, dt):
        roll = angle[0] + gyroscope[0] * dt
        pitch = angle[1] + gyroscope[1] * dt
        yaw = angle[2] + gyroscope[2] * dt
        
        angle = [roll, pitch, yaw]

        return angle


    def Estimate_angle_complementary(self, gyroscope, acceleration, angle, dt):
        alpha = 0.996
        new_angle = [0, 0, 0]
        
        # Integracja prędkości kątowej
        gyro_roll = angle[0] + gyroscope[0] * dt
        gyro_pitch = angle[1] + gyroscope[1] * dt
        gyro_yaw = angle[2] + gyroscope[2] * dt
        
        # Odczyty z akcelerometru
        acc_roll = np.arctan2(acceleration[1], -acceleration[2])
        acc_pitch = np.arctan2(-acceleration[0], np.sqrt(acceleration[1]**2 + acceleration[2]**2))

        # Fuzja danyc
        new_angle[0] = alpha * gyro_roll + (1 - alpha) * acc_roll
        new_angle[1] = alpha * gyro_pitch + (1 - alpha) * acc_pitch
        new_angle[2] = gyro_yaw
    
        return new_angle


    def Estimate_velocity(self,velocity, acceleration, dt):
        velocity = velocity + acceleration * dt
        velocity = np.asarray(velocity).flatten()
        return velocity
    
    def Estimate_velocity_cheat(self,velocity, acceleration, dt):
        temp = [0, 0, 0]
        for i in range(0,3):
            if abs(acceleration[i]) >= 0.025:
                temp[i] = velocity[i] + acceleration[i]*dt
            else:
                temp[i] = velocity[i]

        temp = np.asarray(temp).flatten()
        return temp
    
    def Decrease_velocity(self,velocity, dt):
        velocity = velocity - velocity * 0.01
        return velocity
        

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
        local_acceleration = acceleration - np.array([local_G_force[0], local_G_force[1], -local_G_force[2]])
        local_acceleration = np.asarray(local_acceleration).flatten()
        local_acceleration[0] -= 0.005
        return local_acceleration
    
    
    def Update_status(self, position, velocity, acceleration, angle):
        global real_object 
        real_object = [position, velocity, acceleration, angle]

    def do_magic(self, object, data, dt):
        position = object[0]
        velocity = object[1]
        angle = object[3]
        acceleration_data = data[0]
        gyroscope_data = data[1]

        #angle = self.Estimate_angle(gyroscope_data, angle, dt)
        angle = self.Estimate_angle_complementary(gyroscope_data, acceleration_data, angle, dt)
        
        acceleration = self.Calculate_acceleration(acceleration_data, angle)

        velocity = self.Estimate_velocity_cheat(velocity, acceleration, dt)

        velocity = self.Decrease_velocity(velocity, dt)

        position = self.Estimate_position(velocity, position, dt)

        self.Update_status(position, velocity, acceleration, angle)

    def applay_offsets(self, IMU_data, offsets):
        IMU_data[0][0] = IMU_data[0][0] - offsets[0]
        IMU_data[0][1] = IMU_data[0][1] - offsets[1]
        IMU_data[0][2] = IMU_data[0][2] - offsets[2]
        IMU_data[1][0] = IMU_data[1][0] - offsets[3]
        IMU_data[1][1] = IMU_data[1][1] - offsets[4]
        IMU_data[1][2] = IMU_data[1][2] - offsets[5]
        return IMU_data

# ==============================================================================
# -- Node ---------------------------------------------------------------
# ==============================================================================

class MyEstimator(Node):
    def __init__(self):
        super().__init__("estimator_node") 
        self.estimator = EstimatorClass()
        self.filter_LP = RealTimeFilter("lowpass")
        self.filter_HP = RealTimeFilter("highpass")
        self.filter_LP_calibration = RealTimeFilter("lowpass_calib")
        self.calibrator = [0, 0, 0, 0, 0, 0, 0]
        self.mode = 'calibration'
        self.last_timestamp = 0

        self.subscription = self.create_subscription(
            ImuData,
            'imu_data',
            self.listener_callback,
            100)
        self.flaskSubscription = self.create_subscription(
            String,
            'flask_commands',
            self.listener_flask_callback,
            10)
        self.subscription 
        self.flaskSubscription
        self.publisher_ = self.create_publisher(EstimatorData, "estimation_data", 100)


    def perform_estimate(self, IMU_data, dt):
        global real_object
        IMU_data = self.estimator.applay_offsets(IMU_data, self.calibrator)
        IMU_data = self.filter_LP.filter_data(IMU_data) # Filtr dolnoprzepustowy
        IMU_data = self.filter_HP.filter_data(IMU_data) # Filtr górnoprzepustowy
        self.estimator.do_magic(real_object, IMU_data, dt)


    def perform_calibration(self, IMU_data):
        IMU_data = self.filter_LP_calibration.filter_data(IMU_data) # Filtr dolnoprzepustowy
        iterations = 1000
        if(self.calibrator[6] == iterations):
            for i in range(0,6):
                self.calibrator[i] = self.calibrator[i]/iterations
            self.mode = 'estimation'
            self.calibrator[2] += G_force
            print(self.calibrator)
        else:
            for i in range(0,2):
                for j in range(0,3):
                    self.calibrator[j+i*2] += IMU_data[i][j]
            self.calibrator[6] += 1
            print(self.calibrator[6])


    def listener_flask_callback(self, msg):
        if(msg.data == 'reset'):
            print('Reset')
            global real_object
            position = np.array([0, 0, 0]) # X, Y and Z axis
            speed = np.array([0, 0, 0]) # X, Y and Z axis
            acceleration = np.array([0, 0, 0]) # X, Y and Z axis
            angle = np.array([0, 0, 0]) # roll, pitch and yaw in rad
            real_object = [position, speed, acceleration, angle]
        elif(msg.data == 'calibrate'):
            self.calibrator = [0, 0, 0, 0, 0, 0, 0]
            self.mode = 'calibration'
            print('Re-calibrate')


    def listener_callback(self, msg):
        if self.last_timestamp == 0:
            self.last_timestamp = msg.timestamp
        dt = (msg.timestamp - self.last_timestamp)/1000000
        self.last_timestamp = msg.timestamp
        IMU_data = [[msg.accel.x, msg.accel.y, msg.accel.z], [msg.gyro.x, msg.gyro.y, msg.gyro.z], msg.timestamp]

        if(self.mode == 'estimation'):
            self.perform_estimate(IMU_data, dt)
        elif(self.mode == 'calibration'):
            self.perform_calibration(IMU_data)

        self.publisher_.publish(self.prepare_msg())


    def prepare_msg(self):
        global real_object
        data = EstimatorData()
        data.possition = DataXYZ()
        data.speed = DataXYZ()
        data.accel = DataXYZ()
        data.rotation = DataXYZ()

        data.possition.x = float(real_object[0][0]*100)
        data.possition.y = float(real_object[0][1]*100)
        data.possition.z = float(-real_object[0][2]*100)

        data.speed.x = float(real_object[1][0])
        data.speed.y = float(real_object[1][1])
        data.speed.z = float(real_object[1][2])

        data.accel.x = float(real_object[2][0])
        data.accel.y = float(real_object[2][1])
        data.accel.z = float(real_object[2][2])

        data.rotation.x = float(real_object[3][0])
        data.rotation.y = float(real_object[3][1])
        data.rotation.z = float(real_object[3][2])

        data.timestamp = 0
        return data

def main(args=None):
    rclpy.init(args=args)
    node = MyEstimator() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
