// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from message_interfaces:msg/ArmPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "message_interfaces/msg/arm_position.hpp"


#ifndef MESSAGE_INTERFACES__MSG__DETAIL__ARM_POSITION__TRAITS_HPP_
#define MESSAGE_INTERFACES__MSG__DETAIL__ARM_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "message_interfaces/msg/detail/arm_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace message_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ArmPosition & msg,
  std::ostream & out)
{
  out << "{";
  // member: arm_positions
  {
    if (msg.arm_positions.size() == 0) {
      out << "arm_positions: []";
    } else {
      out << "arm_positions: [";
      size_t pending_items = msg.arm_positions.size();
      for (auto item : msg.arm_positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArmPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: arm_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.arm_positions.size() == 0) {
      out << "arm_positions: []\n";
    } else {
      out << "arm_positions:\n";
      for (auto item : msg.arm_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArmPosition & msg, bool use_flow_style = false)
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
  const message_interfaces::msg::ArmPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  message_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use message_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const message_interfaces::msg::ArmPosition & msg)
{
  return message_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<message_interfaces::msg::ArmPosition>()
{
  return "message_interfaces::msg::ArmPosition";
}

template<>
inline const char * name<message_interfaces::msg::ArmPosition>()
{
  return "message_interfaces/msg/ArmPosition";
}

template<>
struct has_fixed_size<message_interfaces::msg::ArmPosition>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<message_interfaces::msg::ArmPosition>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<message_interfaces::msg::ArmPosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGE_INTERFACES__MSG__DETAIL__ARM_POSITION__TRAITS_HPP_
