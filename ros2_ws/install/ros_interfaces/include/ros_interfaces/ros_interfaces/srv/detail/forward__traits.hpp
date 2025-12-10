// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_interfaces:srv/Forward.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros_interfaces/srv/forward.hpp"


#ifndef ROS_INTERFACES__SRV__DETAIL__FORWARD__TRAITS_HPP_
#define ROS_INTERFACES__SRV__DETAIL__FORWARD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros_interfaces/srv/detail/forward__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Forward_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Forward_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Forward_Request & msg, bool use_flow_style = false)
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
  const ros_interfaces::srv::Forward_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros_interfaces::srv::Forward_Request & msg)
{
  return ros_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros_interfaces::srv::Forward_Request>()
{
  return "ros_interfaces::srv::Forward_Request";
}

template<>
inline const char * name<ros_interfaces::srv::Forward_Request>()
{
  return "ros_interfaces/srv/Forward_Request";
}

template<>
struct has_fixed_size<ros_interfaces::srv::Forward_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros_interfaces::srv::Forward_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros_interfaces::srv::Forward_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ros_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Forward_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Forward_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
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

inline std::string to_yaml(const Forward_Response & msg, bool use_flow_style = false)
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
  const ros_interfaces::srv::Forward_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros_interfaces::srv::Forward_Response & msg)
{
  return ros_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros_interfaces::srv::Forward_Response>()
{
  return "ros_interfaces::srv::Forward_Response";
}

template<>
inline const char * name<ros_interfaces::srv::Forward_Response>()
{
  return "ros_interfaces/srv/Forward_Response";
}

template<>
struct has_fixed_size<ros_interfaces::srv::Forward_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros_interfaces::srv::Forward_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros_interfaces::srv::Forward_Response>
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
  const Forward_Event & msg,
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
  const Forward_Event & msg,
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

inline std::string to_yaml(const Forward_Event & msg, bool use_flow_style = false)
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
  const ros_interfaces::srv::Forward_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros_interfaces::srv::Forward_Event & msg)
{
  return ros_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros_interfaces::srv::Forward_Event>()
{
  return "ros_interfaces::srv::Forward_Event";
}

template<>
inline const char * name<ros_interfaces::srv::Forward_Event>()
{
  return "ros_interfaces/srv/Forward_Event";
}

template<>
struct has_fixed_size<ros_interfaces::srv::Forward_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros_interfaces::srv::Forward_Event>
  : std::integral_constant<bool, has_bounded_size<ros_interfaces::srv::Forward_Request>::value && has_bounded_size<ros_interfaces::srv::Forward_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<ros_interfaces::srv::Forward_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros_interfaces::srv::Forward>()
{
  return "ros_interfaces::srv::Forward";
}

template<>
inline const char * name<ros_interfaces::srv::Forward>()
{
  return "ros_interfaces/srv/Forward";
}

template<>
struct has_fixed_size<ros_interfaces::srv::Forward>
  : std::integral_constant<
    bool,
    has_fixed_size<ros_interfaces::srv::Forward_Request>::value &&
    has_fixed_size<ros_interfaces::srv::Forward_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros_interfaces::srv::Forward>
  : std::integral_constant<
    bool,
    has_bounded_size<ros_interfaces::srv::Forward_Request>::value &&
    has_bounded_size<ros_interfaces::srv::Forward_Response>::value
  >
{
};

template<>
struct is_service<ros_interfaces::srv::Forward>
  : std::true_type
{
};

template<>
struct is_service_request<ros_interfaces::srv::Forward_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros_interfaces::srv::Forward_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS_INTERFACES__SRV__DETAIL__FORWARD__TRAITS_HPP_
