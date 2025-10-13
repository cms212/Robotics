// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from message_interfaces:msg/TennisBallDetection.idl
// generated code does not contain a copyright notice

#include "message_interfaces/msg/detail/tennis_ball_detection__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_message_interfaces
const rosidl_type_hash_t *
message_interfaces__msg__TennisBallDetection__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9e, 0xc7, 0x6a, 0x38, 0x2f, 0x13, 0xa2, 0x6d,
      0x90, 0x78, 0xf9, 0xda, 0x27, 0x99, 0x1b, 0xc6,
      0x94, 0x03, 0x94, 0x61, 0x7a, 0xf3, 0x29, 0xc2,
      0xda, 0xf3, 0xd7, 0x45, 0xfc, 0xa2, 0x90, 0xb3,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char message_interfaces__msg__TennisBallDetection__TYPE_NAME[] = "message_interfaces/msg/TennisBallDetection";

// Define type names, field names, and default values
static char message_interfaces__msg__TennisBallDetection__FIELD_NAME__left_x[] = "left_x";
static char message_interfaces__msg__TennisBallDetection__FIELD_NAME__right_x[] = "right_x";
static char message_interfaces__msg__TennisBallDetection__FIELD_NAME__top_y[] = "top_y";
static char message_interfaces__msg__TennisBallDetection__FIELD_NAME__bottom_y[] = "bottom_y";

static rosidl_runtime_c__type_description__Field message_interfaces__msg__TennisBallDetection__FIELDS[] = {
  {
    {message_interfaces__msg__TennisBallDetection__FIELD_NAME__left_x, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {message_interfaces__msg__TennisBallDetection__FIELD_NAME__right_x, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {message_interfaces__msg__TennisBallDetection__FIELD_NAME__top_y, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {message_interfaces__msg__TennisBallDetection__FIELD_NAME__bottom_y, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
message_interfaces__msg__TennisBallDetection__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {message_interfaces__msg__TennisBallDetection__TYPE_NAME, 42, 42},
      {message_interfaces__msg__TennisBallDetection__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint16 left_x\n"
  "uint16 right_x\n"
  "uint16 top_y\n"
  "uint16 bottom_y";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
message_interfaces__msg__TennisBallDetection__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {message_interfaces__msg__TennisBallDetection__TYPE_NAME, 42, 42},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 58, 58},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
message_interfaces__msg__TennisBallDetection__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *message_interfaces__msg__TennisBallDetection__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
