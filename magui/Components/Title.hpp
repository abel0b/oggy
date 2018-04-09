#ifndef MAGUI_TITLE_HPP
#define MAGUI_TITLE_HPP

#include <iostream>
#include "../Core/Node.hpp"

namespace magui {
  class Title : public Node {
  public:
    Title(std::string text);
    void updateState(Event * eevnt);
    void render();
    std::string text;
  };
}

#endif
