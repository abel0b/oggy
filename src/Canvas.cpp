#include "oggy/Canvas.hpp"
#include <iostream>

oggy::Canvas::Canvas(SDL_Renderer * renderer) {
  this->renderer = renderer;
}

void oggy::Canvas::setFontManager(oggy::ResourceManager<Font> * fonts) {
  this->fonts = fonts;
}

void oggy::Canvas::drawRectangle(oggy::Color color, int x, int y, int width, int height) {
  SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = width;
  rect.h = height;
  SDL_RenderFillRect(this->renderer, &rect);
}

void oggy::Canvas::drawText(Color color, int x, int y, const std::string& text) {
  SDL_Color fg = {color.r,color.g,color.b,color.a};
  TTF_Font * cantarell = TTF_OpenFont("/usr/share/fonts/TTF/DejaVuSerif.ttf", 18);
  SDL_Surface * textSurface = TTF_RenderText_Blended(cantarell, text.c_str(), fg);
  SDL_Texture * textTexture = SDL_CreateTextureFromSurface(this->renderer, textSurface);
  SDL_FreeSurface(textSurface);

  int texW = 0, texH = 0;
  SDL_QueryTexture(textTexture, NULL, NULL, &texW, &texH);
  SDL_Rect r = { x, y, texW, texH };
  SDL_RenderCopy(this->renderer, textTexture, NULL, &r);
  SDL_DestroyTexture(textTexture);
  TTF_CloseFont(cantarell);
}

void oggy::Canvas::refresh() {
  SDL_RenderPresent(this->renderer);
}
