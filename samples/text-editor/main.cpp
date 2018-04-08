#include <iostream>

#include "magui/Core/Window.hpp"
#include "magui/Core/Application.hpp"
#include "magui/Core/VerticalLayout.hpp"

int main() {
  magui::Application * app = new magui::Application();
  magui::VerticalLayout * sidebar = new magui::VerticalLayout();

  app->document->root->addChild(sidebar);


  app->run();

  delete app;

  return EXIT_SUCCESS;
}
