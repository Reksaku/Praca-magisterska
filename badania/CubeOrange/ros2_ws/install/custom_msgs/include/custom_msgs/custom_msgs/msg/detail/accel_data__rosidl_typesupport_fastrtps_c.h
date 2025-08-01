// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from custom_msgs:msg/AccelData.idl
// generated code does not contain a copyright notice
#ifndef CUSTOM_MSGS__MSG__DETAIL__ACCEL_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define CUSTOM_MSGS__MSG__DETAIL__ACCEL_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_msgs/msg/detail/accel_data__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
bool cdr_serialize_custom_msgs__msg__AccelData(
  const custom_msgs__msg__AccelData * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
bool cdr_deserialize_custom_msgs__msg__AccelData(
  eprosima::fastcdr::Cdr &,
  custom_msgs__msg__AccelData * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t get_serialized_size_custom_msgs__msg__AccelData(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t max_serialized_size_custom_msgs__msg__AccelData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
bool cdr_serialize_key_custom_msgs__msg__AccelData(
  const custom_msgs__msg__AccelData * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t get_serialized_size_key_custom_msgs__msg__AccelData(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t max_serialized_size_key_custom_msgs__msg__AccelData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msgs, msg, AccelData)();

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__ACCEL_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
