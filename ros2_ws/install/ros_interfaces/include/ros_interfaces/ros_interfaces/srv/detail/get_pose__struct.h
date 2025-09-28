// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros_interfaces:srv/GetPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros_interfaces/srv/get_pose.h"


#ifndef ROS_INTERFACES__SRV__DETAIL__GET_POSE__STRUCT_H_
#define ROS_INTERFACES__SRV__DETAIL__GET_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetPose in the package ros_interfaces.
typedef struct ros_interfaces__srv__GetPose_Request
{
  uint8_t structure_needs_at_least_one_member;
} ros_interfaces__srv__GetPose_Request;

// Struct for a sequence of ros_interfaces__srv__GetPose_Request.
typedef struct ros_interfaces__srv__GetPose_Request__Sequence
{
  ros_interfaces__srv__GetPose_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_interfaces__srv__GetPose_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in srv/GetPose in the package ros_interfaces.
typedef struct ros_interfaces__srv__GetPose_Response
{
  geometry_msgs__msg__Pose pose;
} ros_interfaces__srv__GetPose_Response;

// Struct for a sequence of ros_interfaces__srv__GetPose_Response.
typedef struct ros_interfaces__srv__GetPose_Response__Sequence
{
  ros_interfaces__srv__GetPose_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_interfaces__srv__GetPose_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  ros_interfaces__srv__GetPose_Event__request__MAX_SIZE = 1
};
// response
enum
{
  ros_interfaces__srv__GetPose_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetPose in the package ros_interfaces.
typedef struct ros_interfaces__srv__GetPose_Event
{
  service_msgs__msg__ServiceEventInfo info;
  ros_interfaces__srv__GetPose_Request__Sequence request;
  ros_interfaces__srv__GetPose_Response__Sequence response;
} ros_interfaces__srv__GetPose_Event;

// Struct for a sequence of ros_interfaces__srv__GetPose_Event.
typedef struct ros_interfaces__srv__GetPose_Event__Sequence
{
  ros_interfaces__srv__GetPose_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_interfaces__srv__GetPose_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS_INTERFACES__SRV__DETAIL__GET_POSE__STRUCT_H_
