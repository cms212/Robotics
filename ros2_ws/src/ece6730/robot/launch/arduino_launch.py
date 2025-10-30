from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='robot',
            executable='arduinotest.py',
            name='arduino_test_node',
            output='screen',
            parameters=[],
        ),
    ])