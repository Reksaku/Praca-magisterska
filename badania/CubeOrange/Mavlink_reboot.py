from pymavlink import mavutil

# Create the connection
master = mavutil.mavlink_connection('COM5', baud=57600)
# Wait a heartbeat before sending commands
master.wait_heartbeat()

master.reboot_autopilot()