from launch import LaunchDescription
from launch_ros.actions import Node
import os.path
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='robot',
            executable='tennis_ball_detector',
        ),
        Node(
            package='robot',
            executable='detection_info_subscriber',
        ),
    ])