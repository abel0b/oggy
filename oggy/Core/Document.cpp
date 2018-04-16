#include "Document.hpp"

#include <queue>
#include <iostream>

oggy::Document::Document(oggy::Node * root) {
  this->root = root;
  oggy::Font mainFont = oggy::Font(std::string("/usr/share/fonts/TTF/DejaVuSerif.ttf"), 16);
  //this->fonts.load("main", mainFont);
}

oggy::Document::~Document() {
  std::queue<oggy::Node *> queue;
  queue.push(this->root);
  oggy::Node * node;
  while(!queue.empty()) {
    node = queue.front();
    queue.pop();
    for (std::vector<oggy::Node*>::iterator it = node->children.begin(); it != node->children.end(); ++it) {
      queue.push(*it);
    }
    delete node;
  }
}

void oggy::Document::updateState(Event * event) {
  std::queue<oggy::Node *> queue;
  queue.push(this->root);
  oggy::Node * node;
  while(!queue.empty()) {
    node = queue.front();
    node->updateState(event);
    queue.pop();
    for (std::vector<oggy::Node*>::iterator it = node->children.begin(); it != node->children.end(); ++it) {
      queue.push(*it);
    }
  }
}

void oggy::Document::render() {
  std::cout << "=== begin render" << std::endl;
  std::queue<oggy::Node *> queue;
  queue.push(this->root);
  oggy::Node * node;
  while(!queue.empty()) {
    node = queue.front();
    int nodeWidth = (node->growX)? node->calculatedWidth : node->width;
    int nodeHeight = (node->growY)? node->calculatedHeight : node->height;
    int nodeX = (node->position == POSITION_ABSOLUTE)? node->x : node->calculatedX;
    int nodeY = (node->position == POSITION_ABSOLUTE)? node->y : node->calculatedY;
    std::cout << "w " << nodeWidth << " h " << nodeHeight << std::endl;
    std::cout << "x " << nodeX << " y " << nodeY << std::endl;
    queue.pop();
    switch (node->direction) {
      case DIRECTION_ROW:
      {
        int availableWidth = nodeWidth;
        int nXGrowable = 0;
        for (std::vector<oggy::Node*>::iterator n = node->children.begin(); n != node->children.end(); ++n) {
          queue.push(*n);
          if ((*n)->growX) {
            nXGrowable++;
          }
          else {
            availableWidth -= (*n)->width;
          }
        }

        int width=-1;
        if (nXGrowable > 0)
          width = availableWidth / nXGrowable;

        int x = nodeX;
        for (std::vector<oggy::Node*>::iterator n = node->children.begin(); n != node->children.end(); ++n) {
          (*n)->calculatedY = nodeY;
          (*n)->calculatedX = x;
          if ((*n)->growY) {
            (*n)->calculatedHeight = nodeHeight;
          }
          if ((*n)->growX) {
            (*n)->calculatedWidth = width;
            x += width;
          }
          else {
            x += (*n)->width;
          }
        }
        break;
      }
      case DIRECTION_COLUMN:
      {
        int availableHeight = nodeHeight;
        int nYGrowable = 0;
        for (std::vector<oggy::Node*>::iterator n = node->children.begin(); n != node->children.end(); ++n) {
          queue.push(*n);
          if ((*n)->growY) {
            nYGrowable++;
          }
          else {
            availableHeight -= (*n)->height;
          }
        }

        int height=-1;
        if (nYGrowable > 0)
          height = availableHeight / nYGrowable;

        int y = nodeY;
        for (std::vector<oggy::Node*>::iterator n = node->children.begin(); n != node->children.end(); ++n) {
          (*n)->calculatedX = nodeX;
          (*n)->calculatedY = y;
          if ((*n)->growX) {
            (*n)->calculatedWidth = nodeWidth;
          }
          if ((*n)->growY) {
            (*n)->calculatedHeight = height;
            y += height;
          }
          else {
            y += (*n)->height;
          }
        }
        break;
      }
      default: break;
    }
    node->render();
  }
  std::cout << "=== end render" << std::endl;
}
