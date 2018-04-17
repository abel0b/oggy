#ifndef OGGY_NODE_HPP
#define OGGY_NODE_HPP

#include <vector>
#include <SDL2/SDL.h>

#include "Canvas.hpp"
#include "Event.hpp"
#include "Font.hpp"

namespace oggy {
  enum Direction {
    DIRECTION_COLUMN,
    DIRECTION_ROW
  };

  enum Alignment {
    ALIGNMENT_START,
    ALIGNMENT_CENTER,
    ALIGNMENT_END
  };

  enum Overflow {
    OVERFLOW_NOWRAP,
    OVERFLOW_WRAP
  };

  enum Position {
    POSITION_AUTO,
    POSITION_ABSOLUTE
  };

  class Node {
    public:
      Node();
      Node(oggy::Node * parent);
      virtual ~Node();
      Node(Canvas * canvas);
      void addChild(Node * node);
      virtual void updateState(Event * event) = 0;
      virtual void render() = 0;
      void renderAll();
      void updateStateAll(SDL_Event * event);

      int x = 0;
      int calculatedX = 0;
      int y = 0;
      int calculatedY = 0;
      int width;
      int calculatedWidth;
      int height;
      int calculatedHeight;
      bool growX;
      bool growY;
      enum Direction direction;
      enum Alignment alignChildren;
      enum Overflow overflow;
      enum Alignment alignSelf;
      enum Position position;
      bool hidden = false;
      std::vector <Node*> children;
      Canvas * canvas;
    protected:
      Node * parent;
  };
}

#endif
