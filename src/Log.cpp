#include "oggy/Log.hpp"
#include <iostream>

void oggy::Log::info(std::string& message) {
  std::cout << "info: " << message << std::endl;
}

void oggy::Log::debug(std::string& message) {
  std::cout << "debug: " << message << std::endl;
}
