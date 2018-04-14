#include <iostream>

#include "oggy/Core/Window.hpp"
#include "oggy/Core/Application.hpp"
#include "oggy/Core/Color.hpp"
#include "oggy/Components/ColumnLayout.hpp"
#include "oggy/Components/RowLayout.hpp"
#include "oggy/Components/Heading.hpp"

int main() {
  oggy::Application * app = new oggy::Application();

  oggy::RowLayout * toolbar = new oggy::RowLayout(25);
  toolbar->setBackground(oggy::Color(200,200,200,255));


  oggy::RowLayout * main = new oggy::RowLayout();
  main->setBackground(oggy::Color(0,255,0,255));

  oggy::ColumnLayout * text = new oggy::ColumnLayout();
  text->setBackground(oggy::Color(255,255,255,255));

  oggy::ColumnLayout * sidebar = new oggy::ColumnLayout(200);
  sidebar->setBackground(oggy::Color(40,40,40,255));

  oggy::Heading * title = new oggy::Heading("Sidebar");

  oggy::RowLayout * statusbar = new oggy::RowLayout(20);
  statusbar->setBackground(oggy::Color(200,200,200,255));

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
