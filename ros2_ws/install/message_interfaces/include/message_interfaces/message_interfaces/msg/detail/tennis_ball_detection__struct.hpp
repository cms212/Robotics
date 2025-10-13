// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from message_interfaces:msg/TennisBallDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "message_interfaces/msg/tennis_ball_detection.hpp"


#ifndef MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_DETECTION__STRUCT_HPP_
#define MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__message_interfaces__msg__TennisBallDetection __attribute__((deprecated))
#else
# define DEPRECATED__message_interfaces__msg__TennisBallDetection __declspec(deprecated)
#endif

namespace message_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TennisBallDetection_
{
  using Type = TennisBallDetection_<ContainerAllocator>;

  explicit TennisBallDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_x = 0;
      this->right_x = 0;
      this->top_y = 0;
      this->bottom_y = 0;
    }
  }

  explicit TennisBallDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_x = 0;
      this->right_x = 0;
      this->top_y = 0;
      this->bottom_y = 0;
    }
  }

  // field types and members
  using _left_x_type =
    uint16_t;
  _left_x_type left_x;
  using _right_x_type =
    uint16_t;
  _right_x_type right_x;
  using _top_y_type =
    uint16_t;
  _top_y_type top_y;
  using _bottom_y_type =
    uint16_t;
  _bottom_y_type bottom_y;

  // setters for named parameter idiom
  Type & set__left_x(
    const uint16_t & _arg)
  {
    this->left_x = _arg;
    return *this;
  }
  Type & set__right_x(
    const uint16_t & _arg)
  {
    this->right_x = _arg;
    return *this;
  }
  Type & set__top_y(
    const uint16_t & _arg)
  {
    this->top_y = _arg;
    return *this;
  }
  Type & set__bottom_y(
    const uint16_t & _arg)
  {
    this->bottom_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    message_interfaces::msg::TennisBallDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const message_interfaces::msg::TennisBallDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<message_interfaces::msg::TennisBallDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<message_interfaces::msg::TennisBallDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      message_interfaces::msg::TennisBallDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<message_interfaces::msg::TennisBallDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      message_interfaces::msg::TennisBallDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<message_interfaces::msg::TennisBallDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<message_interfaces::msg::TennisBallDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<message_interfaces::msg::TennisBallDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__message_interfaces__msg__TennisBallDetection
    std::shared_ptr<message_interfaces::msg::TennisBallDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__message_interfaces__msg__TennisBallDetection
    std::shared_ptr<message_interfaces::msg::TennisBallDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TennisBallDetection_ & other) const
  {
    if (this->left_x != other.left_x) {
      return false;
    }
    if (this->right_x != other.right_x) {
      return false;
    }
    if (this->top_y != other.top_y) {
      return false;
    }
    if (this->bottom_y != other.bottom_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const TennisBallDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TennisBallDetection_

// alias to use template instance with default allocator
using TennisBallDetection =
  message_interfaces::msg::TennisBallDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace message_interfaces

#endif  // MESSAGE_INTERFACES__MSG__DETAIL__TENNIS_BALL_DETECTION__STRUCT_HPP_
