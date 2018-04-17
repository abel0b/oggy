#include "oggy/Canvas.hpp"
#include <iostream>

oggy::Canvas::Canvas(SDL_Renderer * renderer) {
  this->renderer = renderer;
}

void oggy::Canvas::drawRectangle(Color color, int x, int y, int width, int height) {
  //std::cout << "ddrawing rectangle " << std::endl;
  SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = width;
  rect.h = height;
  SDL_RenderFillRect(this->renderer, &rect);
}

void oggy::Canvas::refresh() {
  SDL_RenderPresent(this->renderer);
}
