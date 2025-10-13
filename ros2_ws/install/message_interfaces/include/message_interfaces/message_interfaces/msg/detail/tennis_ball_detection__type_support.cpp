// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from message_interfaces:msg/TennisBallDetection.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "message_interfaces/msg/detail/tennis_ball_detection__functions.h"
#include "message_interfaces/msg/detail/tennis_ball_detection__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace message_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TennisBallDetection_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) message_interfaces::msg::TennisBallDetection(_init);
}

void TennisBallDetection_fini_function(void * message_memory)
{
  auto typed_message = static_cast<message_interfaces::msg::TennisBallDetection *>(message_memory);
  typed_message->~TennisBallDetection();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TennisBallDetection_message_member_array[4] = {
  {
    "left_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(message_interfaces::msg::TennisBallDetection, left_x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "right_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(message_interfaces::msg::TennisBallDetection, right_x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "top_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(message_interfaces::msg::TennisBallDetection, top_y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "bottom_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(message_interfaces::msg::TennisBallDetection, bottom_y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TennisBallDetection_message_members = {
  "message_interfaces::msg",  // message namespace
  "TennisBallDetection",  // message name
  4,  // number of fields
  sizeof(message_interfaces::msg::TennisBallDetection),
  false,  // has_any_key_member_
  TennisBallDetection_message_member_array,  // message members
  TennisBallDetection_init_function,  // function to initialize message memory (memory has to be allocated)
  TennisBallDetection_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TennisBallDetection_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TennisBallDetection_message_members,
  get_message_typesupport_handle_function,
  &message_interfaces__msg__TennisBallDetection__get_type_hash,
  &message_interfaces__msg__TennisBallDetection__get_type_description,
  &message_interfaces__msg__TennisBallDetection__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace message_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<message_interfaces::msg::TennisBallDetection>()
{
  return &::message_interfaces::msg::rosidl_typesupport_introspection_cpp::TennisBallDetection_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, message_interfaces, msg, TennisBallDetection)() {
  return &::message_interfaces::msg::rosidl_typesupport_introspection_cpp::TennisBallDetection_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
