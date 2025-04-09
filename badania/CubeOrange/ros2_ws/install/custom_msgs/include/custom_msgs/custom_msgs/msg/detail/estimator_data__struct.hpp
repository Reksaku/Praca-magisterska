// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/EstimatorData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/estimator_data.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__ESTIMATOR_DATA__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__ESTIMATOR_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'possition'
#include "custom_msgs/msg/detail/possition_data__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__EstimatorData __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__EstimatorData __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EstimatorData_
{
  using Type = EstimatorData_<ContainerAllocator>;

  explicit EstimatorData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : possition(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp = 0ll;
    }
  }

  explicit EstimatorData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : possition(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp = 0ll;
    }
  }

  // field types and members
  using _timestamp_type =
    int64_t;
  _timestamp_type timestamp;
  using _possition_type =
    custom_msgs::msg::PossitionData_<ContainerAllocator>;
  _possition_type possition;

  // setters for named parameter idiom
  Type & set__timestamp(
    const int64_t & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__possition(
    const custom_msgs::msg::PossitionData_<ContainerAllocator> & _arg)
  {
    this->possition = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::EstimatorData_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::EstimatorData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::EstimatorData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::EstimatorData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::EstimatorData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::EstimatorData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::EstimatorData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::EstimatorData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::EstimatorData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::EstimatorData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__EstimatorData
    std::shared_ptr<custom_msgs::msg::EstimatorData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__EstimatorData
    std::shared_ptr<custom_msgs::msg::EstimatorData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EstimatorData_ & other) const
  {
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->possition != other.possition) {
      return false;
    }
    return true;
  }
  bool operator!=(const EstimatorData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EstimatorData_

// alias to use template instance with default allocator
using EstimatorData =
  custom_msgs::msg::EstimatorData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__ESTIMATOR_DATA__STRUCT_HPP_
