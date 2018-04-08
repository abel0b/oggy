#include "Window.hpp"

magui::Window::Window(std::string title, int width, int height) {
  TTF_Init();
  SDL_Init(SDL_INIT_VIDEO);
  this->SDLWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
  this->SDLRenderer = SDL_CreateRenderer(this->SDLWindow, -1, SDL_RENDERER_ACCELERATED);
  this->canvas = new magui::Canvas(this->SDLRenderer);
  this->x = this->y = 0;
}

void callRender(magui::Node * node) {
  int availableHeight = node->height;
  int availableWidth = node->width;
  int nXGrowable = 0;
  int nYGrowable = 0;
  for (std::vector<magui::Node*>::iterator n = node->children.begin(); n != node->children.end(); ++n) {
    if ((*n)->growX) {
      nXGrowable++;
    }
    else {
      availableWidth -= (*n)->width;
    }
    if ((*n)->growY) {
      nYGrowable++;
    }
    else {
      availableHeight -= (*n)->height;
    }
  }

  int width=-1, height=-1;
  if (nXGrowable > 0)
    width = availableWidth / nXGrowable;
  if (nYGrowable > 0)
    height = availableHeight / nYGrowable;

  for (std::vector<magui::Node*>::iterator n = node->children.begin(); n != node->children.end(); ++n) {
    if ((*n)->growX) {
      (*n)->width = width;
      (*n)->y = node->x;
    }
    if ((*n)->growY) {
      (*n)->y = node->y;
      (*n)->height = height;
    }
  }
  std::cout << "render object with geometry " <<  node->width << "-" << node->height << std::endl;
  node->render();
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
