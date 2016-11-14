
#ifndef PROJECT_PRIORITYQUEUE_H
#define PROJECT_PRIORITYQUEUE_H


#include <vector>
#include "Node.h"

class PriorityQueue {
    std::vector<Node *> heap;

public:
    PriorityQueue();

    long size();

    void insert(Node *node);

    Node *popMin();

    ~PriorityQueue();

private:
    void swapDown(long i);

    void swapUp(long i);

    /** @deprecated **/
    void heapify();
};


#endif //PROJECT_PRIORITYQUEUE_H
