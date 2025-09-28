// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from message_interfaces:msg/ArmPosition.idl
// generated code does not contain a copyright notice

#include "message_interfaces/msg/detail/arm_position__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_message_interfaces
const rosidl_type_hash_t *
message_interfaces__msg__ArmPosition__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xbd, 0xb8, 0x81, 0xf8, 0xb0, 0x1d, 0x18, 0x3a,
      0xaa, 0x1d, 0xbe, 0x15, 0x6b, 0x52, 0x1f, 0xa2,
      0x84, 0x7e, 0x31, 0xd9, 0xbe, 0x8b, 0xd2, 0x44,
      0x7c, 0xd7, 0xb6, 0xd0, 0x55, 0x12, 0x63, 0xfc,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char message_interfaces__msg__ArmPosition__TYPE_NAME[] = "message_interfaces/msg/ArmPosition";

// Define type names, field names, and default values
static char message_interfaces__msg__ArmPosition__FIELD_NAME__arm_positions[] = "arm_positions";

static rosidl_runtime_c__type_description__Field message_interfaces__msg__ArmPosition__FIELDS[] = {
  {
    {message_interfaces__msg__ArmPosition__FIELD_NAME__arm_positions, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
message_interfaces__msg__ArmPosition__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {message_interfaces__msg__ArmPosition__TYPE_NAME, 34, 34},
      {message_interfaces__msg__ArmPosition__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint32[] arm_positions";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
message_interfaces__msg__ArmPosition__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {message_interfaces__msg__ArmPosition__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 22, 22},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
message_interfaces__msg__ArmPosition__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *message_interfaces__msg__ArmPosition__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
