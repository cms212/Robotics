// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from message_interfaces:msg/ArduinoCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "message_interfaces/msg/arduino_command.hpp"


#ifndef MESSAGE_INTERFACES__MSG__DETAIL__ARDUINO_COMMAND__STRUCT_HPP_
#define MESSAGE_INTERFACES__MSG__DETAIL__ARDUINO_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__message_interfaces__msg__ArduinoCommand __attribute__((deprecated))
#else
# define DEPRECATED__message_interfaces__msg__ArduinoCommand __declspec(deprecated)
#endif

namespace message_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArduinoCommand_
{
  using Type = ArduinoCommand_<ContainerAllocator>;

  explicit ArduinoCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->arduino_command = "";
    }
  }

  explicit ArduinoCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : arduino_command(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->arduino_command = "";
    }
  }

  // field types and members
  using _arduino_command_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _arduino_command_type arduino_command;

  // setters for named parameter idiom
  Type & set__arduino_command(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->arduino_command = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    message_interfaces::msg::ArduinoCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const message_interfaces::msg::ArduinoCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<message_interfaces::msg::ArduinoCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<message_interfaces::msg::ArduinoCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      message_interfaces::msg::ArduinoCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<message_interfaces::msg::ArduinoCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      message_interfaces::msg::ArduinoCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<message_interfaces::msg::ArduinoCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<message_interfaces::msg::ArduinoCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<message_interfaces::msg::ArduinoCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__message_interfaces__msg__ArduinoCommand
    std::shared_ptr<message_interfaces::msg::ArduinoCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__message_interfaces__msg__ArduinoCommand
    std::shared_ptr<message_interfaces::msg::ArduinoCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArduinoCommand_ & other) const
  {
    if (this->arduino_command != other.arduino_command) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArduinoCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArduinoCommand_

// alias to use template instance with default allocator
using ArduinoCommand =
  message_interfaces::msg::ArduinoCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace message_interfaces

#endif  // MESSAGE_INTERFACES__MSG__DETAIL__ARDUINO_COMMAND__STRUCT_HPP_
