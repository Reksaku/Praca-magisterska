// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/EstimatorData.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/estimator_data__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__EstimatorData__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe5, 0x9d, 0x32, 0x09, 0x98, 0x1a, 0x2d, 0xba,
      0x19, 0xb6, 0x5f, 0xc7, 0x25, 0x07, 0xb8, 0xdf,
      0x9d, 0xfb, 0xce, 0x32, 0xff, 0x93, 0x0e, 0xd0,
      0xc9, 0xa0, 0x1d, 0x79, 0x84, 0x56, 0x99, 0x5c,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "custom_msgs/msg/detail/data_xyz__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t custom_msgs__msg__DataXYZ__EXPECTED_HASH = {1, {
    0xa0, 0x8f, 0x26, 0x09, 0xe6, 0x1f, 0xe4, 0x1b,
    0xf7, 0x03, 0xb6, 0x36, 0x70, 0xae, 0x70, 0x0d,
    0xbf, 0x82, 0x14, 0x21, 0x35, 0xc6, 0xed, 0xbd,
    0xf3, 0x18, 0x7c, 0x26, 0x28, 0x1a, 0xa1, 0xf7,
  }};
#endif

static char custom_msgs__msg__EstimatorData__TYPE_NAME[] = "custom_msgs/msg/EstimatorData";
static char custom_msgs__msg__DataXYZ__TYPE_NAME[] = "custom_msgs/msg/DataXYZ";

// Define type names, field names, and default values
static char custom_msgs__msg__EstimatorData__FIELD_NAME__timestamp[] = "timestamp";
static char custom_msgs__msg__EstimatorData__FIELD_NAME__possition[] = "possition";
static char custom_msgs__msg__EstimatorData__FIELD_NAME__speed[] = "speed";
static char custom_msgs__msg__EstimatorData__FIELD_NAME__accel[] = "accel";
static char custom_msgs__msg__EstimatorData__FIELD_NAME__orientation[] = "orientation";
static char custom_msgs__msg__EstimatorData__FIELD_NAME__raw_data[] = "raw_data";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__EstimatorData__FIELDS[] = {
  {
    {custom_msgs__msg__EstimatorData__FIELD_NAME__timestamp, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__EstimatorData__FIELD_NAME__possition, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_msgs__msg__DataXYZ__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__EstimatorData__FIELD_NAME__speed, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_msgs__msg__DataXYZ__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__EstimatorData__FIELD_NAME__accel, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_msgs__msg__DataXYZ__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__EstimatorData__FIELD_NAME__orientation, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_msgs__msg__DataXYZ__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__EstimatorData__FIELD_NAME__raw_data, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_msgs__msg__DataXYZ__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription custom_msgs__msg__EstimatorData__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {custom_msgs__msg__DataXYZ__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_msgs__msg__EstimatorData__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__EstimatorData__TYPE_NAME, 29, 29},
      {custom_msgs__msg__EstimatorData__FIELDS, 6, 6},
    },
    {custom_msgs__msg__EstimatorData__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&custom_msgs__msg__DataXYZ__EXPECTED_HASH, custom_msgs__msg__DataXYZ__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = custom_msgs__msg__DataXYZ__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int64 timestamp\n"
  "DataXYZ possition\n"
  "DataXYZ speed\n"
  "DataXYZ accel\n"
  "DataXYZ orientation\n"
  "DataXYZ raw_data";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__msg__EstimatorData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__EstimatorData__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 98, 98},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__EstimatorData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__EstimatorData__get_individual_type_description_source(NULL),
    sources[1] = *custom_msgs__msg__DataXYZ__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
