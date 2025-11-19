// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros_interfaces:srv/Centered.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros_interfaces/srv/centered.hpp"


#ifndef ROS_INTERFACES__SRV__DETAIL__CENTERED__BUILDER_HPP_
#define ROS_INTERFACES__SRV__DETAIL__CENTERED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros_interfaces/srv/detail/centered__struct.hpp"
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
auto build<::ros_interfaces::srv::Centered_Request>()
{
  return ::ros_interfaces::srv::Centered_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace ros_interfaces


namespace ros_interfaces
{

namespace srv
{

namespace builder
{

class Init_Centered_Response_x
{
public:
  Init_Centered_Response_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros_interfaces::srv::Centered_Response x(::ros_interfaces::srv::Centered_Response::_x_type arg)
  {
    msg_.x = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_interfaces::srv::Centered_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_interfaces::srv::Centered_Response>()
{
  return ros_interfaces::srv::builder::Init_Centered_Response_x();
}

}  // namespace ros_interfaces


namespace ros_interfaces
{

namespace srv
{

namespace builder
{

class Init_Centered_Event_response
{
public:
  explicit Init_Centered_Event_response(::ros_interfaces::srv::Centered_Event & msg)
  : msg_(msg)
  {}
  ::ros_interfaces::srv::Centered_Event response(::ros_interfaces::srv::Centered_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_interfaces::srv::Centered_Event msg_;
};

class Init_Centered_Event_request
{
public:
  explicit Init_Centered_Event_request(::ros_interfaces::srv::Centered_Event & msg)
  : msg_(msg)
  {}
  Init_Centered_Event_response request(::ros_interfaces::srv::Centered_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Centered_Event_response(msg_);
  }

private:
  ::ros_interfaces::srv::Centered_Event msg_;
};

class Init_Centered_Event_info
{
public:
  Init_Centered_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Centered_Event_request info(::ros_interfaces::srv::Centered_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Centered_Event_request(msg_);
  }

private:
  ::ros_interfaces::srv::Centered_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_interfaces::srv::Centered_Event>()
{
  return ros_interfaces::srv::builder::Init_Centered_Event_info();
}

}  // namespace ros_interfaces

#endif  // ROS_INTERFACES__SRV__DETAIL__CENTERED__BUILDER_HPP_
