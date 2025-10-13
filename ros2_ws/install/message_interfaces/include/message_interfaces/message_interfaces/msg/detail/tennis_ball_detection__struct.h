// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from message_interfaces:msg/TennisBallDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "message_interfaces/msg/tennis_ball_detection.h"


#ifndef MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_DETECTION__STRUCT_H_
#define MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/TennisBallDetection in the package message_interfaces.
typedef struct message_interfaces__msg__TennisBallDetection
{
  uint16_t left_x;
  uint16_t right_x;
  uint16_t top_y;
  uint16_t bottom_y;
} message_interfaces__msg__TennisBallDetection;

// Struct for a sequence of message_interfaces__msg__TennisBallDetection.
typedef struct message_interfaces__msg__TennisBallDetection__Sequence
{
  message_interfaces__msg__TennisBallDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} message_interfaces__msg__TennisBallDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_DETECTION__STRUCT_H_
