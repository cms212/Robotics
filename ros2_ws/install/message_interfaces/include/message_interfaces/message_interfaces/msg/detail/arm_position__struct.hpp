// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from message_interfaces:msg/ArmPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "message_interfaces/msg/arm_position.hpp"


#ifndef MESSAGE_INTERFACES__MSG__DETAIL__ARM_POSITION__STRUCT_HPP_
#define MESSAGE_INTERFACES__MSG__DETAIL__ARM_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__message_interfaces__msg__ArmPosition __attribute__((deprecated))
#else
# define DEPRECATED__message_interfaces__msg__ArmPosition __declspec(deprecated)
#endif

namespace message_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArmPosition_
{
  using Type = ArmPosition_<ContainerAllocator>;

  explicit ArmPosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit ArmPosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _arm_positions_type =
    std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>>;
  _arm_positions_type arm_positions;

  // setters for named parameter idiom
  Type & set__arm_positions(
    const std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> & _arg)
  {
    this->arm_positions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    message_interfaces::msg::ArmPosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const message_interfaces::msg::ArmPosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<message_interfaces::msg::ArmPosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<message_interfaces::msg::ArmPosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      message_interfaces::msg::ArmPosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<message_interfaces::msg::ArmPosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      message_interfaces::msg::ArmPosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<message_interfaces::msg::ArmPosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<message_interfaces::msg::ArmPosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<message_interfaces::msg::ArmPosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__message_interfaces__msg__ArmPosition
    std::shared_ptr<message_interfaces::msg::ArmPosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__message_interfaces__msg__ArmPosition
    std::shared_ptr<message_interfaces::msg::ArmPosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmPosition_ & other) const
  {
    if (this->arm_positions != other.arm_positions) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmPosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmPosition_

// alias to use template instance with default allocator
using ArmPosition =
  message_interfaces::msg::ArmPosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace message_interfaces

#endif  // MESSAGE_INTERFACES__MSG__DETAIL__ARM_POSITION__STRUCT_HPP_
