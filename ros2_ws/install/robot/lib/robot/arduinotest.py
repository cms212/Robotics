#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import serial
g_ser = None
on = False
a_node = None

class ArduinoNode(Node):
    def __init__(self):
        super().__init__('arduino_publisher')
        global g_ser
        g_ser=serial.Serial('/dev/ttyACM0', 9600, timeout=1)
        timer_period = 2  # seconds
        self.timer = self.create_timer(timer_period, self.arduino_command)
        global a_node
        a_node = self

    def arduino_command(self):
        global g_ser
        global on
        if on:
            g_ser.write("0\n".encode())
            on = False
            a_node.get_logger().info('LED OFF command sent to Arduino')
        else:
            g_ser.write("1\n".encode())
            on = True
            a_node.get_logger().info('LED ON command sent to Arduino')


def main(args=None):
    global g_ser
    rclpy.init(args=args)
    a_node = ArduinoNode()
    
    rclpy.spin(a_node)

    a_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()