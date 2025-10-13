from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import FileContent, LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    # Use sim time argument
    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    # Get URDF file content
    urdf = FileContent(
        PathJoinSubstitution([FindPackageShare('urdf_tutorial_cpp'), 'urdf', 'robot.urdf.xml']))

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use simulation (Gazebo) clock if true'),
        
        # Robot State Publisher - publishes the robot's state to tf2
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
        
        # Your custom Joint States Publisher - publishes joint states
        Node(
            package='urdf_tutorial_cpp',
            executable='joint_states_publisher',
            name='joint_states_publisher',
            output='screen',
            parameters=[{'use_sim_time': use_sim_time}]
        ),
        
        # RViz2 - visualization tool
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            output='screen',
            parameters=[{'use_sim_time': use_sim_time}],
            arguments=['-d', PathJoinSubstitution([FindPackageShare('urdf_tutorial_cpp'), 'config', 'urdf.rviz'])]
        ),
    ])
