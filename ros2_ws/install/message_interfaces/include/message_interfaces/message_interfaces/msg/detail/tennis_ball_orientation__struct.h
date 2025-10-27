// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from message_interfaces:msg/TennisBallOrientation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "message_interfaces/msg/tennis_ball_orientation.h"


#ifndef MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_ORIENTATION__STRUCT_H_
#define MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_ORIENTATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/TennisBallOrientation in the package message_interfaces.
typedef struct message_interfaces__msg__TennisBallOrientation
{
  float x;
  float y;
  float z;
} message_interfaces__msg__TennisBallOrientation;

// Struct for a sequence of message_interfaces__msg__TennisBallOrientation.
typedef struct message_interfaces__msg__TennisBallOrientation__Sequence
{
  message_interfaces__msg__TennisBallOrientation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} message_interfaces__msg__TennisBallOrientation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_ORIENTATION__STRUCT_H_
