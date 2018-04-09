#include <stdint.h>
#include "Color.hpp"

magui::Color::Color() {
  this->r = 255;
  this->g = 255;
  this->b = 255;
  this->a = 255;
}

magui::Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}
