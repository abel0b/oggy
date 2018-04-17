#ifndef OGGY_FONT_HPP
#define OGGY_FONT_HPP

#include <string>
#include <SDL2/SDL_ttf.h>
#include "Resource.hpp"

namespace oggy {
    class Font : public Resource {
    public:
      Font();
      Font(std::string path, int size);
      ~Font();
      TTF_Font * font = NULL;
    private:
      std::string path;
    };
}

#endif
