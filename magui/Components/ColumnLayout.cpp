#include "ColumnLayout.hpp"
#include "../Core/Color.hpp"
#include <iostream>
#include <SDL2/SDL.h>

magui::ColumnLayout::ColumnLayout():
  background(255,0,0,255) {
  this->width = -1;
  this->height = -1;
  this->growX = true;
  this->growY = true;
  this->alignChildren = ALIGNMENT_START;
  this->direction = DIRECTION_COLUMN;
  this->alignChildren = ALIGNMENT_START;
  this->overflow = OVERFLOW_WRAP;
  this->alignSelf = ALIGNMENT_START;
  this->position = POSITION_AUTO;
}

magui::ColumnLayout::ColumnLayout(int width):
  background(255,0,0,255) {
  this->width = width;
  this->height = -1;
  this->growX = false;
  this->growY = true;
  this->alignChildren = ALIGNMENT_START;
  this->direction = DIRECTION_COLUMN;
  this->alignChildren = ALIGNMENT_START;
  this->overflow = OVERFLOW_WRAP;
  this->alignSelf = ALIGNMENT_START;
  this->position = POSITION_AUTO;
}

void magui::ColumnLayout::render() {
  std::cout << "render vl" << std::endl;
  std::cout << this->calculatedX << " " << this->calculatedY << " " << this->width << " " << this->calculatedHeight << std::endl;
  this->canvas->drawRectangle(this->background, this->calculatedX, this->calculatedY, (this->growX)? this->calculatedWidth : this->width, this->calculatedHeight);
  /*SDL_SetRenderDrawColor(this->renderer, 210,210,210,255);
  SDL_Rect rectangle = {this->x, this->y, this->width, this->height};
  SDL_RenderFillRect(this->renderer, &rectangle);*/
}

void magui::ColumnLayout::updateState(Event * event) {

}

void magui::ColumnLayout::setBackground(Color color) {
  this->background = color;
}
