// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_msgs:msg/EstimatorData.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/estimator_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_msgs/msg/detail/estimator_data__struct.h"
#include "custom_msgs/msg/detail/estimator_data__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "custom_msgs/msg/detail/data_xyz__functions.h"  // accel, possition, rotation, speed

// forward declare type support functions

bool cdr_serialize_custom_msgs__msg__DataXYZ(
  const custom_msgs__msg__DataXYZ * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_custom_msgs__msg__DataXYZ(
  eprosima::fastcdr::Cdr & cdr,
  custom_msgs__msg__DataXYZ * ros_message);

size_t get_serialized_size_custom_msgs__msg__DataXYZ(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_custom_msgs__msg__DataXYZ(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_custom_msgs__msg__DataXYZ(
  const custom_msgs__msg__DataXYZ * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_custom_msgs__msg__DataXYZ(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_custom_msgs__msg__DataXYZ(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msgs, msg, DataXYZ)();


using _EstimatorData__ros_msg_type = custom_msgs__msg__EstimatorData;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
bool cdr_serialize_custom_msgs__msg__EstimatorData(
  const custom_msgs__msg__EstimatorData * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: timestamp
  {
    cdr << ros_message->timestamp;
  }

  // Field name: possition
  {
    cdr_serialize_custom_msgs__msg__DataXYZ(
      &ros_message->possition, cdr);
  }

  // Field name: speed
  {
    cdr_serialize_custom_msgs__msg__DataXYZ(
      &ros_message->speed, cdr);
  }

  // Field name: accel
  {
    cdr_serialize_custom_msgs__msg__DataXYZ(
      &ros_message->accel, cdr);
  }

  // Field name: rotation
  {
    cdr_serialize_custom_msgs__msg__DataXYZ(
      &ros_message->rotation, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
bool cdr_deserialize_custom_msgs__msg__EstimatorData(
  eprosima::fastcdr::Cdr & cdr,
  custom_msgs__msg__EstimatorData * ros_message)
{
  // Field name: timestamp
  {
    cdr >> ros_message->timestamp;
  }

  // Field name: possition
  {
    cdr_deserialize_custom_msgs__msg__DataXYZ(cdr, &ros_message->possition);
  }

  // Field name: speed
  {
    cdr_deserialize_custom_msgs__msg__DataXYZ(cdr, &ros_message->speed);
  }

  // Field name: accel
  {
    cdr_deserialize_custom_msgs__msg__DataXYZ(cdr, &ros_message->accel);
  }

  // Field name: rotation
  {
    cdr_deserialize_custom_msgs__msg__DataXYZ(cdr, &ros_message->rotation);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t get_serialized_size_custom_msgs__msg__EstimatorData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _EstimatorData__ros_msg_type * ros_message = static_cast<const _EstimatorData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: timestamp
  {
    size_t item_size = sizeof(ros_message->timestamp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: possition
  current_alignment += get_serialized_size_custom_msgs__msg__DataXYZ(
    &(ros_message->possition), current_alignment);

  // Field name: speed
  current_alignment += get_serialized_size_custom_msgs__msg__DataXYZ(
    &(ros_message->speed), current_alignment);

  // Field name: accel
  current_alignment += get_serialized_size_custom_msgs__msg__DataXYZ(
    &(ros_message->accel), current_alignment);

  // Field name: rotation
  current_alignment += get_serialized_size_custom_msgs__msg__DataXYZ(
    &(ros_message->rotation), current_alignment);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t max_serialized_size_custom_msgs__msg__EstimatorData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: timestamp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: possition
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_custom_msgs__msg__DataXYZ(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: speed
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_custom_msgs__msg__DataXYZ(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: accel
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_custom_msgs__msg__DataXYZ(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: rotation
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_custom_msgs__msg__DataXYZ(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_msgs__msg__EstimatorData;
    is_plain =
      (
      offsetof(DataType, rotation) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
bool cdr_serialize_key_custom_msgs__msg__EstimatorData(
  const custom_msgs__msg__EstimatorData * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: timestamp
  {
    cdr << ros_message->timestamp;
  }

  // Field name: possition
  {
    cdr_serialize_key_custom_msgs__msg__DataXYZ(
      &ros_message->possition, cdr);
  }

  // Field name: speed
  {
    cdr_serialize_key_custom_msgs__msg__DataXYZ(
      &ros_message->speed, cdr);
  }

  // Field name: accel
  {
    cdr_serialize_key_custom_msgs__msg__DataXYZ(
      &ros_message->accel, cdr);
  }

  // Field name: rotation
  {
    cdr_serialize_key_custom_msgs__msg__DataXYZ(
      &ros_message->rotation, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t get_serialized_size_key_custom_msgs__msg__EstimatorData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _EstimatorData__ros_msg_type * ros_message = static_cast<const _EstimatorData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: timestamp
  {
    size_t item_size = sizeof(ros_message->timestamp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: possition
  current_alignment += get_serialized_size_key_custom_msgs__msg__DataXYZ(
    &(ros_message->possition), current_alignment);

  // Field name: speed
  current_alignment += get_serialized_size_key_custom_msgs__msg__DataXYZ(
    &(ros_message->speed), current_alignment);

  // Field name: accel
  current_alignment += get_serialized_size_key_custom_msgs__msg__DataXYZ(
    &(ros_message->accel), current_alignment);

  // Field name: rotation
  current_alignment += get_serialized_size_key_custom_msgs__msg__DataXYZ(
    &(ros_message->rotation), current_alignment);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t max_serialized_size_key_custom_msgs__msg__EstimatorData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: timestamp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: possition
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_custom_msgs__msg__DataXYZ(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: speed
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_custom_msgs__msg__DataXYZ(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: accel
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_custom_msgs__msg__DataXYZ(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: rotation
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_custom_msgs__msg__DataXYZ(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_msgs__msg__EstimatorData;
    is_plain =
      (
      offsetof(DataType, rotation) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _EstimatorData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const custom_msgs__msg__EstimatorData * ros_message = static_cast<const custom_msgs__msg__EstimatorData *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_custom_msgs__msg__EstimatorData(ros_message, cdr);
}

static bool _EstimatorData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  custom_msgs__msg__EstimatorData * ros_message = static_cast<custom_msgs__msg__EstimatorData *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_custom_msgs__msg__EstimatorData(cdr, ros_message);
}

static uint32_t _EstimatorData__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_msgs__msg__EstimatorData(
      untyped_ros_message, 0));
}

static size_t _EstimatorData__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_custom_msgs__msg__EstimatorData(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_EstimatorData = {
  "custom_msgs::msg",
  "EstimatorData",
  _EstimatorData__cdr_serialize,
  _EstimatorData__cdr_deserialize,
  _EstimatorData__get_serialized_size,
  _EstimatorData__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _EstimatorData__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_EstimatorData,
  get_message_typesupport_handle_function,
  &custom_msgs__msg__EstimatorData__get_type_hash,
  &custom_msgs__msg__EstimatorData__get_type_description,
  &custom_msgs__msg__EstimatorData__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msgs, msg, EstimatorData)() {
  return &_EstimatorData__type_support;
}

#if defined(__cplusplus)
}
#endif
