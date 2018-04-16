set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

add_library(oggy SHARED Window.cpp Node.cpp Heading.cpp ColumnLayout.cpp RowLayout.cpp Color.cpp Canvas.cpp Event.cpp Application.cpp Document.cpp Font.cpp)
target_link_libraries(oggy SDL2 SDL2_ttf)
