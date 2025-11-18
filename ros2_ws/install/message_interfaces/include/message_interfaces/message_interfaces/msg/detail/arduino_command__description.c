// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from message_interfaces:msg/ArduinoCommand.idl
// generated code does not contain a copyright notice

#include "message_interfaces/msg/detail/arduino_command__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_message_interfaces
const rosidl_type_hash_t *
message_interfaces__msg__ArduinoCommand__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x35, 0x65, 0x8d, 0x0e, 0xd5, 0xc9, 0xce, 0xbf,
      0x24, 0xbe, 0xb2, 0x13, 0xff, 0x28, 0x25, 0xe8,
      0xf1, 0xa4, 0x73, 0x3a, 0xd0, 0x03, 0x35, 0xb9,
      0x9a, 0xae, 0x09, 0xf7, 0x31, 0x39, 0xc6, 0x02,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char message_interfaces__msg__ArduinoCommand__TYPE_NAME[] = "message_interfaces/msg/ArduinoCommand";

// Define type names, field names, and default values
static char message_interfaces__msg__ArduinoCommand__FIELD_NAME__arduino_command[] = "arduino_command";

static rosidl_runtime_c__type_description__Field message_interfaces__msg__ArduinoCommand__FIELDS[] = {
  {
    {message_interfaces__msg__ArduinoCommand__FIELD_NAME__arduino_command, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
message_interfaces__msg__ArduinoCommand__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {message_interfaces__msg__ArduinoCommand__TYPE_NAME, 37, 37},
      {message_interfaces__msg__ArduinoCommand__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string arduino_command";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
message_interfaces__msg__ArduinoCommand__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {message_interfaces__msg__ArduinoCommand__TYPE_NAME, 37, 37},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 22, 22},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
message_interfaces__msg__ArduinoCommand__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *message_interfaces__msg__ArduinoCommand__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
