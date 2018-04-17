#ifndef OGGY_CANVAS_HPP
#define OGGY_CANVAS_HPP

#include <SDL2/SDL.h>
#include <string>
#include "Color.hpp"
#include "ResourceManager.hpp"
#include "Font.hpp"

namespace oggy {
  class Canvas {
  public:
    Canvas(SDL_Renderer * renderer);
    void drawRectangle(Color color, int x, int y, int width, int height);
    void drawText(Color color, int x, int y, const std::string& text);
    void setFontManager(ResourceManager<Font> * fonts);
    void refresh();
    SDL_Renderer * renderer;
  private:
    ResourceManager<Font> * fonts;
  };
}

#endif
