#include "VerticalLayout.hpp"
#include "Color.hpp"
#include <iostream>
#include <SDL2/SDL.h>

magui::VerticalLayout::VerticalLayout() {
  this->width = 200;
  this->height = -1;
  this->growX = false;
  this->growY = true;
}

void magui::VerticalLayout::render() {
  std::cout << "render vl" << std::endl;
  magui::Color bg(0,0,0,255);
  std::cout << this->x << " " << this->y << " " << this->width << " " << this->height << std::endl;
  this->canvas->drawRectangle(bg, this->x, this->y, this->width, this->height);
  /*SDL_SetRenderDrawColor(this->renderer, 210,210,210,255);
  SDL_Rect rectangle = {this->x, this->y, this->width, this->height};
  SDL_RenderFillRect(this->renderer, &rectangle);*/
}

void magui::VerticalLayout::updateState(Event * event) {

}
