import serial

# Ustawienia portu szeregowego
ser = serial.Serial('/dev/ttyAMA0', 115200, timeout=1)

while True:
    if ser.in_waiting > 0:
        #data = ser.readline().decode('ASCII').rstrip()
        data = ser.read(ser.in_waiting)
        print(f'Otrzymano dane: {data}')
