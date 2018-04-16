#include "oggy/Event.hpp"

oggy::Event::Event(SDL_Event * event) {
  this->event = event;
}
