#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from custom_msgs.msg import ImuData, AccelData, GyroData, EstimatorData, PossitionData
from example_interfaces.msg import String
from flask import Flask, render_template, jsonify, request
import threading
import os
from datetime import datetime, timedelta

# Uzyskanie ścieżki do katalogu z szablonami
template_dir = os.path.join(os.path.expanduser('~'), 'ros2_ws/src/flask_pkg/flask_pkg/templates')

# Inicjalizacja aplikacji Flask z niestandardowym katalogiem szablonów
app = Flask(__name__, template_folder=template_dir)

data_buffer = [] 

# Inicjalizacja rclpy
rclpy.init()

# Tworzenie węzła ROS 2
class ServerNode(Node):
    def __init__(self):
        super().__init__('flask_server')
        self.subscription = self.create_subscription(
            EstimatorData,
            'estimation_data',
            self.listener_callback,
            100)
        self.subscription  # zapobiega usunięciu subskrypcji przez garbage collector
        self.counter = 0  # licznik do próbkowania
        self.publisher_ = self.create_publisher(String, 'flask_commands', 10)


    def listener_callback(self, msg):
        self.counter += 1
        if self.counter % 4 != 0:  # tylko co 10. wiadomość (czyli 10Hz)
            return  
        timestamp = datetime.utcnow()
        data_buffer.append(
            (timestamp, msg.possition.x, msg.possition.y, 
             msg.possition.z, msg.speed.x, 
             msg.speed.y, msg.speed.z, 
             msg.accel.x, msg.accel.y, msg.accel.z,
             msg.rotation.x, msg.rotation.y, msg.rotation.z
             ))
        cutoff = timestamp - timedelta(seconds=5)
        while data_buffer and data_buffer[0][0] < cutoff:
            data_buffer.pop(0)
        #self.get_logger().info('Odebrano: "%s"' % msg.timestamp)


    def publish_message(self, command):
        msg = String()
        msg.data = command
        self.publisher_.publish(msg)
        self.get_logger().info(f'Opublikowano: "{msg}"')




ros2_node = ServerNode()



# Uruchomienie węzła ROS 2 w osobnym wątku
def ros2_spin():
    rclpy.spin(ros2_node)

ros2_thread = threading.Thread(target=ros2_spin, daemon=True)
ros2_thread.start()


@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        print('POST')
        if request.form.get('reset') == 'Reset':
            ros2_node.publish_message('reset')
        if request.form.get('calibrate') == 'Re-calibrate':
            ros2_node.publish_message('calibrate')
    return render_template('index.html')


@app.route('/data')
def get_data():
    now = datetime.utcnow()
    recent = [(t, posx, posy, posz, spdx, spdy, spdz, accx, accy, accz, rotx, roty, rotz) 
              for (t, posx, posy, posz, spdx, spdy, spdz, accx, accy, accz, rotx, roty, rotz) in data_buffer]
    return jsonify([
        {
            'time': t.strftime('%H:%M:%S'),
            'position_x': posx,
            'position_y': posy,
            'position_z': posz,
            'speed_x': spdx,
            'speed_y': spdy,
            'speed_z': spdz,
            'accel_x': accx,
            'accel_y': accy,
            'accel_z': accz,
            'rotation_x': rotx,
            'rotation_y': roty,
            'rotation_z': rotz
        } for (t, posx, posy, posz, spdx, spdy, spdz, accx, accy, accz, rotx, roty, rotz) in recent
    ])

def main():
    app.run(debug=True,  host='0.0.0.0')

if __name__ == '__main__':
    main()
