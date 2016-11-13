
#include <iostream>
#include "CodeTree.h"
#include "PriorityQueue.h"

CodeTree::CodeTree(int * characters) {
    std::vector<Node> nodeVector;
    // todo: create vector of nodes with characters and frequencies of each character
    queue = new PriorityQueue(nodeVector);

    // todo: Huffman coding
}

CodeTree::~CodeTree(){

}

void CodeTree::printTree() {
    // todo: implement
}

void CodeTree::printCode() {
    // todo: implement
}

void CodeTree::printChar(int ch) {
    if( ch < 16 ) {
        std::cout << "x0" << std::hex << ch;
    } else if( ch < 32 || ch > 126 ) {
        std::cout << "x" << std::hex << ch;
    } else {
        std::cout << "\"" << (char)ch << "\"";
    }
}
