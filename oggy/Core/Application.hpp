#ifndef OGGY_APPLICATION_HPP
#define OGGY_APPLICATION_HPP

#include "Node.hpp"
#include "Window.hpp"
#include "Document.hpp"
#include "Canvas.hpp"
#include "ResourceManager.hpp"

namespace oggy {
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
