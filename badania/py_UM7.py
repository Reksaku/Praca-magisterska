import um7

# Inicjalizacja połączenia
u = um7.UM7('um7', '/dev/ttyS0', ['health', 'pitch', 'roll', 'yaw'])

# Sprawdzenie wersji oprogramowania
print('Wersja firmware:', u.get_fw_revision())

# Zerowanie żyroskopów
u.zero_gyros()

# Odczyt wartości pitch, roll i yaw
u.catchallsamples(['pitch', 'roll', 'yaw'], 0.5)
print(f"Pitch: {u.state['pitch']}, Roll: {u.state['roll']}, Yaw: {u.state['yaw']}")
