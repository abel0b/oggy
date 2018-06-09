cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)
project(oggy)

enable_testing()
include_directories(include)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(examples)
