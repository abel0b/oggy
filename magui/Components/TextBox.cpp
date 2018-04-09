#include "TextBox.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

magui::TextBox::TextBox(std::string text) {
  this->text = text;
  this->growX = true;
  this->growY = false;
  this->height = 50;
  std::cout << "construct " << text << std::endl;
}

void magui::TextBox::render() {
  std::cout << "render " << this->text << "boxx\n" << std::endl;
  magui::Color blue(20,20,255,255);
  this->canvas->drawRectangle(blue, 0,0, 50, 50);
  /*SDL_Rect rect = {0, 0, 50, 50};
  SDL_SetRenderDrawColor(this->canvas->renderer,255,255,0,255);
  SDL_RenderFillRect(renderer, &rect);


  TTF_Font * cantarell = TTF_OpenFont("../magui/assets/fonts/Cantarell-Regular.ttf", 16);
  SDL_Color fg = {0,0,0,255};
  SDL_Color bg = {255,255,255,255};
  SDL_Surface * txt = TTF_RenderText_Shaded(cantarell, this->text.c_str(), fg, bg);
  SDL_Texture * texture = SDL_CreateTextureFromSurface(this->renderer, txt);
  SDL_FreeSurface(txt);

  int texW = 0;
  int texH = 0;
  SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
  SDL_Rect r = { this->x, this->y, texW, texH };
  std::cout << this->x << this->y << std::endl;
  SDL_RenderCopy(this->renderer, texture, NULL, &r);

  TTF_CloseFont(cantarell);*/
}

void magui::TextBox::updateState(SDL_Event * event) {
  std::cout << "okok"<< std::endl;
}
