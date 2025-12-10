// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros_interfaces:srv/ArmService.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros_interfaces/srv/arm_service.hpp"


#ifndef ROS_INTERFACES__SRV__DETAIL__ARM_SERVICE__BUILDER_HPP_
#define ROS_INTERFACES__SRV__DETAIL__ARM_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros_interfaces/srv/detail/arm_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros_interfaces
{

namespace srv
{

namespace builder
{

class Init_ArmService_Request_joint_pos
{
public:
  explicit Init_ArmService_Request_joint_pos(::ros_interfaces::srv::ArmService_Request & msg)
  : msg_(msg)
  {}
  ::ros_interfaces::srv::ArmService_Request joint_pos(::ros_interfaces::srv::ArmService_Request::_joint_pos_type arg)
  {
    msg_.joint_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_interfaces::srv::ArmService_Request msg_;
};

class Init_ArmService_Request_joint
{
public:
  Init_ArmService_Request_joint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmService_Request_joint_pos joint(::ros_interfaces::srv::ArmService_Request::_joint_type arg)
  {
    msg_.joint = std::move(arg);
    return Init_ArmService_Request_joint_pos(msg_);
  }

private:
  ::ros_interfaces::srv::ArmService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_interfaces::srv::ArmService_Request>()
{
  return ros_interfaces::srv::builder::Init_ArmService_Request_joint();
}

}  // namespace ros_interfaces


namespace ros_interfaces
{

namespace srv
{

namespace builder
{

class Init_ArmService_Response_result
{
public:
  Init_ArmService_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros_interfaces::srv::ArmService_Response result(::ros_interfaces::srv::ArmService_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_interfaces::srv::ArmService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_interfaces::srv::ArmService_Response>()
{
  return ros_interfaces::srv::builder::Init_ArmService_Response_result();
}

}  // namespace ros_interfaces


namespace ros_interfaces
{

namespace srv
{

namespace builder
{

class Init_ArmService_Event_response
{
public:
  explicit Init_ArmService_Event_response(::ros_interfaces::srv::ArmService_Event & msg)
  : msg_(msg)
  {}
  ::ros_interfaces::srv::ArmService_Event response(::ros_interfaces::srv::ArmService_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_interfaces::srv::ArmService_Event msg_;
};

class Init_ArmService_Event_request
{
public:
  explicit Init_ArmService_Event_request(::ros_interfaces::srv::ArmService_Event & msg)
  : msg_(msg)
  {}
  Init_ArmService_Event_response request(::ros_interfaces::srv::ArmService_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ArmService_Event_response(msg_);
  }

private:
  ::ros_interfaces::srv::ArmService_Event msg_;
};

class Init_ArmService_Event_info
{
public:
  Init_ArmService_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmService_Event_request info(::ros_interfaces::srv::ArmService_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ArmService_Event_request(msg_);
  }

private:
  ::ros_interfaces::srv::ArmService_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_interfaces::srv::ArmService_Event>()
{
  return ros_interfaces::srv::builder::Init_ArmService_Event_info();
}

}  // namespace ros_interfaces

#endif  // ROS_INTERFACES__SRV__DETAIL__ARM_SERVICE__BUILDER_HPP_
