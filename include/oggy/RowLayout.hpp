#ifndef OGGY_ROW_LAYOUT_HPP
#define OGGY_ROW_LAYOUT_HPP

#include "Node.hpp"
#include "Event.hpp"

namespace oggy {

  class RowLayout : public Node {
  public:
    RowLayout(oggy::Node * parent);
    RowLayout(oggy::Node * parent, int height);
    void render();
    void updateState(Event * event);
    void setBackground(Color color);
  private:
    Color background;
  };
}

#endif
