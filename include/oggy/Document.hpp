#ifndef OGGY_DOCUMENT_HPP
#define OGGY_DOCUMENT_HPP

#include "Node.hpp"
#include "Event.hpp"
#include "ResourceManager.hpp"
#include "Font.hpp"
#include "Resource.hpp"

namespace oggy {
  class Document {
  public:
    Document(Node * root);
    ~Document();
    Resource * resource(std::string& id);
    void updateState(Event * event);
    void render();
    Node * root;
  private:
    ResourceManager<Font> fonts;
  };
}

#endif
