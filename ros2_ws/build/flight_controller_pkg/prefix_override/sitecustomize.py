import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/dron/Praca-magisterska/ros2_ws/install/flight_controller_pkg'
