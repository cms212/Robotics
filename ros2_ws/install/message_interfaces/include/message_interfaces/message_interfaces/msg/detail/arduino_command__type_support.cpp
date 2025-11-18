// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from message_interfaces:msg/ArduinoCommand.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "message_interfaces/msg/detail/arduino_command__functions.h"
#include "message_interfaces/msg/detail/arduino_command__struct.hpp"
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

void ArduinoCommand_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) message_interfaces::msg::ArduinoCommand(_init);
}

void ArduinoCommand_fini_function(void * message_memory)
{
  auto typed_message = static_cast<message_interfaces::msg::ArduinoCommand *>(message_memory);
  typed_message->~ArduinoCommand();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ArduinoCommand_message_member_array[1] = {
  {
    "arduino_command",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(message_interfaces::msg::ArduinoCommand, arduino_command),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ArduinoCommand_message_members = {
  "message_interfaces::msg",  // message namespace
  "ArduinoCommand",  // message name
  1,  // number of fields
  sizeof(message_interfaces::msg::ArduinoCommand),
  false,  // has_any_key_member_
  ArduinoCommand_message_member_array,  // message members
  ArduinoCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  ArduinoCommand_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ArduinoCommand_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ArduinoCommand_message_members,
  get_message_typesupport_handle_function,
  &message_interfaces__msg__ArduinoCommand__get_type_hash,
  &message_interfaces__msg__ArduinoCommand__get_type_description,
  &message_interfaces__msg__ArduinoCommand__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace message_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<message_interfaces::msg::ArduinoCommand>()
{
  return &::message_interfaces::msg::rosidl_typesupport_introspection_cpp::ArduinoCommand_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, message_interfaces, msg, ArduinoCommand)() {
  return &::message_interfaces::msg::rosidl_typesupport_introspection_cpp::ArduinoCommand_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
