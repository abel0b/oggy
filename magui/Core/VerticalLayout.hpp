#ifndef MAGUI_VERTICAL_LAYOUT_HPP
#define MAGUI_VERTICAL_LAYOUT_HPP

#include "Node.hpp"
#include "Event.hpp"

namespace magui {

  class VerticalLayout : public Node {
  public:
    VerticalLayout();
    void render();
    void updateState(Event * event);
  };
}

#endif
