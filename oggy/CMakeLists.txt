set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
add_library(oggy SHARED Core/Window.hpp Core/Window.cpp Core/Node.hpp Core/Node.cpp Components/Heading.hpp Components/Heading.cpp Components/ColumnLayout.hpp Components/ColumnLayout.cpp Components/RowLayout.hpp Components/RowLayout.cpp Core/Color.hpp Core/Color.cpp Core/Canvas.hpp Core/Canvas.cpp Core/Event.hpp Core/Event.cpp Core/Application.cpp Core/Application.hpp Core/Document.hpp Core/Document.cpp Core/ResourceManager.hpp Core/Font.hpp Core/Font.cpp)
target_include_directories(oggy PUBLIC ${CMAKE_SOURCE_DIR})
