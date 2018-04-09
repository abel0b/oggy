#ifndef MAGUI_TEXTBOX_HPP
#define MAGUI_TEXTBOX_HPP

#include <string>
#include "../Core/Node.hpp"
#include <SDL2/SDL.h>

namespace magui {
  class TextBox : public Node {
  public:
    TextBox(std::string text);
    void render();
    void updateState(SDL_Event * event);
  private:
    std::string text;
    std::pair<int,int> paddingH;
    std::pair<int,int> paddingV;
    SDL_Rect rect;
  };
}

#endif
