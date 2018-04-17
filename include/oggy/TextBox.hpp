#ifndef OGGY_TEXTBOX_HPP
#define OGGY_TEXTBOX_HPP

#include <iostream>
#include "Node.hpp"

namespace oggy {
  class TextBox : public Node {
  public:
    TextBox(oggy::Node * parent, std::string text);
    void updateState(Event * event);
    void render();
  private:
    std::string text;
  };
}

#endif
