// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from message_interfaces:msg/ArduinoCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "message_interfaces/msg/arduino_command.hpp"


#ifndef MESSAGE_INTERFACES__MSG__DETAIL__ARDUINO_COMMAND__BUILDER_HPP_
#define MESSAGE_INTERFACES__MSG__DETAIL__ARDUINO_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "message_interfaces/msg/detail/arduino_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace message_interfaces
{

namespace msg
{

namespace builder
{

class Init_ArduinoCommand_arduino_command
{
public:
  Init_ArduinoCommand_arduino_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::message_interfaces::msg::ArduinoCommand arduino_command(::message_interfaces::msg::ArduinoCommand::_arduino_command_type arg)
  {
    msg_.arduino_command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::message_interfaces::msg::ArduinoCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::message_interfaces::msg::ArduinoCommand>()
{
  return message_interfaces::msg::builder::Init_ArduinoCommand_arduino_command();
}

}  // namespace message_interfaces

#endif  // MESSAGE_INTERFACES__MSG__DETAIL__ARDUINO_COMMAND__BUILDER_HPP_
