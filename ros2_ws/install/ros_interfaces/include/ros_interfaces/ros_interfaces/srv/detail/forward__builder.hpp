// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros_interfaces:srv/Forward.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros_interfaces/srv/forward.hpp"


#ifndef ROS_INTERFACES__SRV__DETAIL__FORWARD__BUILDER_HPP_
#define ROS_INTERFACES__SRV__DETAIL__FORWARD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros_interfaces/srv/detail/forward__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_interfaces::srv::Forward_Request>()
{
  return ::ros_interfaces::srv::Forward_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace ros_interfaces


namespace ros_interfaces
{

namespace srv
{

namespace builder
{

class Init_Forward_Response_z
{
public:
  Init_Forward_Response_z()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros_interfaces::srv::Forward_Response z(::ros_interfaces::srv::Forward_Response::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_interfaces::srv::Forward_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_interfaces::srv::Forward_Response>()
{
  return ros_interfaces::srv::builder::Init_Forward_Response_z();
}

}  // namespace ros_interfaces


namespace ros_interfaces
{

namespace srv
{

namespace builder
{

class Init_Forward_Event_response
{
public:
  explicit Init_Forward_Event_response(::ros_interfaces::srv::Forward_Event & msg)
  : msg_(msg)
  {}
  ::ros_interfaces::srv::Forward_Event response(::ros_interfaces::srv::Forward_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_interfaces::srv::Forward_Event msg_;
};

class Init_Forward_Event_request
{
public:
  explicit Init_Forward_Event_request(::ros_interfaces::srv::Forward_Event & msg)
  : msg_(msg)
  {}
  Init_Forward_Event_response request(::ros_interfaces::srv::Forward_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Forward_Event_response(msg_);
  }

private:
  ::ros_interfaces::srv::Forward_Event msg_;
};

class Init_Forward_Event_info
{
public:
  Init_Forward_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Forward_Event_request info(::ros_interfaces::srv::Forward_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Forward_Event_request(msg_);
  }

private:
  ::ros_interfaces::srv::Forward_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_interfaces::srv::Forward_Event>()
{
  return ros_interfaces::srv::builder::Init_Forward_Event_info();
}

}  // namespace ros_interfaces

#endif  // ROS_INTERFACES__SRV__DETAIL__FORWARD__BUILDER_HPP_
