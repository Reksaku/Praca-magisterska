#!/usr/bin/env python3
import os
import csv
from datetime import datetime
import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data

# UŻYJ tego typu, który naprawdę jest publikowany na /imu_data!
from custom_msgs.msg import ImuData  # zamiast EstimatorData

class CSVWriter:
    def __init__(self, filename, headers=None, batch_size=20,
                 path='/home/dron/Praca-magisterska/log_data/'):
        # upewnij się, że ścieżka istnieje
        self.path = os.path.expanduser(path)
        os.makedirs(self.path, exist_ok=True)

        self.headers = headers or []
        self.batch_size = batch_size
        self.buffer = []

        # dodaj rozszerzenie .csv
        if not filename.endswith('.csv'):
            filename += '.csv'
        self.filename = os.path.join(self.path, filename)

        print(f"Filename path: {self.filename}")
        self._file_initialized = os.path.exists(self.filename)

    def add_row(self, row):
        self.buffer.append(row)
        if len(self.buffer) >= self.batch_size:
            self.flush()

    def flush(self):
        mode = 'a' if self._file_initialized else 'w'
        with open(self.filename, mode, newline='', encoding='utf-8') as csvfile:
            writer = csv.writer(csvfile)
            if not self._file_initialized and self.headers:
                writer.writerow(self.headers)
                self._file_initialized = True
            writer.writerows(self.buffer)
        self.buffer.clear()

    def flush_remaining(self):
        if self.buffer:
            self.flush()

class SavingNode(Node):
    def __init__(self):
        super().__init__("data_collector")
        self.subscription = self.create_subscription(
            ImuData,                # <— UPEWNIJ SIĘ, ŻE TO JEST TEN SAM TYP CO U PUBLISHERA
            'imu_data',
            self.listener_callback,
            qos_profile_sensor_data
        )
        headers = [
            'Timestamp',
            'Accel X', 'Accel Y', 'Accel Z',
            'Gyro X',  'Gyro Y',  'Gyro Z'
        ]
        self.writer = CSVWriter(self.time_now(), headers)
        self.get_logger().info("Init complete")

    def listener_callback(self, msg: ImuData):
        # dopasuj pola do faktycznej definicji wiadomości
        self.writer.add_row([
            msg.timestamp,
            msg.accel.x, msg.accel.y, msg.accel.z,
            msg.gyro.x,  msg.gyro.y,  msg.gyro.z
        ])

    def time_now(self):
        now = datetime.now()
        return now.strftime("dane-%d_%m_%y-%H_%M_%S")

def main(args=None):
    rclpy.init(args=args)
    node = SavingNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        # gwarantujemy zapis reszty danych
        node.writer.flush_remaining()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()
