add_executable(text-editor text-editor/main.cpp)

target_link_libraries(text-editor oggy SDL2 SDL2_ttf)
target_include_directories(text-editor PUBLIC ${CMAKE_SOURCE_DIR})

add_custom_target(
  run-text-editor
  COMMAND ./samples/text-editor
  DEPENDS ./samples/text-editor
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
