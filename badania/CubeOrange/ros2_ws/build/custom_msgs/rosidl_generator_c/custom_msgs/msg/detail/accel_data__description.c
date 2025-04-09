// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/AccelData.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/accel_data__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__AccelData__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x6f, 0x9a, 0xd0, 0x31, 0xbb, 0x21, 0x92, 0x21,
      0x92, 0x5f, 0xce, 0x01, 0xf9, 0x70, 0x1e, 0x4a,
      0xed, 0x8e, 0xab, 0x91, 0x32, 0x3e, 0x5e, 0xd7,
      0x62, 0x31, 0xcd, 0x15, 0x01, 0x93, 0xaf, 0x64,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_msgs__msg__AccelData__TYPE_NAME[] = "custom_msgs/msg/AccelData";

// Define type names, field names, and default values
static char custom_msgs__msg__AccelData__FIELD_NAME__x[] = "x";
static char custom_msgs__msg__AccelData__FIELD_NAME__y[] = "y";
static char custom_msgs__msg__AccelData__FIELD_NAME__z[] = "z";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__AccelData__FIELDS[] = {
  {
    {custom_msgs__msg__AccelData__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__AccelData__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__AccelData__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_msgs__msg__AccelData__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__AccelData__TYPE_NAME, 25, 25},
      {custom_msgs__msg__AccelData__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 x\n"
  "float64 y\n"
  "float64 z";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__msg__AccelData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__AccelData__TYPE_NAME, 25, 25},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 29, 29},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__AccelData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__AccelData__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
