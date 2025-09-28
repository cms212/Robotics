from launch import LaunchDescription
from launch_ros.actions import Node
import os.path
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='cpp_pubsub',
            executable='talker',
            output='screen',
            prefix = 'xterm -e'
        ),
        Node(
            package='cpp_pubsub',
            executable='listener',
            output='screen',
            prefix = 'xterm -e'
        ),
    ])
