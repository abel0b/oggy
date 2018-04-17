#include <iostream>

#include "oggy/Window.hpp"
#include "oggy/Application.hpp"
#include "oggy/Color.hpp"
#include "oggy/ColumnLayout.hpp"
#include "oggy/RowLayout.hpp"
#include "oggy/Heading.hpp"

int main() {
  oggy::Application * app = new oggy::Application();
  oggy::Node * root = app->document->root;

  oggy::RowLayout * toolbar = new oggy::RowLayout(root, 25);
  toolbar->setBackground(oggy::Color(200,200,200,255));

  oggy::RowLayout * main = new oggy::RowLayout(root);
  main->setBackground(oggy::Color(0,255,0,255));

  oggy::ColumnLayout * sidebar = new oggy::ColumnLayout(main, 200);
  sidebar->setBackground(oggy::Color(40,40,40,255));

  oggy::ColumnLayout * text = new oggy::ColumnLayout(main);
  text->setBackground(oggy::Color(255,255,255,255));


  oggy::Heading * title = new oggy::Heading(sidebar, "Sidebar");

  oggy::RowLayout * statusbar = new oggy::RowLayout(root, 20);
  statusbar->setBackground(oggy::Color(200,200,200,255));

  app->run();

  delete app;

  return EXIT_SUCCESS;
}
