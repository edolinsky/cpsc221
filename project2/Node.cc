
#include <cstdlib>
#include "Node.h"

Node::Node(int frequency, char character, Node *left, Node *right) {
    this->character = character;
    this->frequency = frequency;
    this->left = left;
    this->right = right;
}

Node::~Node() {

}
