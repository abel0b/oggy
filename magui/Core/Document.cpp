#include "Document.hpp"

#include <queue>

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
  std::queue<magui::Node *> queue;
  queue.push(this->root);
  magui::Node * node;
  while(!queue.empty()) {
    node = queue.front();
    queue.pop();
    int availableHeight = node->height;
    int availableWidth = node->width;
    int nXGrowable = 0;
    int nYGrowable = 0;
    for (std::vector<magui::Node*>::iterator n = node->children.begin(); n != node->children.end(); ++n) {
      queue.push(*n);
      if ((*n)->growX) {
        nXGrowable++;
      }
      else {
        availableWidth -= (*n)->width;
      }
      if ((*n)->growY) {
        nYGrowable++;
      }
      else {
        availableHeight -= (*n)->height;
      }
    }

    int width=-1, height=-1;
    if (nXGrowable > 0)
      width = availableWidth / nXGrowable;
    if (nYGrowable > 0)
      height = availableHeight / nYGrowable;

    for (std::vector<magui::Node*>::iterator n = node->children.begin(); n != node->children.end(); ++n) {
      if ((*n)->growX) {
        (*n)->width = width;
        (*n)->y = node->x;
      }
      if ((*n)->growY) {
        (*n)->y = node->y;
        (*n)->height = height;
      }
    }
    node->render();
  }
}
