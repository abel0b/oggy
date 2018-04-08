set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
add_library(magui SHARED Core/Window.hpp Core/Window.cpp Core/Node.hpp Core/Node.cpp Components/TextBox.hpp Components/TextBox.cpp Core/VerticalLayout.hpp Core/VerticalLayout.cpp Core/Color.hpp Core/Color.cpp Core/Canvas.hpp Core/Canvas.cpp Core/Event.hpp Core/Event.cpp Core/Application.cpp Core/Application.hpp Core/Document.hpp Core/Document.cpp)
target_include_directories(magui PUBLIC ${CMAKE_SOURCE_DIR})
