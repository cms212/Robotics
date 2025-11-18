#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import serial
from message_interfaces.msg import ArduinoCommand
from rclpy.logging import LoggingSeverity

g_ser = None
on = False
a_node = None


class ArduinoNode(Node):
    def __init__(self):
        super().__init__('arduino_publisher')
        global g_ser
        global a_node
        a_node = self
        # ensure INFO-level logs are emitted
        try:
            self.get_logger().set_level(LoggingSeverity.INFO)
        except Exception:
            pass
        try:
            g_ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
            self.get_logger().info('Serial port /dev/ttyACM0 opened successfully.')
        except serial.SerialException as e:
            self.get_logger().error(f'Error opening serial port: {e}')
            g_ser = None

        arduino_commandsubscription = self.create_subscription(
            ArduinoCommand,
            'arduino_command',
            self.arduino_command_callback,
            10)

    def arduino_command_callback(self, msg):
        global g_ser
        global current_command
        g_ser.write(msg.arduino_command.encode())
        self.get_logger().info(f"Sent command: {msg.arduino_command.strip()}")


def main(args=None):
    global g_ser
    rclpy.init(args=args)
    a_node = ArduinoNode()
    
    rclpy.spin(a_node)

    a_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()