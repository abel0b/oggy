#ifndef OGGY_DOCUMENT_HPP
#define OGGY_DOCUMENT_HPP

#include "Node.hpp"
#include "Event.hpp"

namespace oggy {
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
