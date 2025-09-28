cmake_minimum_required(VERSION 3.8)
project(robot)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(nav2_msgs REQUIRED)
find_package(nav2_behavior_tree REQUIRED)
find_package(behaviortree_cpp REQUIRED)
find_package(behaviortree_ros2 REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(ros_interfaces REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
# find_package(slam_toolbox REQUIRED)  # Commented out due to yaml-cpp dependency issue
find_package(sensor_msgs REQUIRED)
find_package(dynamixel_sdk REQUIRED)
find_package(dynamixel_sdk_custom_interfaces REQUIRED)
find_package(message_interfaces REQUIRED)

add_executable(executive src/executive.cpp)
ament_target_dependencies(executive rclcpp behaviortree_cpp behaviortree_ros2 nav2_msgs  nav_msgs ros_interfaces tf2 tf2_ros tf2_geometry_msgs)  # removed slam_toolbox

add_executable(pose_srv src/get_pose_server.cpp)
ament_target_dependencies(pose_srv rclcpp nav2_msgs  nav_msgs ros_interfaces tf2 tf2_ros)

add_executable(pose_publisher src/pose_publisher.cpp)
ament_target_dependencies(pose_publisher rclcpp nav2_msgs nav_msgs tf2 tf2_ros tf2_geometry_msgs)

add_executable(image_subscriber src/image_subscriber.cpp)
ament_target_dependencies(image_subscriber rclcpp sensor_msgs tf2 tf2_ros)

add_executable(arm_position_publisher src/arm_position_publisher.cpp)
ament_target_dependencies(arm_position_publisher  dynamixel_sdk dynamixel_sdk_custom_interfaces message_interfaces rclcpp tf2 tf2_ros)

add_executable(arm_position_subscriber src/arm_position_subscriber.cpp)
ament_target_dependencies(arm_position_subscriber  dynamixel_sdk dynamixel_sdk_custom_interfaces message_interfaces rclcpp tf2 tf2_ros)

install(TARGETS
  executive 
  pose_srv
  pose_publisher
  image_subscriber
  arm_position_publisher
  arm_position_subscriber
  DESTINATION lib/${PROJECT_NAME})

install(
  DIRECTORY
    config/
  DESTINATION share/${PROJECT_NAME}/config
)
install(
  DIRECTORY
    launch/
  DESTINATION share/${PROJECT_NAME}/launch
)
install(
  DIRECTORY
    worlds/
  DESTINATION share/${PROJECT_NAME}/worlds
)
install(
  DIRECTORY
    models/
  DESTINATION share/${PROJECT_NAME}/models
)

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
