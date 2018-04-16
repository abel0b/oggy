cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)
project(oggy)

enable_testing()
add_subdirectory(oggy)
add_subdirectory(tests)
add_subdirectory(samples)
