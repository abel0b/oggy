add_executable(text-editor text-editor/main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")

target_link_libraries(text-editor oggy)

add_custom_target(
  run-text-editor
  COMMAND ./examples/text-editor
  DEPENDS ./examples/text-editor
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
