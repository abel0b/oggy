#ifndef MAGUI_EVENT_HPP
#define MAGUI_EVENT_HPP

#include <SDL2/SDL.h>

namespace magui {
  class Event {
  public:
    Event(SDL_Event * event);
  private:
    SDL_Event * event;
  };
}

#endif
