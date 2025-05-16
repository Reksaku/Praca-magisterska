// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/ImuData.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/imu_data__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__ImuData__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xbc, 0xc3, 0xb1, 0x37, 0x9f, 0xbd, 0x87, 0xe3,
      0xde, 0xe4, 0x3b, 0x7c, 0x4d, 0x23, 0xdd, 0xb1,
      0xc2, 0x09, 0x5e, 0x9e, 0x75, 0xd5, 0x84, 0x8e,
      0xdc, 0x36, 0x89, 0x4d, 0xdb, 0x6e, 0xa7, 0x45,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "custom_msgs/msg/detail/accel_data__functions.h"
#include "custom_msgs/msg/detail/gyro_data__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t custom_msgs__msg__AccelData__EXPECTED_HASH = {1, {
    0x6f, 0x9a, 0xd0, 0x31, 0xbb, 0x21, 0x92, 0x21,
    0x92, 0x5f, 0xce, 0x01, 0xf9, 0x70, 0x1e, 0x4a,
    0xed, 0x8e, 0xab, 0x91, 0x32, 0x3e, 0x5e, 0xd7,
    0x62, 0x31, 0xcd, 0x15, 0x01, 0x93, 0xaf, 0x64,
  }};
static const rosidl_type_hash_t custom_msgs__msg__GyroData__EXPECTED_HASH = {1, {
    0xa7, 0xba, 0xb7, 0x53, 0xa3, 0x1e, 0x09, 0xc0,
    0xd4, 0x8c, 0x84, 0xc7, 0xb7, 0xa2, 0x20, 0x87,
    0xf2, 0x1d, 0x4b, 0x03, 0x45, 0x6f, 0xa1, 0x16,
    0x20, 0x00, 0xd2, 0x68, 0x08, 0x40, 0x8d, 0xaf,
  }};
#endif

static char custom_msgs__msg__ImuData__TYPE_NAME[] = "custom_msgs/msg/ImuData";
static char custom_msgs__msg__AccelData__TYPE_NAME[] = "custom_msgs/msg/AccelData";
static char custom_msgs__msg__GyroData__TYPE_NAME[] = "custom_msgs/msg/GyroData";

// Define type names, field names, and default values
static char custom_msgs__msg__ImuData__FIELD_NAME__timestamp[] = "timestamp";
static char custom_msgs__msg__ImuData__FIELD_NAME__accel[] = "accel";
static char custom_msgs__msg__ImuData__FIELD_NAME__gyro[] = "gyro";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__ImuData__FIELDS[] = {
  {
    {custom_msgs__msg__ImuData__FIELD_NAME__timestamp, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__ImuData__FIELD_NAME__accel, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_msgs__msg__AccelData__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__ImuData__FIELD_NAME__gyro, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_msgs__msg__GyroData__TYPE_NAME, 24, 24},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription custom_msgs__msg__ImuData__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {custom_msgs__msg__AccelData__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__GyroData__TYPE_NAME, 24, 24},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_msgs__msg__ImuData__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__ImuData__TYPE_NAME, 23, 23},
      {custom_msgs__msg__ImuData__FIELDS, 3, 3},
    },
    {custom_msgs__msg__ImuData__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&custom_msgs__msg__AccelData__EXPECTED_HASH, custom_msgs__msg__AccelData__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = custom_msgs__msg__AccelData__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&custom_msgs__msg__GyroData__EXPECTED_HASH, custom_msgs__msg__GyroData__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = custom_msgs__msg__GyroData__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int64 timestamp\n"
  "AccelData accel\n"
  "GyroData gyro";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__msg__ImuData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__ImuData__TYPE_NAME, 23, 23},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 45, 45},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__ImuData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__ImuData__get_individual_type_description_source(NULL),
    sources[1] = *custom_msgs__msg__AccelData__get_individual_type_description_source(NULL);
    sources[2] = *custom_msgs__msg__GyroData__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
