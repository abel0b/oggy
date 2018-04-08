#ifndef MAGUI_NODE_HPP
#define MAGUI_NODE_HPP

#include <vector>
#include <SDL2/SDL.h>

#include "Canvas.hpp"
#include "Event.hpp"

namespace magui {

  class Node {
    public:
      Node();
      virtual ~Node();
      Node(Canvas * canvas);
      void addChild(Node * node);
      virtual void updateState(Event * event) = 0;
      virtual void render() = 0;
      void renderAll();
      void updateStateAll(SDL_Event * event);

      int x = 0;
      int y = 0;
      int width;
      int height;
      bool growX;
      bool growY;
      bool hidden = false;
      std::vector <Node*> children;
      Canvas * canvas;
    protected:
      Node * parent;
  };
}

#endif
