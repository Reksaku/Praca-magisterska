#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from custom_msgs.msg import ImuData, AccelData, GyroData, EstimatorData, PossitionData
from flask import Flask, render_template, jsonify, request
import threading
import os
from datetime import datetime, timedelta

# Uzyskanie ścieżki do katalogu z szablonami
template_dir = os.path.join(os.path.expanduser('~'), 'ros2_ws/src/flask_pkg/flask_pkg/templates')

# Inicjalizacja aplikacji Flask z niestandardowym katalogiem szablonów
app = Flask(__name__, template_folder=template_dir)
   
data_buffer = []   

# Klasa subskrybenta ROS 2
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

    def listener_callback(self, msg):
        self.counter += 1
        if self.counter % 10 != 0:  # tylko co 10. wiadomość (czyli 10Hz)
            return  

  
        timestamp = datetime.utcnow()
        data_buffer.append((timestamp, msg.possition.x, msg.possition.y, msg.possition.z))
        cutoff = timestamp - timedelta(seconds=10)
        while data_buffer and data_buffer[0][0] < cutoff:
            data_buffer.pop(0)
        #self.get_logger().info('Odebrano: "%s"' % msg.timestamp)

# Inicjalizacja rclpy i uruchomienie subskrybenta w osobnym wątku
def ros2_thread():
    rclpy.init()
    minimal_subscriber = ServerNode()
    rclpy.spin(minimal_subscriber)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


@app.route('/')
def index():
    return render_template('index.html')

@app.route('/data')
def get_data():
    now = datetime.utcnow()
    recent = [(t, temp, hum, press) for (t, temp, hum, press) in data_buffer]
    return jsonify([
        {
            'time': t.strftime('%H:%M:%S'),
            'temperature': temp,
            'humidity': hum,
            'pressure': press
        } for (t, temp, hum, press) in recent
    ])



def main():
    ros_thread = threading.Thread(target=ros2_thread)
    ros_thread.start()
    app.run(debug=True, host='0.0.0.0')

if __name__ == '__main__':
    main()