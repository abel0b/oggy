#include "oggy/TextBox.hpp"

#include <SDL2/SDL_ttf.h>

oggy::TextBox::TextBox(oggy::Node * parent, std::string text):
oggy::Node(parent) {
  this->text = text;
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

void oggy::TextBox::render() {
  this->canvas->drawRectangle(oggy::Color(20,20,255,255), this->calculatedX, this->calculatedY, this->calculatedWidth, this->calculatedHeight);

  this->canvas->drawText(oggy::Color(240,240,240,255), this->calculatedX, this->calculatedY, this->text);
}

void oggy::TextBox::updateState(Event * event) {

}
