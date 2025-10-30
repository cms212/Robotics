// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from message_interfaces:msg/TennisBallDetection.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "message_interfaces/msg/detail/tennis_ball_detection__rosidl_typesupport_introspection_c.h"
#include "message_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "message_interfaces/msg/detail/tennis_ball_detection__functions.h"
#include "message_interfaces/msg/detail/tennis_ball_detection__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void message_interfaces__msg__TennisBallDetection__rosidl_typesupport_introspection_c__TennisBallDetection_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  message_interfaces__msg__TennisBallDetection__init(message_memory);
}

void message_interfaces__msg__TennisBallDetection__rosidl_typesupport_introspection_c__TennisBallDetection_fini_function(void * message_memory)
{
  message_interfaces__msg__TennisBallDetection__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember message_interfaces__msg__TennisBallDetection__rosidl_typesupport_introspection_c__TennisBallDetection_message_member_array[4] = {
  {
    "left_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(message_interfaces__msg__TennisBallDetection, left_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "right_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(message_interfaces__msg__TennisBallDetection, right_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "top_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(message_interfaces__msg__TennisBallDetection, top_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bottom_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(message_interfaces__msg__TennisBallDetection, bottom_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers message_interfaces__msg__TennisBallDetection__rosidl_typesupport_introspection_c__TennisBallDetection_message_members = {
  "message_interfaces__msg",  // message namespace
  "TennisBallDetection",  // message name
  4,  // number of fields
  sizeof(message_interfaces__msg__TennisBallDetection),
  false,  // has_any_key_member_
  message_interfaces__msg__TennisBallDetection__rosidl_typesupport_introspection_c__TennisBallDetection_message_member_array,  // message members
  message_interfaces__msg__TennisBallDetection__rosidl_typesupport_introspection_c__TennisBallDetection_init_function,  // function to initialize message memory (memory has to be allocated)
  message_interfaces__msg__TennisBallDetection__rosidl_typesupport_introspection_c__TennisBallDetection_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t message_interfaces__msg__TennisBallDetection__rosidl_typesupport_introspection_c__TennisBallDetection_message_type_support_handle = {
  0,
  &message_interfaces__msg__TennisBallDetection__rosidl_typesupport_introspection_c__TennisBallDetection_message_members,
  get_message_typesupport_handle_function,
  &message_interfaces__msg__TennisBallDetection__get_type_hash,
  &message_interfaces__msg__TennisBallDetection__get_type_description,
  &message_interfaces__msg__TennisBallDetection__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_message_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, message_interfaces, msg, TennisBallDetection)() {
  if (!message_interfaces__msg__TennisBallDetection__rosidl_typesupport_introspection_c__TennisBallDetection_message_type_support_handle.typesupport_identifier) {
    message_interfaces__msg__TennisBallDetection__rosidl_typesupport_introspection_c__TennisBallDetection_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &message_interfaces__msg__TennisBallDetection__rosidl_typesupport_introspection_c__TennisBallDetection_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
