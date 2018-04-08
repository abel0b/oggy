#ifndef MAGUI_COLOR_HPP
#define MAGUI_COLOR_HPP

#include <stdint.h>

namespace magui {
  class Color {
  public:
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
  };
}

#endif
