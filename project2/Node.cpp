
#include <cstdlib>
#include "Node.h"

Node::Node(int frequency, char character = NULL, Node *left = NULL, Node *right = NULL) {
    this->character = character;
    this->frequency = frequency;
    this->left = left;
    this->right = right;
}

Node::~Node() {

}
