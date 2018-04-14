#ifndef OGGY_ROW_LAYOUT_HPP
#define OGGY_ROW_LAYOUT_HPP

#include "../Core/Node.hpp"
#include "../Core/Event.hpp"

namespace oggy {

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
