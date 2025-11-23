from launch import LaunchDescription
from launch_ros.actions import Node
import os.path
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import FileContent, LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    urdf = FileContent(
        PathJoinSubstitution([FindPackageShare('robot'), 'urdf', 'robot.urdf.xml']))

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use simulation (Gazebo) clock if true'),
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{
                'robot_description': urdf,
                'use_sim_time': use_sim_time
            }]
        ),
        Node(
            package='robot',
            executable='tennis_ball_detector',
        ),
        Node(
            package='robot',
            executable='tennis_ball_to_camera_orientation',
        ),
        Node(
            package='robot',
            executable='center_to_tennisball',
            name='center_to_tennisball',
            output='screen',
        ),
        Node(
            package='robot',
            executable='forward_to_tennisball',
            name='forward_to_tennisball',
            output='screen',
        ),
        Node(
            package='robot',
            executable='behavior_tree',
            name='behavior_tree',
            output='screen',
        ),
        #Node(
            #package='robot',
            #executable='movement_to_tennisball_publisher',
            #),
        Node(
            package='robot',
            executable='tf_publisher',
        ),
        Node(
            package='robot',
            executable='joint_states_publisher',
            name='joint_states_publisher',
            output='screen',
            parameters=[{'use_sim_time': use_sim_time}]
        ),
         Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            output='screen',
            parameters=[{'use_sim_time': use_sim_time}],
            arguments=['-d', PathJoinSubstitution([FindPackageShare('urdf_tutorial_cpp'), 'config', 'urdf.rviz'])]
        ),
        Node(
            package='robot',
            executable='arduinocommands.py',
            name='arduino_publisher',
            output='screen',
            parameters=[],
        ),
    ])