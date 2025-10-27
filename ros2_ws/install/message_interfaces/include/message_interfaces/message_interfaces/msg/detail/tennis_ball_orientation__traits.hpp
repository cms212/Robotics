// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from message_interfaces:msg/TennisBallOrientation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "message_interfaces/msg/tennis_ball_orientation.hpp"


#ifndef MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_ORIENTATION__TRAITS_HPP_
#define MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_ORIENTATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "message_interfaces/msg/detail/tennis_ball_orientation__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace message_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TennisBallOrientation & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TennisBallOrientation & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TennisBallOrientation & msg, bool use_flow_style = false)
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
  const message_interfaces::msg::TennisBallOrientation & msg,
  std::ostream & out, size_t indentation = 0)
{
  message_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use message_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const message_interfaces::msg::TennisBallOrientation & msg)
{
  return message_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<message_interfaces::msg::TennisBallOrientation>()
{
  return "message_interfaces::msg::TennisBallOrientation";
}

template<>
inline const char * name<message_interfaces::msg::TennisBallOrientation>()
{
  return "message_interfaces/msg/TennisBallOrientation";
}

template<>
struct has_fixed_size<message_interfaces::msg::TennisBallOrientation>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<message_interfaces::msg::TennisBallOrientation>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<message_interfaces::msg::TennisBallOrientation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_ORIENTATION__TRAITS_HPP_
