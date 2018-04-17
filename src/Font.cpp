#include "oggy/Font.hpp"
#include <stdlib.h>
#include <iostream>

int i = 0;

oggy::Font::Font() {
  this->font = NULL;
}

oggy::Font::Font(std::string path, int size) {
  this->font = TTF_OpenFont(path.c_str(), size);
  this->path = path;
}

oggy::Font::~Font() {
  if (this->font) {
    TTF_CloseFont(this->font);
  }
}
