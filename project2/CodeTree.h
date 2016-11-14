
#ifndef PROJECT_CODETREE_H
#define PROJECT_CODETREE_H


#include "PriorityQueue.h"

class CodeTree {
    Node* tree;
public:
    CodeTree(PriorityQueue*);
    void printTree();
    void printCode();
    ~CodeTree();

private:
    void printChar(int);
    void recursePrintCodes(Node *head, std::string trail);
    void recursePrintTree(Node *head, int level);
    void printBars(int level);
    void printTreeHelper(Node * r, std::string pre);
};


#endif //PROJECT_CODETREE_H
