#include "Document.hpp"

#include <queue>
#include <iostream>

magui::Document::Document(magui::Node * root) {
  this->root = root;
}

magui::Document::~Document() {
  std::queue<magui::Node *> queue;
  queue.push(this->root);
  magui::Node * node;
  while(!queue.empty()) {
    node = queue.front();
    queue.pop();
    for (std::vector<magui::Node*>::iterator it = node->children.begin(); it != node->children.end(); ++it) {
      queue.push(*it);
    }
    delete node;
  }
}

void magui::Document::updateState(Event * event) {
  std::queue<magui::Node *> queue;
  queue.push(this->root);
  magui::Node * node;
  while(!queue.empty()) {
    node = queue.front();
    node->updateState(event);
    queue.pop();
    for (std::vector<magui::Node*>::iterator it = node->children.begin(); it != node->children.end(); ++it) {
      queue.push(*it);
    }
  }
}

void magui::Document::render() {
  std::cout << "=== begin render" << std::endl;
  std::queue<magui::Node *> queue;
  queue.push(this->root);
  magui::Node * node;
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
        for (std::vector<magui::Node*>::iterator n = node->children.begin(); n != node->children.end(); ++n) {
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
        for (std::vector<magui::Node*>::iterator n = node->children.begin(); n != node->children.end(); ++n) {
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
        for (std::vector<magui::Node*>::iterator n = node->children.begin(); n != node->children.end(); ++n) {
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
        for (std::vector<magui::Node*>::iterator n = node->children.begin(); n != node->children.end(); ++n) {
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
