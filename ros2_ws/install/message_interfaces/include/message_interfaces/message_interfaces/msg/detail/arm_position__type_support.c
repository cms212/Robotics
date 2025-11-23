// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from message_interfaces:msg/ArmPosition.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "message_interfaces/msg/detail/arm_position__rosidl_typesupport_introspection_c.h"
#include "message_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "message_interfaces/msg/detail/arm_position__functions.h"
#include "message_interfaces/msg/detail/arm_position__struct.h"


// Include directives for member types
// Member `arm_positions`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__ArmPosition_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  message_interfaces__msg__ArmPosition__init(message_memory);
}

void message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__ArmPosition_fini_function(void * message_memory)
{
  message_interfaces__msg__ArmPosition__fini(message_memory);
}

size_t message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__size_function__ArmPosition__arm_positions(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return member->size;
}

const void * message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__get_const_function__ArmPosition__arm_positions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__get_function__ArmPosition__arm_positions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__fetch_function__ArmPosition__arm_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint32_t * item =
    ((const uint32_t *)
    message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__get_const_function__ArmPosition__arm_positions(untyped_member, index));
  uint32_t * value =
    (uint32_t *)(untyped_value);
  *value = *item;
}

void message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__assign_function__ArmPosition__arm_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint32_t * item =
    ((uint32_t *)
    message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__get_function__ArmPosition__arm_positions(untyped_member, index));
  const uint32_t * value =
    (const uint32_t *)(untyped_value);
  *item = *value;
}

bool message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__resize_function__ArmPosition__arm_positions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  rosidl_runtime_c__uint32__Sequence__fini(member);
  return rosidl_runtime_c__uint32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__ArmPosition_message_member_array[1] = {
  {
    "arm_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(message_interfaces__msg__ArmPosition, arm_positions),  // bytes offset in struct
    NULL,  // default value
    message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__size_function__ArmPosition__arm_positions,  // size() function pointer
    message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__get_const_function__ArmPosition__arm_positions,  // get_const(index) function pointer
    message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__get_function__ArmPosition__arm_positions,  // get(index) function pointer
    message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__fetch_function__ArmPosition__arm_positions,  // fetch(index, &value) function pointer
    message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__assign_function__ArmPosition__arm_positions,  // assign(index, value) function pointer
    message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__resize_function__ArmPosition__arm_positions  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__ArmPosition_message_members = {
  "message_interfaces__msg",  // message namespace
  "ArmPosition",  // message name
  1,  // number of fields
  sizeof(message_interfaces__msg__ArmPosition),
  false,  // has_any_key_member_
  message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__ArmPosition_message_member_array,  // message members
  message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__ArmPosition_init_function,  // function to initialize message memory (memory has to be allocated)
  message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__ArmPosition_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__ArmPosition_message_type_support_handle = {
  0,
  &message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__ArmPosition_message_members,
  get_message_typesupport_handle_function,
  &message_interfaces__msg__ArmPosition__get_type_hash,
  &message_interfaces__msg__ArmPosition__get_type_description,
  &message_interfaces__msg__ArmPosition__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_message_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, message_interfaces, msg, ArmPosition)() {
  if (!message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__ArmPosition_message_type_support_handle.typesupport_identifier) {
    message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__ArmPosition_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &message_interfaces__msg__ArmPosition__rosidl_typesupport_introspection_c__ArmPosition_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
