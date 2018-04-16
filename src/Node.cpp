#include "oggy/Node.hpp"
#include <iostream>
#include "oggy/Canvas.hpp"

oggy::Node::Node() {

}

oggy::Node::~Node() {

}

oggy::Node::Node(Canvas * canvas) {
  this->canvas = canvas;
}

void oggy::Node::addChild(oggy::Node * node) {
  this->children.push_back(node);
  node->parent = this;
  node->canvas = this->canvas;
}
