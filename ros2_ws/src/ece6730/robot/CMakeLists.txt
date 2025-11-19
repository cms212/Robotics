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
find_package(sensor_msgs REQUIRED)
find_package(dynamixel_sdk REQUIRED)
find_package(dynamixel_sdk_custom_interfaces REQUIRED)
find_package(message_interfaces REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(PkgConfig REQUIRED)

set(ONNXRUNTIME_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/onnxruntime-linux-x64-1.16.3)
set(ONNXRUNTIME_INCLUDE_DIRS ${ONNXRUNTIME_ROOT_PATH}/include)
set(ONNXRUNTIME_LIB_DIRS ${ONNXRUNTIME_ROOT_PATH}/lib)
find_library(ONNXRUNTIME_LIB onnxruntime HINTS ${ONNXRUNTIME_LIB_DIRS})

set(OPENCV_LOCAL_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/opencv-local)
set(OPENCV_LOCAL_INCLUDE_DIRS ${OPENCV_LOCAL_ROOT_PATH}/include)
set(OPENCV_LOCAL_LIB_DIRS ${OPENCV_LOCAL_ROOT_PATH}/lib)
find_library(OPENCV_CORE_LIB opencv_core HINTS ${OPENCV_LOCAL_LIB_DIRS})
find_library(OPENCV_IMGPROC_LIB opencv_imgproc HINTS ${OPENCV_LOCAL_LIB_DIRS})
find_library(OPENCV_IMGCODECS_LIB opencv_imgcodecs HINTS ${OPENCV_LOCAL_LIB_DIRS})
find_library(OPENCV_HIGHGUI_LIB opencv_highgui HINTS ${OPENCV_LOCAL_LIB_DIRS})
find_library(OPENCV_VIDEOIO_LIB opencv_videoio HINTS ${OPENCV_LOCAL_LIB_DIRS})
find_library(OPENCV_DNN_LIB opencv_dnn HINTS ${OPENCV_LOCAL_LIB_DIRS})
set(OPENCV_LOCAL_LIBS ${OPENCV_CORE_LIB} ${OPENCV_IMGPROC_LIB} ${OPENCV_IMGCODECS_LIB} ${OPENCV_HIGHGUI_LIB} ${OPENCV_VIDEOIO_LIB} ${OPENCV_DNN_LIB})


#add_executable(executive src/executive.cpp)
#ament_target_dependencies(executive rclcpp behaviortree_cpp behaviortree_ros2 nav2_msgs  nav_msgs ros_interfaces tf2 tf2_ros tf2_geometry_msgs)  # removed slam_toolbox

#add_executable(pose_srv src/get_pose_server.cpp)
#ament_target_dependencies(pose_srv rclcpp nav2_msgs  nav_msgs ros_interfaces tf2 tf2_ros)

#add_executable(pose_publisher src/pose_publisher.cpp)
#ament_target_dependencies(pose_publisher rclcpp nav2_msgs nav_msgs tf2 tf2_ros tf2_geometry_msgs)

#add_executable(image_subscriber src/image_subscriber.cpp)
#ament_target_dependencies(image_subscriber rclcpp sensor_msgs tf2 tf2_ros)

#add_executable(arm_position_publisher src/arm_position_publisher.cpp)
#ament_target_dependencies(arm_position_publisher  dynamixel_sdk dynamixel_sdk_custom_interfaces message_interfaces rclcpp tf2 tf2_ros)

#add_executable(arm_position_subscriber src/arm_position_subscriber.cpp)
#ament_target_dependencies(arm_position_subscriber  dynamixel_sdk dynamixel_sdk_custom_interfaces message_interfaces rclcpp tf2 tf2_ros)

add_executable(joint_states_publisher src/joint_states_publisher.cpp)
ament_target_dependencies(joint_states_publisher  dynamixel_sdk dynamixel_sdk_custom_interfaces sensor_msgs rclcpp tf2 tf2_ros)

add_executable(tennis_ball_detector src/tennis_ball_detection_publisher.cpp)
ament_target_dependencies(tennis_ball_detector rclcpp std_msgs sensor_msgs message_interfaces cv_bridge)
target_include_directories(tennis_ball_detector PRIVATE ${OPENCV_LOCAL_INCLUDE_DIRS} ${ONNXRUNTIME_INCLUDE_DIRS} src/)
target_link_libraries(tennis_ball_detector ${OPENCV_LOCAL_LIBS} ${ONNXRUNTIME_LIB})
set_target_properties(tennis_ball_detector PROPERTIES
    BUILD_RPATH "${ONNXRUNTIME_LIB_DIRS}"
    INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}/onnxruntime/lib"
)

add_executable(tennis_ball_to_camera_orientation src/tennisball_to_camera_orientation.cpp)
ament_target_dependencies(tennis_ball_to_camera_orientation rclcpp message_interfaces)

add_executable(tf_publisher src/tf_publisher.cpp)
ament_target_dependencies(tf_publisher rclcpp message_interfaces tf2 tf2_ros geometry_msgs)

add_executable(movement_to_tennisball_publisher src/movement_to_tennisball_publisher.cpp)
ament_target_dependencies(movement_to_tennisball_publisher rclcpp message_interfaces)

add_executable(center_to_tennisball src/center_to_tennisball.cpp)
ament_target_dependencies(center_to_tennisball rclcpp message_interfaces ros_interfaces)

add_executable(behavior_tree src/behavior_tree.cpp)
ament_target_dependencies(behavior_tree rclcpp ros_interfaces behaviortree_cpp behaviortree_ros2)

install(TARGETS
  #executive 
  #pose_srv
  #pose_publisher
  #image_subscriber
  #arm_position_publisher
  #arm_position_subscriber
  tennis_ball_detector
  tennis_ball_to_camera_orientation
  joint_states_publisher
  tf_publisher
  movement_to_tennisball_publisher
  center_to_tennisball
  behavior_tree
  DESTINATION lib/${PROJECT_NAME})

install(PROGRAMS
  src/arduinocommands.py
  DESTINATION lib/${PROJECT_NAME}
)

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
install(
  DIRECTORY
    urdf/
  DESTINATION share/${PROJECT_NAME}/urdf
)
install(
  DIRECTORY
    onnxruntime-linux-x64-1.16.3/lib/
  DESTINATION lib/${PROJECT_NAME}/onnxruntime/lib
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
