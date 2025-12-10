// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_interfaces:srv/ArmPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros_interfaces/srv/arm_position.hpp"


#ifndef ROS_INTERFACES__SRV__DETAIL__ARM_POSITION__TRAITS_HPP_
#define ROS_INTERFACES__SRV__DETAIL__ARM_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros_interfaces/srv/detail/arm_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ArmPosition_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: joint
  {
    out << "joint: ";
    rosidl_generator_traits::value_to_yaml(msg.joint, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArmPosition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: joint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "joint: ";
    rosidl_generator_traits::value_to_yaml(msg.joint, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArmPosition_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ros_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros_interfaces::srv::ArmPosition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros_interfaces::srv::ArmPosition_Request & msg)
{
  return ros_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros_interfaces::srv::ArmPosition_Request>()
{
  return "ros_interfaces::srv::ArmPosition_Request";
}

template<>
inline const char * name<ros_interfaces::srv::ArmPosition_Request>()
{
  return "ros_interfaces/srv/ArmPosition_Request";
}

template<>
struct has_fixed_size<ros_interfaces::srv::ArmPosition_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros_interfaces::srv::ArmPosition_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros_interfaces::srv::ArmPosition_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ros_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ArmPosition_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArmPosition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArmPosition_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ros_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros_interfaces::srv::ArmPosition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros_interfaces::srv::ArmPosition_Response & msg)
{
  return ros_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros_interfaces::srv::ArmPosition_Response>()
{
  return "ros_interfaces::srv::ArmPosition_Response";
}

template<>
inline const char * name<ros_interfaces::srv::ArmPosition_Response>()
{
  return "ros_interfaces/srv/ArmPosition_Response";
}

template<>
struct has_fixed_size<ros_interfaces::srv::ArmPosition_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros_interfaces::srv::ArmPosition_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros_interfaces::srv::ArmPosition_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace ros_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ArmPosition_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
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
  const ArmPosition_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArmPosition_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ros_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros_interfaces::srv::ArmPosition_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros_interfaces::srv::ArmPosition_Event & msg)
{
  return ros_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros_interfaces::srv::ArmPosition_Event>()
{
  return "ros_interfaces::srv::ArmPosition_Event";
}

template<>
inline const char * name<ros_interfaces::srv::ArmPosition_Event>()
{
  return "ros_interfaces/srv/ArmPosition_Event";
}

template<>
struct has_fixed_size<ros_interfaces::srv::ArmPosition_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros_interfaces::srv::ArmPosition_Event>
  : std::integral_constant<bool, has_bounded_size<ros_interfaces::srv::ArmPosition_Request>::value && has_bounded_size<ros_interfaces::srv::ArmPosition_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<ros_interfaces::srv::ArmPosition_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros_interfaces::srv::ArmPosition>()
{
  return "ros_interfaces::srv::ArmPosition";
}

template<>
inline const char * name<ros_interfaces::srv::ArmPosition>()
{
  return "ros_interfaces/srv/ArmPosition";
}

template<>
struct has_fixed_size<ros_interfaces::srv::ArmPosition>
  : std::integral_constant<
    bool,
    has_fixed_size<ros_interfaces::srv::ArmPosition_Request>::value &&
    has_fixed_size<ros_interfaces::srv::ArmPosition_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros_interfaces::srv::ArmPosition>
  : std::integral_constant<
    bool,
    has_bounded_size<ros_interfaces::srv::ArmPosition_Request>::value &&
    has_bounded_size<ros_interfaces::srv::ArmPosition_Response>::value
  >
{
};

template<>
struct is_service<ros_interfaces::srv::ArmPosition>
  : std::true_type
{
};

template<>
struct is_service_request<ros_interfaces::srv::ArmPosition_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros_interfaces::srv::ArmPosition_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS_INTERFACES__SRV__DETAIL__ARM_POSITION__TRAITS_HPP_
