// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from message_interfaces:msg/TennisBallDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "message_interfaces/msg/tennis_ball_detection.hpp"


#ifndef MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_DETECTION__BUILDER_HPP_
#define MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "message_interfaces/msg/detail/tennis_ball_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace message_interfaces
{

namespace msg
{

namespace builder
{

class Init_TennisBallDetection_bottom_y
{
public:
  explicit Init_TennisBallDetection_bottom_y(::message_interfaces::msg::TennisBallDetection & msg)
  : msg_(msg)
  {}
  ::message_interfaces::msg::TennisBallDetection bottom_y(::message_interfaces::msg::TennisBallDetection::_bottom_y_type arg)
  {
    msg_.bottom_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::message_interfaces::msg::TennisBallDetection msg_;
};

class Init_TennisBallDetection_top_y
{
public:
  explicit Init_TennisBallDetection_top_y(::message_interfaces::msg::TennisBallDetection & msg)
  : msg_(msg)
  {}
  Init_TennisBallDetection_bottom_y top_y(::message_interfaces::msg::TennisBallDetection::_top_y_type arg)
  {
    msg_.top_y = std::move(arg);
    return Init_TennisBallDetection_bottom_y(msg_);
  }

private:
  ::message_interfaces::msg::TennisBallDetection msg_;
};

class Init_TennisBallDetection_right_x
{
public:
  explicit Init_TennisBallDetection_right_x(::message_interfaces::msg::TennisBallDetection & msg)
  : msg_(msg)
  {}
  Init_TennisBallDetection_top_y right_x(::message_interfaces::msg::TennisBallDetection::_right_x_type arg)
  {
    msg_.right_x = std::move(arg);
    return Init_TennisBallDetection_top_y(msg_);
  }

private:
  ::message_interfaces::msg::TennisBallDetection msg_;
};

class Init_TennisBallDetection_left_x
{
public:
  Init_TennisBallDetection_left_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TennisBallDetection_right_x left_x(::message_interfaces::msg::TennisBallDetection::_left_x_type arg)
  {
    msg_.left_x = std::move(arg);
    return Init_TennisBallDetection_right_x(msg_);
  }

private:
  ::message_interfaces::msg::TennisBallDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::message_interfaces::msg::TennisBallDetection>()
{
  return message_interfaces::msg::builder::Init_TennisBallDetection_left_x();
}

}  // namespace message_interfaces

#endif  // MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_DETECTION__BUILDER_HPP_
