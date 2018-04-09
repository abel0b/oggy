#ifndef MAGUI_COLUMN_LAYOUT_HPP
#define MAGUI_COLUMN_LAYOUT_HPP

#include "../Core/Node.hpp"
#include "../Core/Event.hpp"
#include "../Core/Color.hpp"

namespace magui {

  class ColumnLayout : public Node {
  public:
    ColumnLayout();
    ColumnLayout(int width);
    void render();
    void updateState(Event * event);
    void setBackground(Color color);
  private:
    Color background;
  };
}

#endif
