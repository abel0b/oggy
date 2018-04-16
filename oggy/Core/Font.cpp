#include "Font.hpp"

oggy::Font::Font(std::string path, int size) {
  this->font = TTF_OpenFont(path.c_str(), size);
  this->path = path;
}

oggy::Font::~Font() {
  TTF_CloseFont(this->font);
}
