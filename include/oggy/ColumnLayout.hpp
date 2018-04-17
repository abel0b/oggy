#ifndef OGGY_COLUMN_LAYOUT_HPP
#define OGGY_COLUMN_LAYOUT_HPP

#include "Node.hpp"
#include "Event.hpp"
#include "Color.hpp"

namespace oggy {

  class ColumnLayout : public Node {
  public:
    ColumnLayout(oggy::Node * parent);
    ColumnLayout(oggy::Node * parent, int width);
    void render();
    void updateState(Event * event);
    void setBackground(Color color);
  private:
    Color background;
  };
}

#endif
