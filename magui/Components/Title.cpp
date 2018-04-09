#include "Title.hpp"
#include <SDL2/SDL_ttf.h>

magui::Title::Title(std::string text) {
  this->text = text;
  this->width = -1;
  this->height = 40;
  this->growX = true;
  this->growY = false;
  this->alignChildren = ALIGNMENT_START;
  this->direction = DIRECTION_ROW;
  this->alignChildren = ALIGNMENT_START;
  this->overflow = OVERFLOW_WRAP;
  this->alignSelf = ALIGNMENT_START;
  this->position = POSITION_AUTO;
}


void magui::Title::render() {
  std::cout << "render " << this->text << "boxx\n" << std::endl;
  magui::Color blue(20,20,255,255);
  this->canvas->drawRectangle(blue, this->calculatedX, this->calculatedY, this->calculatedWidth, this->height);

  TTF_Font * cantarell = TTF_OpenFont("/usr/share/fonts/TTF/DejaVuSerif.ttf", 16);
  SDL_Color fg = {0,0,0,255};
  SDL_Color bg = {255,255,255,255};
  SDL_Surface * txt = TTF_RenderText_Shaded(cantarell, this->text.c_str(), fg, bg);
  SDL_Texture * texture = SDL_CreateTextureFromSurface(this->canvas->renderer, txt);
  SDL_FreeSurface(txt);

  int texW = 0;
  int texH = 0;
  SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
  SDL_Rect r = { this->calculatedX, this->calculatedY, texW, texH };
  //std::cout << this->x << this->y << std::endl;
  SDL_RenderCopy(this->canvas->renderer, texture, NULL, &r);

  TTF_CloseFont(cantarell);
  SDL_DestroyTexture(texture);
}

void magui::Title::updateState(Event * event) {
  std::cout << "okok"<< std::endl;
}
