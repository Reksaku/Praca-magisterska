// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/DataXYZ.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/data_xyz__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__DataXYZ__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa0, 0x8f, 0x26, 0x09, 0xe6, 0x1f, 0xe4, 0x1b,
      0xf7, 0x03, 0xb6, 0x36, 0x70, 0xae, 0x70, 0x0d,
      0xbf, 0x82, 0x14, 0x21, 0x35, 0xc6, 0xed, 0xbd,
      0xf3, 0x18, 0x7c, 0x26, 0x28, 0x1a, 0xa1, 0xf7,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_msgs__msg__DataXYZ__TYPE_NAME[] = "custom_msgs/msg/DataXYZ";

// Define type names, field names, and default values
static char custom_msgs__msg__DataXYZ__FIELD_NAME__x[] = "x";
static char custom_msgs__msg__DataXYZ__FIELD_NAME__y[] = "y";
static char custom_msgs__msg__DataXYZ__FIELD_NAME__z[] = "z";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__DataXYZ__FIELDS[] = {
  {
    {custom_msgs__msg__DataXYZ__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__DataXYZ__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__DataXYZ__FIELD_NAME__z, 1, 1},
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
custom_msgs__msg__DataXYZ__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__DataXYZ__TYPE_NAME, 23, 23},
      {custom_msgs__msg__DataXYZ__FIELDS, 3, 3},
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
custom_msgs__msg__DataXYZ__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__DataXYZ__TYPE_NAME, 23, 23},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 29, 29},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__DataXYZ__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__DataXYZ__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
