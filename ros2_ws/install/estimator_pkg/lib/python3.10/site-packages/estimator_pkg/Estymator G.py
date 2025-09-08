import numpy as np
import math
import pandas as pd #type: ignore
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import csv # Import csv for save to file
import os
from scipy import signal
from scipy.signal import kaiserord, firwin, firwin2, lfilter, buttord
import subprocess

from sklearn.linear_model import LinearRegression #type: ignore

# G_force = 9.80665
G_force = 9.81228 # Warsaw g value

global real_object
global IMU_data
position = np.array([0, 0, 0]) # X, Y and Z axis
speed = np.array([0, 0, 0]) # X, Y and Z axis
acceleration = np.array([0, 0, 0]) # X, Y and Z axis
angle = np.array([0, 0, 0]) # roll, pitch and yaw in rad
real_object = [position, speed, acceleration, angle, 0]
IMU_data = [np.array([0, 0, 0]), np.array([0, 0, 0]), 0] #accelerator and gyroscope data

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
        local_acceleration = acceleration - [local_G_force[0], local_G_force[1], local_G_force[2]]
        local_acceleration = np.asarray(local_acceleration).flatten()
        return local_acceleration
    
    
    def Update_status(self, position, velocity, acceleration, angle, dt):
        global real_object 
        real_object = [position, velocity, acceleration, angle, dt]

    def do_magic(self, object, data, dt, timestamp, tester= False):
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

        self.Update_status(position, velocity, acceleration, angle, timestamp)

# ==============================================================================
# -- CSV ---------------------------------------------------------------
# ==============================================================================

class DataLogger:
    def __init__(self):
        pass


    def regresion(self, csvka):
        # Utwórz model regresji
        model = LinearRegression()


        X = csvka[['Accelerometer_Y']].values  # Zmienna niezależna (musi być tablicą 2D)

        y = csvka['Temperature'].values    # Zmienna zależna

        # Dopasuj model do danych
        model.fit(X, y)

        # Współczynniki regresji
        intercept = model.intercept_  # Wyraz wolny (b)
        slope = model.coef_[0]        # Nachylenie (a)

        print(f"Funkcja liniowa: y = {slope}x + {intercept}")


    def load_IMU_CSV(self, file= "imu_data.csv"):
        data = pd.read_csv(file)
        # if file == "static/imu_data.csv":
        #     self.regresion(data)
        deadband = 0
        accelerometer = np.array(data.iloc[deadband:, 1:4])
        gyroscope = np.array(data.iloc[deadband:, 4:7])
        timestamp = np.array(data.iloc[deadband:, 0])
        temperature = np.array(data.iloc[deadband:, 11])
        sensor_data = [accelerometer, gyroscope, timestamp, temperature]
        return sensor_data

    def add_proces_headers(self, filename):
        # Dodanie nagłówków do pliku tylko przy pierwszym zapisie
        with open(filename, mode= 'a', newline= '') as file:
            writer = csv.writer(file)

            writer.writerow([
            'Timestamp',
            'Accel_X', 'Accel_Y', 'Accel_Z', 
            'Speed_X', 'Speed_Y', 'Speed_Z', 
            'Position_X', 'Position_Y', 'Position_Z',
            'Pitch', 'Yaw', 'Roll'
            ])

    def remove_file(self, filename):
        # Jeśli plik już istnieje, usuń go, aby nadpisać od nowa
        if os.path.isfile(filename):
            os.remove(filename)

    def save_proces_data(self, data, filename):
        # Otwarcie pliku w trybie dołączania (append)
        with open(filename, mode='a', newline='') as file:
            writer = csv.writer(file)

            # Zapisanie danych IMU w formacie (x, y, z)
            writer.writerow([
                data[4],
                data[2][0],
                data[2][1],
                data[2][2],
                data[1][0],
                data[1][1],
                data[1][2],
                data[0][0],
                data[0][1],
                data[0][2],
                data[3][0],
                data[3][1],
                data[3][2],
            ])

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
            self.passband = 0.025 # Znormalizowana częstotliwość graniczna pasma przepustowego
            # Oblicz współczynniki filtru
            self.n = 20
            self.taps = firwin(self.n, self.passband, pass_zero='lowpass', fs=400)

            #self.min_attenuation = 7 # Minimalne tłumienie w paśmie zaporowym (dB)
            #self.n, alfa = kaiserord(self.min_attenuation, self.passband)
            #self.taps = firwin(self.n, self.passband, window=('kaiser', alfa), pass_zero='lowpass', fs=400)
        
        # Bufor danych (przechowuje N ostatnich próbek)
        self.buffer = []
        for i in range(0,6):
            if i != 2:
                self.buffer.append(np.zeros(len(self.taps) - 1))  # stan początkowy
            else:
                self.buffer.append(np.zeros(len(self.taps) - 1) + G_force)

        
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

    def filter_row(self):
        print(f"Rząd filtru IIR: {self.n}")

# ==============================================================================
# -- Kalman filter ---------------------------------------------------------------
# ==============================================================================

class ExtendedKalmanFilter:
    def __init__(self, initial_acc=0, initial_bias=0, q_acc=0.2, q_bias=0.05):
        # Stan: [błąd_a, błąd_omega]
        self.x = np.array([initial_acc, initial_bias], dtype=np.float64)  # początkowe oszacowanie błędów

        self.P = np.diag([1, 1])  # macierz kowariancji

        # Macierz przejścia (model dynamiki błędów - zakładamy stałe)
        self.F = np.array([[0, 0], [0, 0]])
        # Macierz obserwacji (zależność pomiarów od stanu)
        self.H = np.array([[1, 1], [1, 1], [1, 1]])
        # Szum procesu
        self.Q = np.array([[q_acc, 0], [0, q_bias]])
        # Szum pomiaru
        self.R = np.array([[0.1, 0, 0], # Szum pomiarowy zależne od dokładności IMU
                         [0, 10, 0],
                         [0, 0, 10]])  

    def predict(self):
        self.x = self.F @ self.x
        self.P = self.F @ self.P @ self.F.T + self.Q

    def update(self, z):
        self.predict()
        y = z - self.H @ self.x
        S = self.H @ self.P @ self.H.T + self.R
        K = self.P @ self.H.T @ np.linalg.inv(S)
        self.x = self.x + K @ y
        self.P = (np.eye(2) - K @ self.H) @ self.P
    
# ==============================================================================
# -- Matlab Plots ---------------------------------------------------------------
# ==============================================================================

class PlotsOperations():
    def __init__(self):
        pass    

    def aktualizuj_wykres(self, trajektoria, fig, ax, title= 'Trajektoria 3D Obiektu', axis_range= 2): # Rysowanie trajektorii
        trajektoria_array = np.array(trajektoria)  # Konwersja listy na tablicę NumPy
        if trajektoria_array.shape[0] > 1:  # Sprawdzenie, czy są dane do rysowania

            x, y, z = trajektoria_array[:, 0], trajektoria_array[:, 1], trajektoria_array[:, 2]
            ax.plot(x, y, z, label=title)
        
            # Ustawienia wykresu
            ax.set_xlabel('X')
            ax.set_ylabel('Y')
            ax.set_zlabel('Z')
            ax.set_title('Trajektoria 3D')
            
            ax.set_xlim(-axis_range, axis_range)
            ax.set_ylim(-axis_range, axis_range)
            ax.set_zlim(-axis_range, axis_range)
            ax.legend()

    def show_plots(self):
        plt.show()

# ==============================================================================
# -- main ---------------------------------------------------------------
# ==============================================================================



def main():
    ploting = PlotsOperations()
    filter_LP = RealTimeFilter("lowpass")
    filter_HP = RealTimeFilter("highpass")
    filter_LP.filter_row()

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    global real_object
    global IMU_data

    for iteration in range(1,5):
        if iteration == 1:
            final_file = 'estimations/estimation1.csv'
            title = 'Brak filtracji'

        elif iteration == 2:
            final_file = 'estimations/estimation2.csv'
            title = 'Filtr lowpass'
            
        elif iteration == 3:
            final_file = 'estimations/estimation3.csv'
            title = 'Kalman IMU'
            
        elif iteration == 4:
            final_file = 'estimations/estimation4.csv'
            title = 'Progowanie przyśpieszenia'
            


        position = np.array([0, 0, 0]) # X, Y and Z axis
        speed = np.array([0, 0, 0]) # X, Y and Z axis
        acceleration = np.array([0, 0, 0]) # X, Y and Z axis
        angle = np.array([0, 0, 0]) # roll, pitch and yaw in rad
        real_object = [position, speed, acceleration, angle, 0]
        IMU_data = [np.array([0, 0, 0]), np.array([0, 0, 0]), 0] #accelerator and gyroscope data


        estimator = EstimatorClass()
        CSV_data = DataLogger()
        kalman_x = ExtendedKalmanFilter(0.5, 0, q_acc=0.5, q_bias=0.05)
        kalman_y = ExtendedKalmanFilter(0.5, 0, q_acc=0.1, q_bias=0.05)
        kalman_z = ExtendedKalmanFilter(-G_force)
        
        


        position_data = []
        time_all = []
        time_all.append(0)
        #path = "dynamic/"
        #path = "static/"
        path = ""
        all_file_data = CSV_data.load_IMU_CSV(path+"imu_data.csv")
        all_file_data_2 = CSV_data.load_IMU_CSV(path+"imu2_data.csv")
        all_file_data_3 = CSV_data.load_IMU_CSV(path+"imu3_data.csv")
    
        CSV_data.remove_file(final_file)
        CSV_data.add_proces_headers(final_file)

        for i in range(1,len(all_file_data[0])):

            # Obliczanie czasu między pomiarami
            dt = (all_file_data[2][i] - all_file_data[2][i-1])/1000000
            
            # Symulacja odbioru danych - odczytanie kolejnego wiersza danych
            IMU_data = [all_file_data[0][i], all_file_data[1][i], all_file_data[2][i]]
            IMU_2_data = [all_file_data_2[0][i], all_file_data_2[1][i], all_file_data_2[2][i]]
            IMU_3_data = [all_file_data_3[0][i], all_file_data_3[1][i], all_file_data_3[2][i]]

            # Aktualizacja aktualnego czasu o dt
            if i != 0:
                time_all.append(time_all[i-1]+dt)

            if iteration >= 2:
                IMU_data = filter_LP.filter_data(IMU_data) # Filtr dolnoprzepustowy
                IMU_data = filter_HP.filter_data(IMU_data) # Filtr górnoprzepustowy


            if iteration >= 3:
                # Krok predykcji i aktualizacji EKF
                
                kalman_x.update(np.array([IMU_data[0][0], IMU_2_data[0][0], IMU_3_data[0][0]]))
                IMU_data[0][0] = IMU_data[0][0] - kalman_x.x[1]

                # Krok predykcji i aktualizacji EKF
                
                kalman_y.update(np.array([IMU_data[0][1], IMU_2_data[0][1], IMU_3_data[0][1]]))
                IMU_data[0][1] = IMU_data[0][1] - kalman_y.x[1]

                # # Krok predykcji i aktualizacji EKF
                # kalman_z.predict()
                # kalman_z.update(np.array([IMU_data[0][2], IMU_2_data[0][2], IMU_3_data[0][2]]))
                # IMU_data[0][2] = IMU_data[0][2] - kalman_z.x[1]


            # Estymowanie pozycji i orientacji
            if iteration != 4:
                estimator.do_magic(real_object, IMU_data, dt, time_all[i])
            else:
                estimator.do_magic(real_object, IMU_data, dt, time_all[i], True)

            # Zapis wyników estymacji
            CSV_data.save_proces_data(real_object,final_file)
            position_data.append(real_object[0])


        # Inicjalizacja wykresu
        ploting.aktualizuj_wykres(position_data, fig, ax, title, 1)
        print("Ukończono")

    ploting.show_plots()
    
    #subprocess.call("estimationVisualize.py", shell=True)
    

if __name__ == "__main__":
    main()