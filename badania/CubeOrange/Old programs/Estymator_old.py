import numpy as np
import math
import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import time

global real_object
global IMU_data
position = np.array([0, 0, 0]) # X, Y and Z axis
speed = np.array([0, 0, 0]) # X, Y and Z axis
angle = np.array([0, 0, 0]) # roll, pitch and yaw in rad
real_object = [position, speed, angle]
IMU_data = [np.array([0, 0, 9.81]), np.array([0, 0, 0]), 0] #accelerator and gyroscope data


class EstimatorClass():
    def __init__(self):
        print("Estimator code sectio")        

    def Estimate_angle(self, gyroscope, angle, dt):

        roll = angle[0] + gyroscope[0] * dt
        pitch = angle[1] + gyroscope[1] * dt
        yaw = angle[2] + gyroscope[2] * dt
        
        angle = [roll, pitch, yaw]
        
        return angle

    def Estimate_velocity(self,velocity, acceleration, dt):
        velocity = velocity + acceleration*dt
        
        velocity = np.asarray(velocity).flatten()
        return velocity

    def Estimate_position(self, velocity, position, dt):
        position = position + velocity*dt

        position = np.asarray(position).flatten()
        
        return position

    # Przekształcenie przyśpieszeń z IMu do układu globalnego (IMU jest na płasko, zgodnie z osiami świata)
    def Calculate_acceleration(self, acceleration, angle):
        roll = angle[0]
        pitch = angle[1]
        yaw = angle[2]

        gravity_force = np.array([0, 0, 9.81])

        R_x = np.matrix([[1, 0, 0], 
                       [0, math.cos(roll), -math.sin(roll)], 
                       [0, math.sin(roll), math.cos(roll)]])
        
        R_y = np.matrix([[math.cos(pitch), 0, math.sin(pitch)],
                        [0, 1, 0],
                        [-math.sin(pitch), 0, math.cos(pitch)]])
        
        R_z = np.matrix([[math.cos(yaw), -math.sin(yaw), 0],
                         [math.sin(yaw), math.cos(yaw), 0],
                         [0, 0, 1]])
        
        Euler_matrix = np.dot(np.dot(R_z, R_y), R_x)
        global_acceleration = np.dot(Euler_matrix, acceleration)
        global_acceleration = global_acceleration - gravity_force
        global_acceleration = np.asarray(global_acceleration).flatten()
        return global_acceleration
    
    def Update_status(self, position, velocity, angle):
        global real_object 
        real_object = [position, velocity, angle]


def program_loop(estimator, object, data, dt):
    position = object[0]
    velocity = object[1]
    angle = object[2]
    acceleration_data = data[0]
    gyroscope_data = data[1]

    angle = estimator.Estimate_angle(gyroscope_data, angle, dt)
    acceleration = estimator.Calculate_acceleration(acceleration_data, angle)
    velocity = estimator.Estimate_velocity(velocity, acceleration, dt)
    position = estimator.Estimate_position(velocity, position, dt)

    estimator.Update_status(position, velocity, angle)

def load_CSV():
    data = pd.read_csv("imu_data.csv")
    deadband = 0
    accelerometer = np.array(data.iloc[deadband:, 1:4])
    gyroscope = np.array(data.iloc[deadband:, 4:7])
    #compass = np.array(data.iloc[deadband:, 7])
    timestamp = np.array(data.iloc[deadband:, 0])
    sensor_data = [accelerometer, gyroscope, timestamp]
    return sensor_data

def draw_plot(data):
    plt.close()
    plt.ion()
    x, y, z = zip(*data)
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.plot(x, y, z, label="Trajektoria")
    ax.scatter(x, y, z, color='red')
    
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')

    ax.legend()
    plt.show()
    

def aktualizuj_wykres(trajektoria, fig, ax):
    """
    Funkcja aktualizuje wykres trajektorii w 3D.
    """

    # Czyści istniejący wykres
    ax.clear()

    # Rysowanie nowej trajektorii
    trajektoria_array = np.array(trajektoria)  # Konwersja listy na tablicę NumPy
    if trajektoria_array.shape[0] > 1:  # Sprawdzenie, czy są dane do rysowania
        x, y, z = trajektoria_array[:, 0], trajektoria_array[:, 1], trajektoria_array[:, 2]
        ax.plot(x, y, z, label='Trajektoria 3D')
    
    # Ustawienia wykresu
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    ax.set_title('Trajektoria 3D Obiektu')
    ax.legend()

    # Aktualizacja wyświetlenia
    plt.pause(0.1)


def main():
    estimator = EstimatorClass()
    global real_object
    global IMU_data
    position_data = []
    file_data = load_CSV()
    print(len(file_data[0]))
    iterations = len(file_data[0])
    percent = 0.1

    # Inicjalizacja wykresu
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    
    last_call_time = time.time()
    interval = 1
    print(IMU_data)
    for i in range(1,iterations):
        dt = (file_data[2][i] - file_data[2][i-1])/1000000
        IMU_data = [file_data[0][i], file_data[1][i], file_data[2][i]]
        program_loop(estimator, real_object, IMU_data, dt)
        position_data.append(real_object[0])

        if time.time() - last_call_time >= interval:
            #aktualizuj_wykres(position_data, fig, ax)
            last_call_time = time.time()

        if i >= iterations*percent:
            print("Ukończono " + str(percent*100) + "% trasy")       
            percent = percent + 0.1
    aktualizuj_wykres(position_data, fig, ax)
    print("Ukończono 100% trasy")

    #for i in range(0,len(position_data)):
    #    print(position_data[i])
    # Wyłączenie trybu interaktywnego
    plt.ioff()
    plt.show()

if __name__ == "__main__":
    main()