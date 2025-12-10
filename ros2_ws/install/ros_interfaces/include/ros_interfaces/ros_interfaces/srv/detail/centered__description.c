// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros_interfaces:srv/Centered.idl
// generated code does not contain a copyright notice

#include "ros_interfaces/srv/detail/centered__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros_interfaces
const rosidl_type_hash_t *
ros_interfaces__srv__Centered__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x39, 0x48, 0x49, 0xf2, 0x9b, 0xf8, 0x09, 0xdf,
      0xc1, 0xbd, 0x6e, 0xe2, 0xc5, 0x5e, 0x07, 0xef,
      0x93, 0xff, 0xc7, 0x11, 0x73, 0x63, 0x04, 0xe6,
      0x3c, 0x1c, 0x7c, 0xf5, 0x2c, 0x7d, 0x46, 0x3c,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_ros_interfaces
const rosidl_type_hash_t *
ros_interfaces__srv__Centered_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x43, 0xd2, 0x6f, 0xe3, 0x57, 0x0d, 0xaa, 0x55,
      0x8f, 0x3b, 0x77, 0x24, 0x89, 0x00, 0x67, 0x34,
      0xfb, 0x99, 0xe4, 0x20, 0x88, 0x99, 0xce, 0x68,
      0x90, 0x32, 0x27, 0x73, 0x23, 0xd8, 0x08, 0x9f,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_ros_interfaces
const rosidl_type_hash_t *
ros_interfaces__srv__Centered_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x31, 0x0a, 0x0e, 0x50, 0xe3, 0x20, 0x01, 0x47,
      0x5e, 0x11, 0x4e, 0x61, 0xac, 0x1c, 0x4e, 0x36,
      0xbd, 0x49, 0xca, 0x8d, 0x47, 0x23, 0x28, 0x44,
      0xe0, 0x90, 0xaa, 0x10, 0x70, 0xc8, 0xc9, 0x61,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_ros_interfaces
const rosidl_type_hash_t *
ros_interfaces__srv__Centered_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x45, 0xdb, 0x3c, 0x17, 0x27, 0x14, 0x84, 0x37,
      0x38, 0xce, 0xb1, 0x41, 0xdd, 0x30, 0x5b, 0xb2,
      0x27, 0xe7, 0xa9, 0xf8, 0x34, 0x79, 0x23, 0xee,
      0xbc, 0x5a, 0xdd, 0x0f, 0xa3, 0x4a, 0x4e, 0x4a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char ros_interfaces__srv__Centered__TYPE_NAME[] = "ros_interfaces/srv/Centered";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char ros_interfaces__srv__Centered_Event__TYPE_NAME[] = "ros_interfaces/srv/Centered_Event";
static char ros_interfaces__srv__Centered_Request__TYPE_NAME[] = "ros_interfaces/srv/Centered_Request";
static char ros_interfaces__srv__Centered_Response__TYPE_NAME[] = "ros_interfaces/srv/Centered_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char ros_interfaces__srv__Centered__FIELD_NAME__request_message[] = "request_message";
static char ros_interfaces__srv__Centered__FIELD_NAME__response_message[] = "response_message";
static char ros_interfaces__srv__Centered__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field ros_interfaces__srv__Centered__FIELDS[] = {
  {
    {ros_interfaces__srv__Centered__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros_interfaces__srv__Centered_Request__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
  {
    {ros_interfaces__srv__Centered__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros_interfaces__srv__Centered_Response__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {ros_interfaces__srv__Centered__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros_interfaces__srv__Centered_Event__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros_interfaces__srv__Centered__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {ros_interfaces__srv__Centered_Event__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {ros_interfaces__srv__Centered_Request__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {ros_interfaces__srv__Centered_Response__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_interfaces__srv__Centered__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_interfaces__srv__Centered__TYPE_NAME, 27, 27},
      {ros_interfaces__srv__Centered__FIELDS, 3, 3},
    },
    {ros_interfaces__srv__Centered__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = ros_interfaces__srv__Centered_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = ros_interfaces__srv__Centered_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = ros_interfaces__srv__Centered_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char ros_interfaces__srv__Centered_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field ros_interfaces__srv__Centered_Request__FIELDS[] = {
  {
    {ros_interfaces__srv__Centered_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_interfaces__srv__Centered_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_interfaces__srv__Centered_Request__TYPE_NAME, 35, 35},
      {ros_interfaces__srv__Centered_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char ros_interfaces__srv__Centered_Response__FIELD_NAME__x[] = "x";

static rosidl_runtime_c__type_description__Field ros_interfaces__srv__Centered_Response__FIELDS[] = {
  {
    {ros_interfaces__srv__Centered_Response__FIELD_NAME__x, 1, 1},
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
ros_interfaces__srv__Centered_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_interfaces__srv__Centered_Response__TYPE_NAME, 36, 36},
      {ros_interfaces__srv__Centered_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char ros_interfaces__srv__Centered_Event__FIELD_NAME__info[] = "info";
static char ros_interfaces__srv__Centered_Event__FIELD_NAME__request[] = "request";
static char ros_interfaces__srv__Centered_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field ros_interfaces__srv__Centered_Event__FIELDS[] = {
  {
    {ros_interfaces__srv__Centered_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {ros_interfaces__srv__Centered_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {ros_interfaces__srv__Centered_Request__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
  {
    {ros_interfaces__srv__Centered_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {ros_interfaces__srv__Centered_Response__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros_interfaces__srv__Centered_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {ros_interfaces__srv__Centered_Request__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {ros_interfaces__srv__Centered_Response__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_interfaces__srv__Centered_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_interfaces__srv__Centered_Event__TYPE_NAME, 33, 33},
      {ros_interfaces__srv__Centered_Event__FIELDS, 3, 3},
    },
    {ros_interfaces__srv__Centered_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = ros_interfaces__srv__Centered_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = ros_interfaces__srv__Centered_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "---\n"
  "float32 x";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros_interfaces__srv__Centered__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_interfaces__srv__Centered__TYPE_NAME, 27, 27},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 13, 13},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
ros_interfaces__srv__Centered_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_interfaces__srv__Centered_Request__TYPE_NAME, 35, 35},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
ros_interfaces__srv__Centered_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_interfaces__srv__Centered_Response__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
ros_interfaces__srv__Centered_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_interfaces__srv__Centered_Event__TYPE_NAME, 33, 33},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_interfaces__srv__Centered__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_interfaces__srv__Centered__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *ros_interfaces__srv__Centered_Event__get_individual_type_description_source(NULL);
    sources[3] = *ros_interfaces__srv__Centered_Request__get_individual_type_description_source(NULL);
    sources[4] = *ros_interfaces__srv__Centered_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_interfaces__srv__Centered_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_interfaces__srv__Centered_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_interfaces__srv__Centered_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_interfaces__srv__Centered_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_interfaces__srv__Centered_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_interfaces__srv__Centered_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *ros_interfaces__srv__Centered_Request__get_individual_type_description_source(NULL);
    sources[3] = *ros_interfaces__srv__Centered_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
