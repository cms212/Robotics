// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from message_interfaces:msg/TennisBallOrientation.idl
// generated code does not contain a copyright notice

#include "message_interfaces/msg/detail/tennis_ball_orientation__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_message_interfaces
const rosidl_type_hash_t *
message_interfaces__msg__TennisBallOrientation__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8e, 0xea, 0x1a, 0xc4, 0x99, 0x39, 0x2d, 0xef,
      0xd4, 0xf7, 0x56, 0x7d, 0x55, 0x6c, 0x1c, 0x48,
      0x5b, 0xa5, 0xa0, 0x3f, 0xc0, 0xa9, 0xdb, 0x64,
      0xe1, 0x7c, 0xc9, 0xa6, 0x1a, 0x5e, 0x8c, 0x3d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char message_interfaces__msg__TennisBallOrientation__TYPE_NAME[] = "message_interfaces/msg/TennisBallOrientation";

// Define type names, field names, and default values
static char message_interfaces__msg__TennisBallOrientation__FIELD_NAME__x[] = "x";
static char message_interfaces__msg__TennisBallOrientation__FIELD_NAME__y[] = "y";
static char message_interfaces__msg__TennisBallOrientation__FIELD_NAME__z[] = "z";

static rosidl_runtime_c__type_description__Field message_interfaces__msg__TennisBallOrientation__FIELDS[] = {
  {
    {message_interfaces__msg__TennisBallOrientation__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {message_interfaces__msg__TennisBallOrientation__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {message_interfaces__msg__TennisBallOrientation__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
message_interfaces__msg__TennisBallOrientation__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {message_interfaces__msg__TennisBallOrientation__TYPE_NAME, 44, 44},
      {message_interfaces__msg__TennisBallOrientation__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 x \n"
  "float32 y \n"
  "float32 z";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
message_interfaces__msg__TennisBallOrientation__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {message_interfaces__msg__TennisBallOrientation__TYPE_NAME, 44, 44},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 31, 31},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
message_interfaces__msg__TennisBallOrientation__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *message_interfaces__msg__TennisBallOrientation__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
