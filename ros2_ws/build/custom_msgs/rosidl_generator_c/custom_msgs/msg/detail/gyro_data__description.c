// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/GyroData.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/gyro_data__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__GyroData__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa7, 0xba, 0xb7, 0x53, 0xa3, 0x1e, 0x09, 0xc0,
      0xd4, 0x8c, 0x84, 0xc7, 0xb7, 0xa2, 0x20, 0x87,
      0xf2, 0x1d, 0x4b, 0x03, 0x45, 0x6f, 0xa1, 0x16,
      0x20, 0x00, 0xd2, 0x68, 0x08, 0x40, 0x8d, 0xaf,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_msgs__msg__GyroData__TYPE_NAME[] = "custom_msgs/msg/GyroData";

// Define type names, field names, and default values
static char custom_msgs__msg__GyroData__FIELD_NAME__x[] = "x";
static char custom_msgs__msg__GyroData__FIELD_NAME__y[] = "y";
static char custom_msgs__msg__GyroData__FIELD_NAME__z[] = "z";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__GyroData__FIELDS[] = {
  {
    {custom_msgs__msg__GyroData__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__GyroData__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__GyroData__FIELD_NAME__z, 1, 1},
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
custom_msgs__msg__GyroData__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__GyroData__TYPE_NAME, 24, 24},
      {custom_msgs__msg__GyroData__FIELDS, 3, 3},
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
custom_msgs__msg__GyroData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__GyroData__TYPE_NAME, 24, 24},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 29, 29},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__GyroData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__GyroData__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
