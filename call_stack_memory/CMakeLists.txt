cmake_minimum_required(VERSION 2.8)

project(call_stack_memory)

add_executable(main main.c)

set_target_properties(main PROPERTIES
  COMPILE_FLAGS "-save-temps"
  C_STANDARD 99)
