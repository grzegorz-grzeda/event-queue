# event-queue

Small event queue.

This is a [G2EPM](https://github.com/grzegorz-grzeda/g2epm) library.

## How to compile and link it?

Just include this directory in your CMake project.

You **MUST** specify:
- `EVENT_QUEUE_PAYLOAD_MAX_SIZE` the maximum payload size for each event,
- `EVENT_QUEUE_MAX_COUNT` the maximum number of events the queue can hold.

Example `CMakeLists.txt` content:
```
...

add_subdirectory(<PATH TO THIS LIBRARY>)
target_compile_definitions(event-queue PRIVATE EVENT_QUEUE_PAYLOAD_MAX_SIZE=64)
target_compile_definitions(event-queue PRIVATE EVENT_QUEUE_MAX_COUNT=20)
target_link_libraries(${PROJECT_NAME} PRIVATE event-queue)

...
```

# Copyright
This library was written by G2Labs Grzegorz Grzęda, and is distributed under MIT Licence. Check the `LICENSE` file for more details.