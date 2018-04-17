#include "oggy/Heading.hpp"
#include "oggy/TextBox.hpp"
#include <SDL2/SDL_ttf.h>

oggy::Heading::Heading(oggy::Node * parent, std::string text):
oggy::Node(parent) {
  new oggy::TextBox(this, text);
  this->width = -1;
  this->height = 40;
  this->growX = true;
  this->growY = false;
  this->alignChildren = ALIGNMENT_START;
  this->direction = DIRECTION_ROW;
  this->alignChildren = ALIGNMENT_START;
  this->overflow = OVERFLOW_WRAP;
  this->alignSelf = ALIGNMENT_START;
  this->position = POSITION_AUTO;
}

void oggy::Heading::render() {
  //std::cout << "render " << this->text << "boxx\n" << std::endl;
  this->canvas->drawRectangle(oggy::Color(20,20,255,255), this->calculatedX, this->calculatedY, this->calculatedWidth, this->height);

  //this->canvas->drawText(oggy::Color(240,240,240,255), this->calculatedX, this->calculatedY, this->text);
}

void oggy::Heading::updateState(Event * event) {
  //std::cout << "okok"<< std::endl;
}
