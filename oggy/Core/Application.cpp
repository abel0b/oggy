#include "Application.hpp"
#include <SDL2/SDL.h>

oggy::Application::Application() {
  oggy::Window * window = new oggy::Window("My Window", 1280, 720);
  this->canvas = window->canvas;
  this->document = new oggy::Document(window);
}

oggy::Application::~Application() {
  delete this->document;
}

void oggy::Application::run() {
  int FPS = 30;
  int frameTime = 1000/FPS;
  int ticks;
  SDL_Event event;
  oggy::Event * ev;
  int stop = false;
  while (!stop) {
    ticks = SDL_GetTicks();
    while(SDL_PollEvent(&event)) {
      ev = new Event(&event);
      if (event.type == SDL_QUIT) {
        stop = true;
        break;
      }
      this->document->updateState(ev);
    }
    this->document->render();
    this->canvas->refresh();
    int elapsedTime = SDL_GetTicks() - ticks;
    SDL_Delay(frameTime - elapsedTime);
  }
}
