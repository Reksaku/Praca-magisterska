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
      0xef, 0x22, 0xe0, 0x40, 0x82, 0x60, 0x16, 0x5a,
      0x98, 0x6b, 0x7a, 0xbf, 0xcc, 0xf9, 0x06, 0xd7,
      0xa9, 0xb4, 0x13, 0x88, 0xef, 0x99, 0x94, 0x3b,
      0xf1, 0x7d, 0xdc, 0xf0, 0xf5, 0xb0, 0x39, 0x78,
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
static char custom_msgs__msg__EstimatorData__FIELD_NAME__rotation[] = "rotation";

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
    {custom_msgs__msg__EstimatorData__FIELD_NAME__rotation, 8, 8},
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
      {custom_msgs__msg__EstimatorData__FIELDS, 5, 5},
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
  "DataXYZ rotation";

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
    {toplevel_type_raw_source, 78, 78},
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
