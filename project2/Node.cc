
#include <cstdlib>
#include "Node.h"

Node::Node(int frequency, Node *left, Node *right, char character) {
    this->character = character;
    this->frequency = frequency;
    this->left = left;
    this->right = right;
}

Node::~Node() {

}
