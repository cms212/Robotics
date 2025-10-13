// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from message_interfaces:msg/TennisBallDetection.idl
// generated code does not contain a copyright notice
#include "message_interfaces/msg/detail/tennis_ball_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
message_interfaces__msg__TennisBallDetection__init(message_interfaces__msg__TennisBallDetection * msg)
{
  if (!msg) {
    return false;
  }
  // left_x
  // right_x
  // top_y
  // bottom_y
  return true;
}

void
message_interfaces__msg__TennisBallDetection__fini(message_interfaces__msg__TennisBallDetection * msg)
{
  if (!msg) {
    return;
  }
  // left_x
  // right_x
  // top_y
  // bottom_y
}

bool
message_interfaces__msg__TennisBallDetection__are_equal(const message_interfaces__msg__TennisBallDetection * lhs, const message_interfaces__msg__TennisBallDetection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // left_x
  if (lhs->left_x != rhs->left_x) {
    return false;
  }
  // right_x
  if (lhs->right_x != rhs->right_x) {
    return false;
  }
  // top_y
  if (lhs->top_y != rhs->top_y) {
    return false;
  }
  // bottom_y
  if (lhs->bottom_y != rhs->bottom_y) {
    return false;
  }
  return true;
}

bool
message_interfaces__msg__TennisBallDetection__copy(
  const message_interfaces__msg__TennisBallDetection * input,
  message_interfaces__msg__TennisBallDetection * output)
{
  if (!input || !output) {
    return false;
  }
  // left_x
  output->left_x = input->left_x;
  // right_x
  output->right_x = input->right_x;
  // top_y
  output->top_y = input->top_y;
  // bottom_y
  output->bottom_y = input->bottom_y;
  return true;
}

message_interfaces__msg__TennisBallDetection *
message_interfaces__msg__TennisBallDetection__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  message_interfaces__msg__TennisBallDetection * msg = (message_interfaces__msg__TennisBallDetection *)allocator.allocate(sizeof(message_interfaces__msg__TennisBallDetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(message_interfaces__msg__TennisBallDetection));
  bool success = message_interfaces__msg__TennisBallDetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
message_interfaces__msg__TennisBallDetection__destroy(message_interfaces__msg__TennisBallDetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    message_interfaces__msg__TennisBallDetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
message_interfaces__msg__TennisBallDetection__Sequence__init(message_interfaces__msg__TennisBallDetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  message_interfaces__msg__TennisBallDetection * data = NULL;

  if (size) {
    data = (message_interfaces__msg__TennisBallDetection *)allocator.zero_allocate(size, sizeof(message_interfaces__msg__TennisBallDetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = message_interfaces__msg__TennisBallDetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        message_interfaces__msg__TennisBallDetection__fini(&data[i - 1]);
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
message_interfaces__msg__TennisBallDetection__Sequence__fini(message_interfaces__msg__TennisBallDetection__Sequence * array)
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
      message_interfaces__msg__TennisBallDetection__fini(&array->data[i]);
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

message_interfaces__msg__TennisBallDetection__Sequence *
message_interfaces__msg__TennisBallDetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  message_interfaces__msg__TennisBallDetection__Sequence * array = (message_interfaces__msg__TennisBallDetection__Sequence *)allocator.allocate(sizeof(message_interfaces__msg__TennisBallDetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = message_interfaces__msg__TennisBallDetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
message_interfaces__msg__TennisBallDetection__Sequence__destroy(message_interfaces__msg__TennisBallDetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    message_interfaces__msg__TennisBallDetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
message_interfaces__msg__TennisBallDetection__Sequence__are_equal(const message_interfaces__msg__TennisBallDetection__Sequence * lhs, const message_interfaces__msg__TennisBallDetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!message_interfaces__msg__TennisBallDetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
message_interfaces__msg__TennisBallDetection__Sequence__copy(
  const message_interfaces__msg__TennisBallDetection__Sequence * input,
  message_interfaces__msg__TennisBallDetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(message_interfaces__msg__TennisBallDetection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    message_interfaces__msg__TennisBallDetection * data =
      (message_interfaces__msg__TennisBallDetection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!message_interfaces__msg__TennisBallDetection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          message_interfaces__msg__TennisBallDetection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!message_interfaces__msg__TennisBallDetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
