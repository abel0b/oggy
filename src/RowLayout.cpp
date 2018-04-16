#include "oggy/RowLayout.hpp"
#include "oggy/Color.hpp"
#include <iostream>
#include <SDL2/SDL.h>

oggy::RowLayout::RowLayout(int height) {
  this->width = -1;
  this->height = height;
  this->growX = true;
  this->growY = false;
  this->alignChildren = ALIGNMENT_START;
  this->direction = DIRECTION_ROW;
  this->alignChildren = ALIGNMENT_START;
  this->overflow = OVERFLOW_WRAP;
  this->alignSelf = ALIGNMENT_START;
  this->position = POSITION_AUTO;
}

oggy::RowLayout::RowLayout() {
  this->width = -1;
  this->height = -1;
  this->growX = true;
  this->growY = true;
  this->alignChildren = ALIGNMENT_START;
  this->direction = DIRECTION_ROW;
  this->alignChildren = ALIGNMENT_START;
  this->overflow = OVERFLOW_WRAP;
  this->alignSelf = ALIGNMENT_START;
  this->position = POSITION_AUTO;
}

void oggy::RowLayout::render() {
  std::cout << "render hl" << std::endl;
  this->canvas->drawRectangle(this->background, this->calculatedX, this->calculatedY, this->calculatedWidth, (this->growY)? this->calculatedHeight : this->height);
  /*SDL_SetRenderDrawColor(this->renderer, 210,210,210,255);
  SDL_Rect rectangle = {this->x, this->y, this->width, this->height};
  SDL_RenderFillRect(this->renderer, &rectangle);*/
}

void oggy::RowLayout::setBackground(Color color) {
  this->background = color;
}

void oggy::RowLayout::updateState(Event * event) {

}
