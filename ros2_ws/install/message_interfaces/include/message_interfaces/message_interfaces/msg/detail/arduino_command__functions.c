// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from message_interfaces:msg/ArduinoCommand.idl
// generated code does not contain a copyright notice
#include "message_interfaces/msg/detail/arduino_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `arduino_command`
#include "rosidl_runtime_c/string_functions.h"

bool
message_interfaces__msg__ArduinoCommand__init(message_interfaces__msg__ArduinoCommand * msg)
{
  if (!msg) {
    return false;
  }
  // arduino_command
  if (!rosidl_runtime_c__String__init(&msg->arduino_command)) {
    message_interfaces__msg__ArduinoCommand__fini(msg);
    return false;
  }
  return true;
}

void
message_interfaces__msg__ArduinoCommand__fini(message_interfaces__msg__ArduinoCommand * msg)
{
  if (!msg) {
    return;
  }
  // arduino_command
  rosidl_runtime_c__String__fini(&msg->arduino_command);
}

bool
message_interfaces__msg__ArduinoCommand__are_equal(const message_interfaces__msg__ArduinoCommand * lhs, const message_interfaces__msg__ArduinoCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // arduino_command
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->arduino_command), &(rhs->arduino_command)))
  {
    return false;
  }
  return true;
}

bool
message_interfaces__msg__ArduinoCommand__copy(
  const message_interfaces__msg__ArduinoCommand * input,
  message_interfaces__msg__ArduinoCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // arduino_command
  if (!rosidl_runtime_c__String__copy(
      &(input->arduino_command), &(output->arduino_command)))
  {
    return false;
  }
  return true;
}

message_interfaces__msg__ArduinoCommand *
message_interfaces__msg__ArduinoCommand__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  message_interfaces__msg__ArduinoCommand * msg = (message_interfaces__msg__ArduinoCommand *)allocator.allocate(sizeof(message_interfaces__msg__ArduinoCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(message_interfaces__msg__ArduinoCommand));
  bool success = message_interfaces__msg__ArduinoCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
message_interfaces__msg__ArduinoCommand__destroy(message_interfaces__msg__ArduinoCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    message_interfaces__msg__ArduinoCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
message_interfaces__msg__ArduinoCommand__Sequence__init(message_interfaces__msg__ArduinoCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  message_interfaces__msg__ArduinoCommand * data = NULL;

  if (size) {
    data = (message_interfaces__msg__ArduinoCommand *)allocator.zero_allocate(size, sizeof(message_interfaces__msg__ArduinoCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = message_interfaces__msg__ArduinoCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        message_interfaces__msg__ArduinoCommand__fini(&data[i - 1]);
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
message_interfaces__msg__ArduinoCommand__Sequence__fini(message_interfaces__msg__ArduinoCommand__Sequence * array)
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
      message_interfaces__msg__ArduinoCommand__fini(&array->data[i]);
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

message_interfaces__msg__ArduinoCommand__Sequence *
message_interfaces__msg__ArduinoCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  message_interfaces__msg__ArduinoCommand__Sequence * array = (message_interfaces__msg__ArduinoCommand__Sequence *)allocator.allocate(sizeof(message_interfaces__msg__ArduinoCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = message_interfaces__msg__ArduinoCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
message_interfaces__msg__ArduinoCommand__Sequence__destroy(message_interfaces__msg__ArduinoCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    message_interfaces__msg__ArduinoCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
message_interfaces__msg__ArduinoCommand__Sequence__are_equal(const message_interfaces__msg__ArduinoCommand__Sequence * lhs, const message_interfaces__msg__ArduinoCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!message_interfaces__msg__ArduinoCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
message_interfaces__msg__ArduinoCommand__Sequence__copy(
  const message_interfaces__msg__ArduinoCommand__Sequence * input,
  message_interfaces__msg__ArduinoCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(message_interfaces__msg__ArduinoCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    message_interfaces__msg__ArduinoCommand * data =
      (message_interfaces__msg__ArduinoCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!message_interfaces__msg__ArduinoCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          message_interfaces__msg__ArduinoCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!message_interfaces__msg__ArduinoCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
