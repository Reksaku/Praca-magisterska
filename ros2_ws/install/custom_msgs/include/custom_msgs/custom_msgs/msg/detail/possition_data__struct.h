// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/PossitionData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/possition_data.h"


#ifndef CUSTOM_MSGS__MSG__DETAIL__POSSITION_DATA__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__POSSITION_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/PossitionData in the package custom_msgs.
typedef struct custom_msgs__msg__PossitionData
{
  double x;
  double y;
  double z;
} custom_msgs__msg__PossitionData;

// Struct for a sequence of custom_msgs__msg__PossitionData.
typedef struct custom_msgs__msg__PossitionData__Sequence
{
  custom_msgs__msg__PossitionData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__PossitionData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__POSSITION_DATA__STRUCT_H_
