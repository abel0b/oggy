#ifndef MAGUI_DOCUMENT_HPP
#define MAGUI_DOCUMENT_HPP

#include "Node.hpp"
#include "Event.hpp"

namespace magui {
  class Document {
  public:
    Document(Node * root);
    ~Document();
    void updateState(Event * event);
    void render();
    Node * root;
  private:
  };
}

#endif
