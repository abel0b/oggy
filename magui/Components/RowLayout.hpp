#ifndef MAGUI_ROW_LAYOUT_HPP
#define MAGUI_ROW_LAYOUT_HPP

#include "../Core/Node.hpp"
#include "../Core/Event.hpp"

namespace magui {

  class RowLayout : public Node {
  public:
    RowLayout();
    RowLayout(int height);
    void render();
    void updateState(Event * event);
    void setBackground(Color color);
  private:
    Color background;
  };
}

#endif
