
#ifndef PROJECT_PRIORITYQUEUE_H
#define PROJECT_PRIORITYQUEUE_H


#include <vector>
#include "Node.h"

class PriorityQueue {
    std::vector<Node> heap;

public:
    PriorityQueue(std::vector<Node> nodeVector);
    void insert(Node* node);
    Node * popMin();
    ~PriorityQueue();
private:
    void swapDown(long i);
    void swapUp(long i);
    void heapify();
};


#endif //PROJECT_PRIORITYQUEUE_H
