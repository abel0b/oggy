#ifndef OGGY_FONT_HPP
#define OGGY_FONT_HPP

#include <string>
#include <SDL2/SDL_ttf.h>

namespace oggy {
    class Font {
    public:
      Font(std::string& path, int size);
    private:
      std::string path;
      TTF_Font * font;
    };
}

#endif
