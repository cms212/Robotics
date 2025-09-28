// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from message_interfaces:msg/ArmPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "message_interfaces/msg/arm_position.hpp"


#ifndef MESSAGE_INTERFACES__MSG__DETAIL__ARM_POSITION__BUILDER_HPP_
#define MESSAGE_INTERFACES__MSG__DETAIL__ARM_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "message_interfaces/msg/detail/arm_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace message_interfaces
{

namespace msg
{

namespace builder
{

class Init_ArmPosition_arm_positions
{
public:
  Init_ArmPosition_arm_positions()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::message_interfaces::msg::ArmPosition arm_positions(::message_interfaces::msg::ArmPosition::_arm_positions_type arg)
  {
    msg_.arm_positions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::message_interfaces::msg::ArmPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::message_interfaces::msg::ArmPosition>()
{
  return message_interfaces::msg::builder::Init_ArmPosition_arm_positions();
}

}  // namespace message_interfaces

#endif  // MESSAGE_INTERFACES__MSG__DETAIL__ARM_POSITION__BUILDER_HPP_
