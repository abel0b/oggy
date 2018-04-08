#include "Node.hpp"
#include <iostream>
#include "Canvas.hpp"

magui::Node::Node() {

}

magui::Node::~Node() {

}

magui::Node::Node(Canvas * canvas) {
  this->canvas = canvas;
}

void magui::Node::addChild(magui::Node * node) {
  this->children.push_back(node);
  node->parent = this;
  node->canvas = this->canvas;
}
