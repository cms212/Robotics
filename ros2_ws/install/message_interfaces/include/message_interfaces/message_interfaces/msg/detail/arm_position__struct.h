// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from message_interfaces:msg/ArmPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "message_interfaces/msg/arm_position.h"


#ifndef MESSAGE_INTERFACES__MSG__DETAIL__ARM_POSITION__STRUCT_H_
#define MESSAGE_INTERFACES__MSG__DETAIL__ARM_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'arm_positions'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/ArmPosition in the package message_interfaces.
typedef struct message_interfaces__msg__ArmPosition
{
  rosidl_runtime_c__uint32__Sequence arm_positions;
} message_interfaces__msg__ArmPosition;

// Struct for a sequence of message_interfaces__msg__ArmPosition.
typedef struct message_interfaces__msg__ArmPosition__Sequence
{
  message_interfaces__msg__ArmPosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} message_interfaces__msg__ArmPosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGE_INTERFACES__MSG__DETAIL__ARM_POSITION__STRUCT_H_
