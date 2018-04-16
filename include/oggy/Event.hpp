#ifndef OGGY_EVENT_HPP
#define OGGY_EVENT_HPP

#include <SDL2/SDL.h>

namespace oggy {
  class Event {
  public:
    Event(SDL_Event * event);
  private:
    SDL_Event * event;
  };
}

#endif
