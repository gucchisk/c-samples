cmake_minimum_required(VERSION 2.8.12)

project(ffi)

include_directories(/usr/local/opt/libffi/include)
add_executable(main main.c)
target_link_libraries(main ffi)

set(CMAKE_MACOSX_RPATH 1)
add_library(sample SHARED libsample.c)

