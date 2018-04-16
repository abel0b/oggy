#ifndef OGGY_WINDOW_HPP
#define OGGY_WINDOW_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "Node.hpp"

namespace oggy {
  class Window : public Node {
  public:
    Window(std::string title, int width, int height);
    ~Window();
    int getWidth();
    int getHeight();
    void updateState(Event * event);
    void render();
    void run();
    SDL_Renderer * SDLRenderer;
  private:
    SDL_Window * SDLWindow;
  };
}

#endif
