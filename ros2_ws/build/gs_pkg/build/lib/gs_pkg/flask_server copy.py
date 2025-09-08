#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from custom_msgs.msg import ImuData, AccelData, GyroData
from flask import Flask, render_template

app = Flask(__name__)

received_data = ""

# ==============================================================================
# -- Node ---------------------------------------------------------------
# ==============================================================================
class ServerNode(Node): 
    def __init__(self):
        super().__init__("flask_server")  
        self.get_logger().info("Node init complete")

        self.subscription = self.create_subscription(
            ImuData,
            'imu_data',
            self.listener_callback,
            10)
        self.subscription  # zapobiega usunięciu subskrypcji przez garbage collector

    def listener_callback(self, msg):
        global received_data
        received_data = msg.timestamp
        self.get_logger().info('Odebrano: "%s"' % msg.timestamp)

    def timer_function(self):
        pass

@app.route('/')
def index():
    return render_template('index.html', data=received_data)        
    
# ==============================================================================
# -- Main ---------------------------------------------------------------
# ==============================================================================
def main(args=None):
    app.run(debug=True) 
    rclpy.init(args=args)
    node = ServerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
