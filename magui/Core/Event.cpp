#include "Event.hpp"

magui::Event::Event(SDL_Event * event) {
  this->event = event;
}
