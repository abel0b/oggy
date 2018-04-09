#include "Window.hpp"

magui::Window::Window(std::string title, int width, int height) {
  TTF_Init();
  SDL_Init(SDL_INIT_VIDEO);
  this->SDLWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
  this->SDLRenderer = SDL_CreateRenderer(this->SDLWindow, -1, SDL_RENDERER_ACCELERATED);
  this->canvas = new magui::Canvas(this->SDLRenderer);
  this->x = this->y = 0;
  this->growX = this->growY = false;
  this->alignChildren = ALIGNMENT_START;
  this->direction = DIRECTION_COLUMN;
  this->alignChildren = ALIGNMENT_START;
  this->overflow = OVERFLOW_WRAP;
  this->alignSelf = ALIGNMENT_START;
  this->position = POSITION_ABSOLUTE;
}

void magui::Window::updateState(Event * event) {
  SDL_GetWindowSize(this->SDLWindow, &this->width, &this->height);
}

void magui::Window::render() {
  std::cout << "render win" << std::endl;
  SDL_SetRenderDrawColor(this->SDLRenderer, 255,255,255,255);
  SDL_RenderClear(this->SDLRenderer);
}


magui::Window::~Window() {
  TTF_Quit();
  SDL_Quit();
}
