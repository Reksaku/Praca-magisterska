import os # Import os for creating csv file
import csv # Import csv for save to file
import pandas as pd
import matplotlib.pyplot as plt

# Wczytanie danych z pliku CSV
df = pd.read_csv('imu_data_cold_13.csv')

# Wybór odpowiednich kolumn - zakładam, że timestamp jest w kolumnie 1, x w kolumnie 6, a y w kolumnie 7
# Jeśli kolumny są numerowane od 0, indeksy to 0, 5 i 6
timestamp = (df.iloc[:, 0]-df.iloc[0, 0])/1000000
accx = df.iloc[:, 1]
accy = df.iloc[:, 2]
accz = df.iloc[:, 3]*-1
gyrox = df.iloc[:, 4]
gyroy = df.iloc[:, 5]
gyroz = df.iloc[:, 6]
magx = df.iloc[:, 7]
magy = df.iloc[:, 8]
magz = df.iloc[:, 9]
bar = df.iloc[:, 10]
temp = df.iloc[:, 11]


# Rysowanie 
fig = plt.figure(1)

ax = fig.add_subplot(3,1,1)
plt.title('Odczyty przyśpieszenia w osi X')
plt.xlabel('Czas [s]')
plt.ylabel('Przyśpieszenie [m/s/s]')
ax.plot(timestamp, accx, linestyle='-', color='red', markersize=2)
ax.plot(timestamp, (temp-temp[0])*0.0004, linestyle='-', color='black', markersize=2)
plt.grid(True)

ay = fig.add_subplot(3,1,2)
plt.title('Odczyty przyśpieszenia w osi Y')
plt.xlabel('Czas [s]')
plt.ylabel('Przyśpieszenie [m/s/s]')
ay.plot(timestamp, accy, linestyle='-', color='blue', markersize=2)
ay.plot(timestamp, -(temp-temp[0])*0.00035, linestyle='-', color='black', markersize=2)
plt.grid(True)

az = fig.add_subplot(3,1,3)
plt.title('Odczyty przyśpieszenia w osi Z')
plt.xlabel('Czas [s]')
plt.ylabel('Przyśpieszenie [m/s/s]')
# az.set_ylim(-16, 0)
#az.plot(timestamp, temp, linestyle='-', color='black', markersize=2)
az.plot(timestamp, accz, linestyle='-', color='green', markersize=2)
plt.grid(True)
plt.tight_layout()


fig = plt.figure(2)

ax = fig.add_subplot(3,1,1)
plt.title('Odczyty obrotu w osi X')
plt.xlabel('Czas [s]')
plt.ylabel('Przyśpieszenie [m/s/s]')
ax.plot(timestamp, gyrox, linestyle='-', color='red', markersize=2)
plt.grid(True)

ay = fig.add_subplot(3,1,2)
plt.title('Odczyty obrotu w osi Y')
plt.xlabel('Czas [s]')
plt.ylabel('Przyśpieszenie [m/s/s]')
ay.plot(timestamp, gyroy, linestyle='-', color='blue', markersize=2)
plt.grid(True)

az = fig.add_subplot(3,1,3)
plt.title('Odczyty obrotu w osi Z')
plt.xlabel('Czas [s]')
plt.ylabel('Przyśpieszenie [m/s/s]')
az.plot(timestamp, gyroz, linestyle='-', color='green', markersize=2)
plt.grid(True)
plt.tight_layout()



fig = plt.figure(3)

ax = fig.add_subplot(4,1,1)
plt.title('Odczyty magnetometru w osi X')
plt.xlabel('Czas [s]')
plt.ylabel('Siła [mG]')
ax.plot(timestamp, magx, linestyle='-', color='red', markersize=2)
plt.grid(True)

ay = fig.add_subplot(4,1,2)
plt.title('Odczyty magnetometru w osi Y')
plt.xlabel('Czas [s]')
plt.ylabel('Siła [mG]')
ay.plot(timestamp, magy, linestyle='-', color='blue', markersize=2)
plt.grid(True)

az = fig.add_subplot(4,1,3)
plt.title('Odczyty magnetometru w osi Z')
plt.xlabel('Czas [s]')
plt.ylabel('Siła [mG]')
az.plot(timestamp, magz, linestyle='-', color='green', markersize=2)
plt.grid(True)
plt.tight_layout()

az = fig.add_subplot(4,1,4)
plt.title('Odczyty termometru')
plt.xlabel('Czas [s]')
plt.ylabel('Temperatura [deg]')
#az.plot(timestamp, bar, linestyle='-', color='black', markersize=2)
az.plot(timestamp, temp, linestyle='-', color='black', markersize=2)
plt.grid(True)
plt.tight_layout()

plt.show()