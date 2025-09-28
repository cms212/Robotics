// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from message_interfaces:msg/ArmPosition.idl
// generated code does not contain a copyright notice
#include "message_interfaces/msg/detail/arm_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `arm_positions`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
message_interfaces__msg__ArmPosition__init(message_interfaces__msg__ArmPosition * msg)
{
  if (!msg) {
    return false;
  }
  // arm_positions
  if (!rosidl_runtime_c__uint32__Sequence__init(&msg->arm_positions, 0)) {
    message_interfaces__msg__ArmPosition__fini(msg);
    return false;
  }
  return true;
}

void
message_interfaces__msg__ArmPosition__fini(message_interfaces__msg__ArmPosition * msg)
{
  if (!msg) {
    return;
  }
  // arm_positions
  rosidl_runtime_c__uint32__Sequence__fini(&msg->arm_positions);
}

bool
message_interfaces__msg__ArmPosition__are_equal(const message_interfaces__msg__ArmPosition * lhs, const message_interfaces__msg__ArmPosition * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // arm_positions
  if (!rosidl_runtime_c__uint32__Sequence__are_equal(
      &(lhs->arm_positions), &(rhs->arm_positions)))
  {
    return false;
  }
  return true;
}

bool
message_interfaces__msg__ArmPosition__copy(
  const message_interfaces__msg__ArmPosition * input,
  message_interfaces__msg__ArmPosition * output)
{
  if (!input || !output) {
    return false;
  }
  // arm_positions
  if (!rosidl_runtime_c__uint32__Sequence__copy(
      &(input->arm_positions), &(output->arm_positions)))
  {
    return false;
  }
  return true;
}

message_interfaces__msg__ArmPosition *
message_interfaces__msg__ArmPosition__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  message_interfaces__msg__ArmPosition * msg = (message_interfaces__msg__ArmPosition *)allocator.allocate(sizeof(message_interfaces__msg__ArmPosition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(message_interfaces__msg__ArmPosition));
  bool success = message_interfaces__msg__ArmPosition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
message_interfaces__msg__ArmPosition__destroy(message_interfaces__msg__ArmPosition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    message_interfaces__msg__ArmPosition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
message_interfaces__msg__ArmPosition__Sequence__init(message_interfaces__msg__ArmPosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  message_interfaces__msg__ArmPosition * data = NULL;

  if (size) {
    data = (message_interfaces__msg__ArmPosition *)allocator.zero_allocate(size, sizeof(message_interfaces__msg__ArmPosition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = message_interfaces__msg__ArmPosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        message_interfaces__msg__ArmPosition__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
message_interfaces__msg__ArmPosition__Sequence__fini(message_interfaces__msg__ArmPosition__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      message_interfaces__msg__ArmPosition__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

message_interfaces__msg__ArmPosition__Sequence *
message_interfaces__msg__ArmPosition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  message_interfaces__msg__ArmPosition__Sequence * array = (message_interfaces__msg__ArmPosition__Sequence *)allocator.allocate(sizeof(message_interfaces__msg__ArmPosition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = message_interfaces__msg__ArmPosition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
message_interfaces__msg__ArmPosition__Sequence__destroy(message_interfaces__msg__ArmPosition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    message_interfaces__msg__ArmPosition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
message_interfaces__msg__ArmPosition__Sequence__are_equal(const message_interfaces__msg__ArmPosition__Sequence * lhs, const message_interfaces__msg__ArmPosition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!message_interfaces__msg__ArmPosition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
message_interfaces__msg__ArmPosition__Sequence__copy(
  const message_interfaces__msg__ArmPosition__Sequence * input,
  message_interfaces__msg__ArmPosition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(message_interfaces__msg__ArmPosition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    message_interfaces__msg__ArmPosition * data =
      (message_interfaces__msg__ArmPosition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!message_interfaces__msg__ArmPosition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          message_interfaces__msg__ArmPosition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!message_interfaces__msg__ArmPosition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
