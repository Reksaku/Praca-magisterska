// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/SpeedData.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/speed_data__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__SpeedData__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x6f, 0x44, 0xea, 0xf6, 0xd5, 0xa6, 0xf6, 0xf3,
      0x8b, 0x64, 0xd2, 0xb8, 0xc4, 0x0a, 0xb6, 0xf1,
      0xbe, 0x8c, 0x40, 0xe6, 0x8b, 0x41, 0x0d, 0xfc,
      0xbb, 0x3b, 0xbc, 0x03, 0xb3, 0x57, 0x0d, 0xd4,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_msgs__msg__SpeedData__TYPE_NAME[] = "custom_msgs/msg/SpeedData";

// Define type names, field names, and default values
static char custom_msgs__msg__SpeedData__FIELD_NAME__x[] = "x";
static char custom_msgs__msg__SpeedData__FIELD_NAME__y[] = "y";
static char custom_msgs__msg__SpeedData__FIELD_NAME__z[] = "z";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__SpeedData__FIELDS[] = {
  {
    {custom_msgs__msg__SpeedData__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__SpeedData__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__SpeedData__FIELD_NAME__z, 1, 1},
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
custom_msgs__msg__SpeedData__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__SpeedData__TYPE_NAME, 25, 25},
      {custom_msgs__msg__SpeedData__FIELDS, 3, 3},
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
custom_msgs__msg__SpeedData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__SpeedData__TYPE_NAME, 25, 25},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 29, 29},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__SpeedData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__SpeedData__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
