

#ifndef PROJECT_CODETREE_H
#define PROJECT_CODETREE_H


#include "PriorityQueue.h"

class CodeTree {
    PriorityQueue *queue;
public:
    CodeTree(int *);
    void printTree();
    void printCode();
    ~CodeTree();

private:
    void printChar(int);
};


#endif //PROJECT_CODETREE_H
