add_executable(text-editor text-editor/main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")

target_link_libraries(text-editor oggy)

add_custom_target(
  run-text-editor
  COMMAND ./samples/text-editor
  DEPENDS ./samples/text-editor
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
