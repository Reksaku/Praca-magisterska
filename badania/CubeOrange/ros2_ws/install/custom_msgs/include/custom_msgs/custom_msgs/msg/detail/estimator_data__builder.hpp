// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/EstimatorData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/estimator_data.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__ESTIMATOR_DATA__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__ESTIMATOR_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/estimator_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_EstimatorData_possition
{
public:
  explicit Init_EstimatorData_possition(::custom_msgs::msg::EstimatorData & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::EstimatorData possition(::custom_msgs::msg::EstimatorData::_possition_type arg)
  {
    msg_.possition = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::EstimatorData msg_;
};

class Init_EstimatorData_timestamp
{
public:
  Init_EstimatorData_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EstimatorData_possition timestamp(::custom_msgs::msg::EstimatorData::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_EstimatorData_possition(msg_);
  }

private:
  ::custom_msgs::msg::EstimatorData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::EstimatorData>()
{
  return custom_msgs::msg::builder::Init_EstimatorData_timestamp();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__ESTIMATOR_DATA__BUILDER_HPP_
