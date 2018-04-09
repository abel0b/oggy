#include <iostream>

#include "magui/Core/Window.hpp"
#include "magui/Core/Application.hpp"
#include "magui/Core/Color.hpp"
#include "magui/Components/ColumnLayout.hpp"
#include "magui/Components/RowLayout.hpp"
#include "magui/Components/Title.hpp"

int main() {
  magui::Application * app = new magui::Application();

  magui::RowLayout * toolbar = new magui::RowLayout(25);
  toolbar->setBackground(magui::Color(200,200,200,255));


  magui::RowLayout * main = new magui::RowLayout();
  main->setBackground(magui::Color(0,255,0,255));

  magui::ColumnLayout * text = new magui::ColumnLayout();
  text->setBackground(magui::Color(255,255,255,255));

  magui::ColumnLayout * sidebar = new magui::ColumnLayout(200);
  sidebar->setBackground(magui::Color(40,40,40,255));

  magui::Title * title = new magui::Title("Sidebar");

  magui::RowLayout * statusbar = new magui::RowLayout(20);
  statusbar->setBackground(magui::Color(200,200,200,255));

  app->document->root->addChild(toolbar);
  app->document->root->addChild(main);
    main->addChild(sidebar);
      sidebar->addChild(title);
    main->addChild(text);
  app->document->root->addChild(statusbar);


  app->run();

  delete app;

  return EXIT_SUCCESS;
}
