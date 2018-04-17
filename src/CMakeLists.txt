set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

add_library(oggy SHARED
  Window.cpp ../include/oggy/Window.hpp
  Node.cpp ../include/oggy/Node.hpp
  Heading.cpp ../include/oggy/Heading.hpp
  ColumnLayout.cpp ../include/oggy/ColumnLayout.hpp
  RowLayout.cpp ../include/oggy/RowLayout.hpp
  Color.cpp ../include/oggy/Color.hpp
  Canvas.cpp ../include/oggy/Canvas.hpp
  Event.cpp ../include/oggy/Event.hpp
  Application.cpp ../include/oggy/Application.hpp
  Document.cpp ../include/oggy/Document.hpp
  Font.cpp ../include/oggy/Font.hpp
  Log.cpp ../include/oggy/Log.hpp
  TextBox.cpp ../include/oggy/TextBox.hpp
)

target_link_libraries(oggy SDL2 SDL2_ttf)
