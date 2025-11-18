// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from message_interfaces:msg/ArduinoCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "message_interfaces/msg/arduino_command.h"


#ifndef MESSAGE_INTERFACES__MSG__DETAIL__ARDUINO_COMMAND__STRUCT_H_
#define MESSAGE_INTERFACES__MSG__DETAIL__ARDUINO_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'arduino_command'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ArduinoCommand in the package message_interfaces.
typedef struct message_interfaces__msg__ArduinoCommand
{
  rosidl_runtime_c__String arduino_command;
} message_interfaces__msg__ArduinoCommand;

// Struct for a sequence of message_interfaces__msg__ArduinoCommand.
typedef struct message_interfaces__msg__ArduinoCommand__Sequence
{
  message_interfaces__msg__ArduinoCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} message_interfaces__msg__ArduinoCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGE_INTERFACES__MSG__DETAIL__ARDUINO_COMMAND__STRUCT_H_
