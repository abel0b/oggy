#include "Canvas.hpp"
#include <iostream>

magui::Canvas::Canvas(SDL_Renderer * renderer) {
  this->renderer = renderer;
}

void magui::Canvas::drawRectangle(Color color, int x, int y, int width, int height) {
  std::cout << "ddrawing rectangle " << std::endl;
  SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = width;
  rect.h = height;
  SDL_RenderFillRect(this->renderer, &rect);
}

void magui::Canvas::refresh() {
  SDL_RenderPresent(this->renderer);
}
