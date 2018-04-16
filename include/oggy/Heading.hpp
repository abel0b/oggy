#ifndef OGGY_HEADING_HPP
#define OGGY_HEADING_HPP

#include <iostream>
#include "Node.hpp"

namespace oggy {
  class Heading : public Node {
  public:
    Heading(std::string text);
    void updateState(Event * eevnt);
    void render();
    std::string text;
  };
}

#endif
