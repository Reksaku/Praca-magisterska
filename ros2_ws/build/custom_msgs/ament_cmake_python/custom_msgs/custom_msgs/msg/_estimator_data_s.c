// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from custom_msgs:msg/EstimatorData.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "custom_msgs/msg/detail/estimator_data__struct.h"
#include "custom_msgs/msg/detail/estimator_data__functions.h"

bool custom_msgs__msg__data_xyz__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * custom_msgs__msg__data_xyz__convert_to_py(void * raw_ros_message);
bool custom_msgs__msg__data_xyz__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * custom_msgs__msg__data_xyz__convert_to_py(void * raw_ros_message);
bool custom_msgs__msg__data_xyz__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * custom_msgs__msg__data_xyz__convert_to_py(void * raw_ros_message);
bool custom_msgs__msg__data_xyz__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * custom_msgs__msg__data_xyz__convert_to_py(void * raw_ros_message);
bool custom_msgs__msg__data_xyz__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * custom_msgs__msg__data_xyz__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool custom_msgs__msg__estimator_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("custom_msgs.msg._estimator_data.EstimatorData", full_classname_dest, 45) == 0);
  }
  custom_msgs__msg__EstimatorData * ros_message = _ros_message;
  {  // timestamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "timestamp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->timestamp = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // possition
    PyObject * field = PyObject_GetAttrString(_pymsg, "possition");
    if (!field) {
      return false;
    }
    if (!custom_msgs__msg__data_xyz__convert_from_py(field, &ros_message->possition)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed");
    if (!field) {
      return false;
    }
    if (!custom_msgs__msg__data_xyz__convert_from_py(field, &ros_message->speed)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // accel
    PyObject * field = PyObject_GetAttrString(_pymsg, "accel");
    if (!field) {
      return false;
    }
    if (!custom_msgs__msg__data_xyz__convert_from_py(field, &ros_message->accel)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // orientation
    PyObject * field = PyObject_GetAttrString(_pymsg, "orientation");
    if (!field) {
      return false;
    }
    if (!custom_msgs__msg__data_xyz__convert_from_py(field, &ros_message->orientation)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // raw_data
    PyObject * field = PyObject_GetAttrString(_pymsg, "raw_data");
    if (!field) {
      return false;
    }
    if (!custom_msgs__msg__data_xyz__convert_from_py(field, &ros_message->raw_data)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * custom_msgs__msg__estimator_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of EstimatorData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("custom_msgs.msg._estimator_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "EstimatorData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  custom_msgs__msg__EstimatorData * ros_message = (custom_msgs__msg__EstimatorData *)raw_ros_message;
  {  // timestamp
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->timestamp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "timestamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // possition
    PyObject * field = NULL;
    field = custom_msgs__msg__data_xyz__convert_to_py(&ros_message->possition);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "possition", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed
    PyObject * field = NULL;
    field = custom_msgs__msg__data_xyz__convert_to_py(&ros_message->speed);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // accel
    PyObject * field = NULL;
    field = custom_msgs__msg__data_xyz__convert_to_py(&ros_message->accel);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "accel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orientation
    PyObject * field = NULL;
    field = custom_msgs__msg__data_xyz__convert_to_py(&ros_message->orientation);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "orientation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // raw_data
    PyObject * field = NULL;
    field = custom_msgs__msg__data_xyz__convert_to_py(&ros_message->raw_data);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "raw_data", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
