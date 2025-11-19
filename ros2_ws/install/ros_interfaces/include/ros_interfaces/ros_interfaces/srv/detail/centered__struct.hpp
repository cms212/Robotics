// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros_interfaces:srv/Centered.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros_interfaces/srv/centered.hpp"


#ifndef ROS_INTERFACES__SRV__DETAIL__CENTERED__STRUCT_HPP_
#define ROS_INTERFACES__SRV__DETAIL__CENTERED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros_interfaces__srv__Centered_Request __attribute__((deprecated))
#else
# define DEPRECATED__ros_interfaces__srv__Centered_Request __declspec(deprecated)
#endif

namespace ros_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Centered_Request_
{
  using Type = Centered_Request_<ContainerAllocator>;

  explicit Centered_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit Centered_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    ros_interfaces::srv::Centered_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_interfaces::srv::Centered_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_interfaces::srv::Centered_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_interfaces::srv::Centered_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_interfaces::srv::Centered_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_interfaces::srv::Centered_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_interfaces::srv::Centered_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_interfaces::srv::Centered_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_interfaces::srv::Centered_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_interfaces::srv::Centered_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_interfaces__srv__Centered_Request
    std::shared_ptr<ros_interfaces::srv::Centered_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_interfaces__srv__Centered_Request
    std::shared_ptr<ros_interfaces::srv::Centered_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Centered_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const Centered_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Centered_Request_

// alias to use template instance with default allocator
using Centered_Request =
  ros_interfaces::srv::Centered_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros_interfaces


#ifndef _WIN32
# define DEPRECATED__ros_interfaces__srv__Centered_Response __attribute__((deprecated))
#else
# define DEPRECATED__ros_interfaces__srv__Centered_Response __declspec(deprecated)
#endif

namespace ros_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Centered_Response_
{
  using Type = Centered_Response_<ContainerAllocator>;

  explicit Centered_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
    }
  }

  explicit Centered_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros_interfaces::srv::Centered_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_interfaces::srv::Centered_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_interfaces::srv::Centered_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_interfaces::srv::Centered_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_interfaces::srv::Centered_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_interfaces::srv::Centered_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_interfaces::srv::Centered_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_interfaces::srv::Centered_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_interfaces::srv::Centered_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_interfaces::srv::Centered_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_interfaces__srv__Centered_Response
    std::shared_ptr<ros_interfaces::srv::Centered_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_interfaces__srv__Centered_Response
    std::shared_ptr<ros_interfaces::srv::Centered_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Centered_Response_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    return true;
  }
  bool operator!=(const Centered_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Centered_Response_

// alias to use template instance with default allocator
using Centered_Response =
  ros_interfaces::srv::Centered_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ros_interfaces__srv__Centered_Event __attribute__((deprecated))
#else
# define DEPRECATED__ros_interfaces__srv__Centered_Event __declspec(deprecated)
#endif

namespace ros_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Centered_Event_
{
  using Type = Centered_Event_<ContainerAllocator>;

  explicit Centered_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit Centered_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<ros_interfaces::srv::Centered_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ros_interfaces::srv::Centered_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<ros_interfaces::srv::Centered_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ros_interfaces::srv::Centered_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<ros_interfaces::srv::Centered_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ros_interfaces::srv::Centered_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<ros_interfaces::srv::Centered_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ros_interfaces::srv::Centered_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros_interfaces::srv::Centered_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_interfaces::srv::Centered_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_interfaces::srv::Centered_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_interfaces::srv::Centered_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_interfaces::srv::Centered_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_interfaces::srv::Centered_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_interfaces::srv::Centered_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_interfaces::srv::Centered_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_interfaces::srv::Centered_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_interfaces::srv::Centered_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_interfaces__srv__Centered_Event
    std::shared_ptr<ros_interfaces::srv::Centered_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_interfaces__srv__Centered_Event
    std::shared_ptr<ros_interfaces::srv::Centered_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Centered_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const Centered_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Centered_Event_

// alias to use template instance with default allocator
using Centered_Event =
  ros_interfaces::srv::Centered_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros_interfaces

namespace ros_interfaces
{

namespace srv
{

struct Centered
{
  using Request = ros_interfaces::srv::Centered_Request;
  using Response = ros_interfaces::srv::Centered_Response;
  using Event = ros_interfaces::srv::Centered_Event;
};

}  // namespace srv

}  // namespace ros_interfaces

#endif  // ROS_INTERFACES__SRV__DETAIL__CENTERED__STRUCT_HPP_
