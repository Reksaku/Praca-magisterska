// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/PossitionData.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/possition_data__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__PossitionData__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x29, 0x41, 0x46, 0x64, 0xde, 0x50, 0x29, 0xd1,
      0xef, 0x58, 0x4f, 0x8f, 0x40, 0xac, 0xb7, 0xe3,
      0x05, 0xd5, 0xe2, 0x81, 0x76, 0x97, 0xf9, 0x0b,
      0xe8, 0x48, 0xaa, 0xb0, 0x1b, 0x71, 0xbc, 0x39,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_msgs__msg__PossitionData__TYPE_NAME[] = "custom_msgs/msg/PossitionData";

// Define type names, field names, and default values
static char custom_msgs__msg__PossitionData__FIELD_NAME__x[] = "x";
static char custom_msgs__msg__PossitionData__FIELD_NAME__y[] = "y";
static char custom_msgs__msg__PossitionData__FIELD_NAME__z[] = "z";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__PossitionData__FIELDS[] = {
  {
    {custom_msgs__msg__PossitionData__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__PossitionData__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__PossitionData__FIELD_NAME__z, 1, 1},
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
custom_msgs__msg__PossitionData__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__PossitionData__TYPE_NAME, 29, 29},
      {custom_msgs__msg__PossitionData__FIELDS, 3, 3},
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
custom_msgs__msg__PossitionData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__PossitionData__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 29, 29},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__PossitionData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__PossitionData__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
