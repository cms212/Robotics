// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from message_interfaces:msg/ArduinoCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "message_interfaces/msg/arduino_command.hpp"


#ifndef MESSAGE_INTERFACES__MSG__DETAIL__ARDUINO_COMMAND__TRAITS_HPP_
#define MESSAGE_INTERFACES__MSG__DETAIL__ARDUINO_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "message_interfaces/msg/detail/arduino_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace message_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ArduinoCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: arduino_command
  {
    out << "arduino_command: ";
    rosidl_generator_traits::value_to_yaml(msg.arduino_command, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArduinoCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: arduino_command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arduino_command: ";
    rosidl_generator_traits::value_to_yaml(msg.arduino_command, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArduinoCommand & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace message_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use message_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const message_interfaces::msg::ArduinoCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  message_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use message_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const message_interfaces::msg::ArduinoCommand & msg)
{
  return message_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<message_interfaces::msg::ArduinoCommand>()
{
  return "message_interfaces::msg::ArduinoCommand";
}

template<>
inline const char * name<message_interfaces::msg::ArduinoCommand>()
{
  return "message_interfaces/msg/ArduinoCommand";
}

template<>
struct has_fixed_size<message_interfaces::msg::ArduinoCommand>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<message_interfaces::msg::ArduinoCommand>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<message_interfaces::msg::ArduinoCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGE_INTERFACES__MSG__DETAIL__ARDUINO_COMMAND__TRAITS_HPP_
