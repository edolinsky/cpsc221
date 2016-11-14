
#include <iostream>
#include "CodeTree.h"
#include "PriorityQueue.h"

CodeTree::CodeTree(PriorityQueue *queue) {
  while (queue->size() > 1) {
    Node *one = queue->popMin();
    Node *two = queue->popMin();

    Node *parent = new Node(one->frequency + two->frequency, NULL, one, two);
    queue->insert(parent);
  }

  tree = queue->popMin();
}

CodeTree::~CodeTree() {

}

void CodeTree::printTree() {
  printTreeHelper(tree, "");
}

void CodeTree::recursePrintTree(Node *head, int level) {
  if (head->character != NULL) {
    // leaf
    printChar(head->character);
    std::cout << std::endl;

  } else {
    // start subtree with a dot
    std::cout << '.' << std::endl;

    // print right subtreetree:
    printBars(level);
    std::cout << "`1-";
    recursePrintTree(head->right, level + 1);

    // print middle
    printBars(level);
    std::cout << std::endl;

    // print left subtree
    printBars(level);
    std::cout << "`-0-";
    recursePrintTree(head->left, level + 1);
  }

}

void CodeTree::printTreeHelper(Node *r, std::string pre) {
  if (r == NULL) return;
  if (r->right == NULL) { // implies r->left == NULL
    printChar(r->character);
    std::cout << std::endl;
  } else {
    std::cout << "." << std::endl;
    std::cout << pre << "|`1-";
    printTreeHelper(r->right, pre + "|   ");
    std::cout << pre + "|   " << std::endl;
    std::cout << pre << "`-0-";
    printTreeHelper(r->left, pre + "    ");
  }
}

void CodeTree::printBars(int level) {
  std::cout << '|';
  for (int i = 0; i < level; i++) {
    std::cout << '\t' << '|';
  }
}

void CodeTree::printCode() {
  recursePrintCodes(tree, "");
}

void CodeTree::recursePrintCodes(Node *head, std::string trail) {
  if (head->character != NULL) {
    printChar(head->character);
    std::cout << ":" << trail << std::endl;
  } else {
    recursePrintCodes(head->left, trail + "0");
    recursePrintCodes(head->right, trail + "1");
  }
}

void CodeTree::printChar(int ch) {
  if (ch < 16) {
    std::cout << "x0" << std::hex << ch;
  } else if (ch < 32 || ch > 126) {
    std::cout << "x" << std::hex << ch;
  } else {
    std::cout << "\"" << (char) ch << "\"";
  }
}
