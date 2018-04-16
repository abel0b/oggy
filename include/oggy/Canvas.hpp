#ifndef OGGY_CANVAS_HPP
#define OGGY_CANVAS_HPP

#include <SDL2/SDL.h>
#include "Color.hpp"

namespace oggy {
  class Canvas {
  public:
    Canvas(SDL_Renderer * renderer);
    void drawRectangle(Color color, int x, int y, int width, int height);
    void refresh();
    SDL_Renderer * renderer;
  private:
  };
}

#endif
