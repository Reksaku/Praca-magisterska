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
      0x4b, 0x1e, 0xcf, 0x17, 0x9e, 0xa2, 0x9d, 0xc8,
      0x1c, 0xab, 0xd9, 0xc4, 0x67, 0x64, 0x33, 0x74,
      0x63, 0x23, 0x3d, 0xc2, 0x31, 0xf1, 0xad, 0x28,
      0x2b, 0xda, 0xd3, 0x67, 0x4c, 0x43, 0x38, 0x07,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "custom_msgs/msg/detail/possition_data__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t custom_msgs__msg__PossitionData__EXPECTED_HASH = {1, {
    0x29, 0x41, 0x46, 0x64, 0xde, 0x50, 0x29, 0xd1,
    0xef, 0x58, 0x4f, 0x8f, 0x40, 0xac, 0xb7, 0xe3,
    0x05, 0xd5, 0xe2, 0x81, 0x76, 0x97, 0xf9, 0x0b,
    0xe8, 0x48, 0xaa, 0xb0, 0x1b, 0x71, 0xbc, 0x39,
  }};
#endif

static char custom_msgs__msg__EstimatorData__TYPE_NAME[] = "custom_msgs/msg/EstimatorData";
static char custom_msgs__msg__PossitionData__TYPE_NAME[] = "custom_msgs/msg/PossitionData";

// Define type names, field names, and default values
static char custom_msgs__msg__EstimatorData__FIELD_NAME__timestamp[] = "timestamp";
static char custom_msgs__msg__EstimatorData__FIELD_NAME__possition[] = "possition";

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
      {custom_msgs__msg__PossitionData__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription custom_msgs__msg__EstimatorData__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {custom_msgs__msg__PossitionData__TYPE_NAME, 29, 29},
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
      {custom_msgs__msg__EstimatorData__FIELDS, 2, 2},
    },
    {custom_msgs__msg__EstimatorData__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&custom_msgs__msg__PossitionData__EXPECTED_HASH, custom_msgs__msg__PossitionData__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = custom_msgs__msg__PossitionData__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int64 timestamp\n"
  "PossitionData possition";

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
    {toplevel_type_raw_source, 39, 39},
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
    sources[1] = *custom_msgs__msg__PossitionData__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
