#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import serial
g_ser = None
on = False
a_node = None
commands = ["1f\n", "1b\n", "1s\n", "2f\n", "2b\n", "2s\n"]
current_command = 0

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
        global current_command
        g_ser.write(commands[current_command].encode())
        current_command = (current_command + 1) % len(commands)
        print(f"Sent command: {commands[current_command-1].strip()}")


def main(args=None):
    global g_ser
    rclpy.init(args=args)
    a_node = ArduinoNode()
    
    rclpy.spin(a_node)

    a_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()