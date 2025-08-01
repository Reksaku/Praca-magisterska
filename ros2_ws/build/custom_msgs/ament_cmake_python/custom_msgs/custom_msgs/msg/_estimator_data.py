# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_msgs:msg/EstimatorData.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EstimatorData(type):
    """Metaclass of message 'EstimatorData'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_msgs.msg.EstimatorData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__estimator_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__estimator_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__estimator_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__estimator_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__estimator_data

            from custom_msgs.msg import DataXYZ
            if DataXYZ.__class__._TYPE_SUPPORT is None:
                DataXYZ.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EstimatorData(metaclass=Metaclass_EstimatorData):
    """Message class 'EstimatorData'."""

    __slots__ = [
        '_timestamp',
        '_possition',
        '_speed',
        '_accel',
        '_orientation',
        '_raw_data',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'timestamp': 'int64',
        'possition': 'custom_msgs/DataXYZ',
        'speed': 'custom_msgs/DataXYZ',
        'accel': 'custom_msgs/DataXYZ',
        'orientation': 'custom_msgs/DataXYZ',
        'raw_data': 'custom_msgs/DataXYZ',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['custom_msgs', 'msg'], 'DataXYZ'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['custom_msgs', 'msg'], 'DataXYZ'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['custom_msgs', 'msg'], 'DataXYZ'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['custom_msgs', 'msg'], 'DataXYZ'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['custom_msgs', 'msg'], 'DataXYZ'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.timestamp = kwargs.get('timestamp', int())
        from custom_msgs.msg import DataXYZ
        self.possition = kwargs.get('possition', DataXYZ())
        from custom_msgs.msg import DataXYZ
        self.speed = kwargs.get('speed', DataXYZ())
        from custom_msgs.msg import DataXYZ
        self.accel = kwargs.get('accel', DataXYZ())
        from custom_msgs.msg import DataXYZ
        self.orientation = kwargs.get('orientation', DataXYZ())
        from custom_msgs.msg import DataXYZ
        self.raw_data = kwargs.get('raw_data', DataXYZ())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.timestamp != other.timestamp:
            return False
        if self.possition != other.possition:
            return False
        if self.speed != other.speed:
            return False
        if self.accel != other.accel:
            return False
        if self.orientation != other.orientation:
            return False
        if self.raw_data != other.raw_data:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'timestamp' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'timestamp' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._timestamp = value

    @builtins.property
    def possition(self):
        """Message field 'possition'."""
        return self._possition

    @possition.setter
    def possition(self, value):
        if self._check_fields:
            from custom_msgs.msg import DataXYZ
            assert \
                isinstance(value, DataXYZ), \
                "The 'possition' field must be a sub message of type 'DataXYZ'"
        self._possition = value

    @builtins.property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if self._check_fields:
            from custom_msgs.msg import DataXYZ
            assert \
                isinstance(value, DataXYZ), \
                "The 'speed' field must be a sub message of type 'DataXYZ'"
        self._speed = value

    @builtins.property
    def accel(self):
        """Message field 'accel'."""
        return self._accel

    @accel.setter
    def accel(self, value):
        if self._check_fields:
            from custom_msgs.msg import DataXYZ
            assert \
                isinstance(value, DataXYZ), \
                "The 'accel' field must be a sub message of type 'DataXYZ'"
        self._accel = value

    @builtins.property
    def orientation(self):
        """Message field 'orientation'."""
        return self._orientation

    @orientation.setter
    def orientation(self, value):
        if self._check_fields:
            from custom_msgs.msg import DataXYZ
            assert \
                isinstance(value, DataXYZ), \
                "The 'orientation' field must be a sub message of type 'DataXYZ'"
        self._orientation = value

    @builtins.property
    def raw_data(self):
        """Message field 'raw_data'."""
        return self._raw_data

    @raw_data.setter
    def raw_data(self, value):
        if self._check_fields:
            from custom_msgs.msg import DataXYZ
            assert \
                isinstance(value, DataXYZ), \
                "The 'raw_data' field must be a sub message of type 'DataXYZ'"
        self._raw_data = value
