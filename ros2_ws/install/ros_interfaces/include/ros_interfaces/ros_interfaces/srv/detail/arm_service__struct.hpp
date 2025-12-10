// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros_interfaces:srv/ArmService.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros_interfaces/srv/arm_service.hpp"


#ifndef ROS_INTERFACES__SRV__DETAIL__ARM_SERVICE__STRUCT_HPP_
#define ROS_INTERFACES__SRV__DETAIL__ARM_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros_interfaces__srv__ArmService_Request __attribute__((deprecated))
#else
# define DEPRECATED__ros_interfaces__srv__ArmService_Request __declspec(deprecated)
#endif

namespace ros_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ArmService_Request_
{
  using Type = ArmService_Request_<ContainerAllocator>;

  explicit ArmService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->joint = 0ul;
      this->joint_pos = 0ul;
    }
  }

  explicit ArmService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->joint = 0ul;
      this->joint_pos = 0ul;
    }
  }

  // field types and members
  using _joint_type =
    uint32_t;
  _joint_type joint;
  using _joint_pos_type =
    uint32_t;
  _joint_pos_type joint_pos;

  // setters for named parameter idiom
  Type & set__joint(
    const uint32_t & _arg)
  {
    this->joint = _arg;
    return *this;
  }
  Type & set__joint_pos(
    const uint32_t & _arg)
  {
    this->joint_pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros_interfaces::srv::ArmService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_interfaces::srv::ArmService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_interfaces::srv::ArmService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_interfaces::srv::ArmService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_interfaces::srv::ArmService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_interfaces::srv::ArmService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_interfaces::srv::ArmService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_interfaces::srv::ArmService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_interfaces::srv::ArmService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_interfaces::srv::ArmService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_interfaces__srv__ArmService_Request
    std::shared_ptr<ros_interfaces::srv::ArmService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_interfaces__srv__ArmService_Request
    std::shared_ptr<ros_interfaces::srv::ArmService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmService_Request_ & other) const
  {
    if (this->joint != other.joint) {
      return false;
    }
    if (this->joint_pos != other.joint_pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmService_Request_

// alias to use template instance with default allocator
using ArmService_Request =
  ros_interfaces::srv::ArmService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros_interfaces


#ifndef _WIN32
# define DEPRECATED__ros_interfaces__srv__ArmService_Response __attribute__((deprecated))
#else
# define DEPRECATED__ros_interfaces__srv__ArmService_Response __declspec(deprecated)
#endif

namespace ros_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ArmService_Response_
{
  using Type = ArmService_Response_<ContainerAllocator>;

  explicit ArmService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0l;
    }
  }

  explicit ArmService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0l;
    }
  }

  // field types and members
  using _result_type =
    int32_t;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const int32_t & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros_interfaces::srv::ArmService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_interfaces::srv::ArmService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_interfaces::srv::ArmService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_interfaces::srv::ArmService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_interfaces::srv::ArmService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_interfaces::srv::ArmService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_interfaces::srv::ArmService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_interfaces::srv::ArmService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_interfaces::srv::ArmService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_interfaces::srv::ArmService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_interfaces__srv__ArmService_Response
    std::shared_ptr<ros_interfaces::srv::ArmService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_interfaces__srv__ArmService_Response
    std::shared_ptr<ros_interfaces::srv::ArmService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmService_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmService_Response_

// alias to use template instance with default allocator
using ArmService_Response =
  ros_interfaces::srv::ArmService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ros_interfaces__srv__ArmService_Event __attribute__((deprecated))
#else
# define DEPRECATED__ros_interfaces__srv__ArmService_Event __declspec(deprecated)
#endif

namespace ros_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ArmService_Event_
{
  using Type = ArmService_Event_<ContainerAllocator>;

  explicit ArmService_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit ArmService_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<ros_interfaces::srv::ArmService_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ros_interfaces::srv::ArmService_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<ros_interfaces::srv::ArmService_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ros_interfaces::srv::ArmService_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<ros_interfaces::srv::ArmService_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ros_interfaces::srv::ArmService_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<ros_interfaces::srv::ArmService_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ros_interfaces::srv::ArmService_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros_interfaces::srv::ArmService_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_interfaces::srv::ArmService_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_interfaces::srv::ArmService_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_interfaces::srv::ArmService_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_interfaces::srv::ArmService_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_interfaces::srv::ArmService_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_interfaces::srv::ArmService_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_interfaces::srv::ArmService_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_interfaces::srv::ArmService_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_interfaces::srv::ArmService_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_interfaces__srv__ArmService_Event
    std::shared_ptr<ros_interfaces::srv::ArmService_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_interfaces__srv__ArmService_Event
    std::shared_ptr<ros_interfaces::srv::ArmService_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmService_Event_ & other) const
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
  bool operator!=(const ArmService_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmService_Event_

// alias to use template instance with default allocator
using ArmService_Event =
  ros_interfaces::srv::ArmService_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros_interfaces

namespace ros_interfaces
{

namespace srv
{

struct ArmService
{
  using Request = ros_interfaces::srv::ArmService_Request;
  using Response = ros_interfaces::srv::ArmService_Response;
  using Event = ros_interfaces::srv::ArmService_Event;
};

}  // namespace srv

}  // namespace ros_interfaces

#endif  // ROS_INTERFACES__SRV__DETAIL__ARM_SERVICE__STRUCT_HPP_
