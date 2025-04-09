import os # Import os for creating csv file
import csv # Import csv for save to file
import pandas as pd
import matplotlib.pyplot as plt

# Wczytanie danych z pliku CSV
df = pd.read_csv('estimations/estimation3.csv')

# Wybór odpowiednich kolumn - zakładam, że timestamp jest w kolumnie 1, x w kolumnie 6, a y w kolumnie 7
# Jeśli kolumny są numerowane od 0, indeksy to 0, 5 i 6
timestamp = df.iloc[:, 0]
accx = df.iloc[:, 1]
accy = df.iloc[:, 2]
accz = df.iloc[:, 3]
speedx = df.iloc[:, 4]
speedy = df.iloc[:, 5]
speedz = df.iloc[:, 6]
positionx = df.iloc[:, 7]
positiony = df.iloc[:, 8]
positionz = df.iloc[:, 9]
orientationr = df.iloc[:, 10]
orientationp = df.iloc[:, 11]
orientationy = df.iloc[:, 12]

# Rysowanie przyśpieszeń
fig = plt.figure(1)

ax = fig.add_subplot(3,1,1)
plt.title('Estymata przyśpieszenia w osi X')
plt.xlabel('Czas [s]')
plt.ylabel('Przyśpieszenie [m/s/s]')
ax.plot(timestamp, accx, linestyle='-', color='red', markersize=2)
plt.grid(True)

ay = fig.add_subplot(3,1,2)
plt.title('Estymata przyśpieszenia w osi Y')
plt.xlabel('Czas [s]')
plt.ylabel('Przyśpieszenie [m/s/s]')
ay.plot(timestamp, accy, linestyle='-', color='blue', markersize=2)
plt.grid(True)

az = fig.add_subplot(3,1,3)
plt.title('Estymata przyśpieszenia w osi Z')
plt.xlabel('Czas [s]')
plt.ylabel('Przyśpieszenie [m/s/s]')
az.plot(timestamp, accz, linestyle='-', color='green', markersize=2)
plt.grid(True)
plt.tight_layout()


#Rysowanie prędkości
fig = plt.figure(2)

ax = fig.add_subplot(3,1,1)
plt.title('Estymata prędkości w osi X')
plt.xlabel('Czas [s]')
plt.ylabel('Prędkość [m/s]')
ax.plot(timestamp, speedx, linestyle='-', color='red', markersize=2)
plt.grid(True)

ay = fig.add_subplot(3,1,2)
plt.title('Estymata prędkości w osi Y')
plt.xlabel('Czas [s]')
plt.ylabel('Prędkość [m/s]')
ay.plot(timestamp, speedy, linestyle='-', color='blue', markersize=2)
plt.grid(True)

az = fig.add_subplot(3,1,3)
plt.title('Estymata prędkości w osi Z')
plt.xlabel('Czas [s]')
plt.ylabel('Prędkość [m/s]')
az.plot(timestamp, speedz, linestyle='-', color='green', markersize=2)
plt.grid(True)
plt.tight_layout()



#Rysowanie pozycji
fig = plt.figure(3)

ax = fig.add_subplot(3,1,1)
plt.title('Estymata pozycji w osi X')
plt.xlabel('Czas [s]')
plt.ylabel('Pozycja [m]')
ax.plot(timestamp, positionx, linestyle='-', color='red', markersize=2)
plt.grid(True)

ay = fig.add_subplot(3,1,2)
plt.title('Estymata pozycji w osi Y')
plt.xlabel('Czas [s]')
plt.ylabel('Pozycja [m]')
ay.plot(timestamp, positiony, linestyle='-', color='blue', markersize=2)
plt.grid(True)

az = fig.add_subplot(3,1,3)
plt.title('Estymata pozycji w osi Z')
plt.xlabel('Czas [s]')
plt.ylabel('Pozycja [m]')
az.plot(timestamp, positionz, linestyle='-', color='green', markersize=2)
plt.grid(True)
plt.tight_layout()


#Rysowanie pozycji
fig = plt.figure(4)

ax = fig.add_subplot(3,1,1)
plt.title('Estymata orientacji pitch')
plt.xlabel('Czas [s]')
plt.ylabel('Kąt [rad]')
ax.plot(timestamp, orientationp, linestyle='-', color='red', markersize=2)
plt.grid(True)

ay = fig.add_subplot(3,1,2)
plt.title('Estymata orientacji yaw')
plt.xlabel('Czas [s]')
plt.ylabel('Kąt [rad]')
ay.plot(timestamp, orientationy, linestyle='-', color='blue', markersize=2)
plt.grid(True)

az = fig.add_subplot(3,1,3)
plt.title('Estymata orientacji roll')
plt.xlabel('Czas [s]')
plt.ylabel('Kąt [rad]')
az.plot(timestamp, orientationr, linestyle='-', color='green', markersize=2)
plt.grid(True)
plt.tight_layout()
plt.show()