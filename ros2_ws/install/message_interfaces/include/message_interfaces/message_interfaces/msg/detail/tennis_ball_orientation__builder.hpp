// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from message_interfaces:msg/TennisBallOrientation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "message_interfaces/msg/tennis_ball_orientation.hpp"


#ifndef MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_ORIENTATION__BUILDER_HPP_
#define MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_ORIENTATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "message_interfaces/msg/detail/tennis_ball_orientation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace message_interfaces
{

namespace msg
{

namespace builder
{

class Init_TennisBallOrientation_z
{
public:
  explicit Init_TennisBallOrientation_z(::message_interfaces::msg::TennisBallOrientation & msg)
  : msg_(msg)
  {}
  ::message_interfaces::msg::TennisBallOrientation z(::message_interfaces::msg::TennisBallOrientation::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::message_interfaces::msg::TennisBallOrientation msg_;
};

class Init_TennisBallOrientation_y
{
public:
  explicit Init_TennisBallOrientation_y(::message_interfaces::msg::TennisBallOrientation & msg)
  : msg_(msg)
  {}
  Init_TennisBallOrientation_z y(::message_interfaces::msg::TennisBallOrientation::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_TennisBallOrientation_z(msg_);
  }

private:
  ::message_interfaces::msg::TennisBallOrientation msg_;
};

class Init_TennisBallOrientation_x
{
public:
  Init_TennisBallOrientation_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TennisBallOrientation_y x(::message_interfaces::msg::TennisBallOrientation::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_TennisBallOrientation_y(msg_);
  }

private:
  ::message_interfaces::msg::TennisBallOrientation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::message_interfaces::msg::TennisBallOrientation>()
{
  return message_interfaces::msg::builder::Init_TennisBallOrientation_x();
}

}  // namespace message_interfaces

#endif  // MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_ORIENTATION__BUILDER_HPP_
