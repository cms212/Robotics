// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from message_interfaces:msg/ArmPosition.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "message_interfaces/msg/detail/arm_position__functions.h"
#include "message_interfaces/msg/detail/arm_position__struct.hpp"
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

void ArmPosition_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) message_interfaces::msg::ArmPosition(_init);
}

void ArmPosition_fini_function(void * message_memory)
{
  auto typed_message = static_cast<message_interfaces::msg::ArmPosition *>(message_memory);
  typed_message->~ArmPosition();
}

size_t size_function__ArmPosition__arm_positions(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ArmPosition__arm_positions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__ArmPosition__arm_positions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__ArmPosition__arm_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint32_t *>(
    get_const_function__ArmPosition__arm_positions(untyped_member, index));
  auto & value = *reinterpret_cast<uint32_t *>(untyped_value);
  value = item;
}

void assign_function__ArmPosition__arm_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint32_t *>(
    get_function__ArmPosition__arm_positions(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint32_t *>(untyped_value);
  item = value;
}

void resize_function__ArmPosition__arm_positions(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint32_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ArmPosition_message_member_array[1] = {
  {
    "arm_positions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(message_interfaces::msg::ArmPosition, arm_positions),  // bytes offset in struct
    nullptr,  // default value
    size_function__ArmPosition__arm_positions,  // size() function pointer
    get_const_function__ArmPosition__arm_positions,  // get_const(index) function pointer
    get_function__ArmPosition__arm_positions,  // get(index) function pointer
    fetch_function__ArmPosition__arm_positions,  // fetch(index, &value) function pointer
    assign_function__ArmPosition__arm_positions,  // assign(index, value) function pointer
    resize_function__ArmPosition__arm_positions  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ArmPosition_message_members = {
  "message_interfaces::msg",  // message namespace
  "ArmPosition",  // message name
  1,  // number of fields
  sizeof(message_interfaces::msg::ArmPosition),
  false,  // has_any_key_member_
  ArmPosition_message_member_array,  // message members
  ArmPosition_init_function,  // function to initialize message memory (memory has to be allocated)
  ArmPosition_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ArmPosition_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ArmPosition_message_members,
  get_message_typesupport_handle_function,
  &message_interfaces__msg__ArmPosition__get_type_hash,
  &message_interfaces__msg__ArmPosition__get_type_description,
  &message_interfaces__msg__ArmPosition__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace message_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<message_interfaces::msg::ArmPosition>()
{
  return &::message_interfaces::msg::rosidl_typesupport_introspection_cpp::ArmPosition_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, message_interfaces, msg, ArmPosition)() {
  return &::message_interfaces::msg::rosidl_typesupport_introspection_cpp::ArmPosition_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
