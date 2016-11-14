
#ifndef PROJECT_CODETREE_H
#define PROJECT_CODETREE_H


#include "PriorityQueue.h"

class CodeTree {
    Node *tree;

public:
    CodeTree(PriorityQueue *);

    void printTree();

    void printCode();

    ~CodeTree();

private:
    void printChar(int);

    void printTreeHelper(Node *r, std::string pre = "");

    void recursePrintCodes(Node *head, std::string trail = "");

    /** @deprecated **/
    void recursePrintTree(Node *head, int level);

    /** @deprecated **/
    void printBars(int level);
};


#endif //PROJECT_CODETREE_H
