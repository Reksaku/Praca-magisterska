// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_msgs:msg/AccelData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_msgs/msg/detail/accel_data__rosidl_typesupport_introspection_c.h"
#include "custom_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_msgs/msg/detail/accel_data__functions.h"
#include "custom_msgs/msg/detail/accel_data__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void custom_msgs__msg__AccelData__rosidl_typesupport_introspection_c__AccelData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_msgs__msg__AccelData__init(message_memory);
}

void custom_msgs__msg__AccelData__rosidl_typesupport_introspection_c__AccelData_fini_function(void * message_memory)
{
  custom_msgs__msg__AccelData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember custom_msgs__msg__AccelData__rosidl_typesupport_introspection_c__AccelData_message_member_array[3] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__AccelData, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__AccelData, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__AccelData, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_msgs__msg__AccelData__rosidl_typesupport_introspection_c__AccelData_message_members = {
  "custom_msgs__msg",  // message namespace
  "AccelData",  // message name
  3,  // number of fields
  sizeof(custom_msgs__msg__AccelData),
  false,  // has_any_key_member_
  custom_msgs__msg__AccelData__rosidl_typesupport_introspection_c__AccelData_message_member_array,  // message members
  custom_msgs__msg__AccelData__rosidl_typesupport_introspection_c__AccelData_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_msgs__msg__AccelData__rosidl_typesupport_introspection_c__AccelData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_msgs__msg__AccelData__rosidl_typesupport_introspection_c__AccelData_message_type_support_handle = {
  0,
  &custom_msgs__msg__AccelData__rosidl_typesupport_introspection_c__AccelData_message_members,
  get_message_typesupport_handle_function,
  &custom_msgs__msg__AccelData__get_type_hash,
  &custom_msgs__msg__AccelData__get_type_description,
  &custom_msgs__msg__AccelData__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msgs, msg, AccelData)() {
  if (!custom_msgs__msg__AccelData__rosidl_typesupport_introspection_c__AccelData_message_type_support_handle.typesupport_identifier) {
    custom_msgs__msg__AccelData__rosidl_typesupport_introspection_c__AccelData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_msgs__msg__AccelData__rosidl_typesupport_introspection_c__AccelData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
