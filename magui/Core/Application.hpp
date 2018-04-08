#ifndef MAGUI_APPLICATION_HPP
#define MAGUI_APPLICATION_HPP

#include "Node.hpp"
#include "Window.hpp"
#include "Document.hpp"
#include "Canvas.hpp"

namespace magui {
  class Application {
  public:
    Application();
    ~Application();
    void run();
    Document * document;
    Canvas * canvas;
  };
}

#endif
