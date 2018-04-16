#ifndef OGGY_COLOR_HPP
#define OGGY_COLOR_HPP

#include <stdint.h>

namespace oggy {
  class Color {
  public:
    Color();
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
  };
}

#endif
