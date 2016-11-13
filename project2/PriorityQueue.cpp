
#include <cstdlib>
#include <iostream>
#include "PriorityQueue.h"
#include "Node.h"

PriorityQueue::PriorityQueue(std::vector<Node> nodeVector) {
    heap = nodeVector;
    heapify();
}

PriorityQueue::~PriorityQueue() {

}

/**
 * Swaps a node up to its rightful place in the heap
 * @param i original index of node in heap to swap up
 */
void PriorityQueue::swapUp(long i) {
    if( i == 0 ) return;
    long p = (i - 1)/2;
    if( heap[i].frequency < heap[p].frequency ) {
        Node tmp = heap[i];
        heap[i] = heap[p];
        heap[p] = tmp;
        swapUp(p);
    }
}

/**
 * Swaps a node down to its rightful place in the heap
 * @param i original index of node in heap to swap down
 */
void PriorityQueue::swapDown(long i) {
    long size = heap.size();
    long leftChild = 2 * i + 1;
    long rightChild = 2 * i + 2;
    long min = i;

    // find who holds smallest element of i and its two children
    if (leftChild < size && heap[leftChild].frequency < heap[min].frequency)
        min = leftChild;
    if (rightChild < size && heap[rightChild].frequency < heap[min].frequency)
        min = rightChild;

    // if a child holds smallest element, swap i's element to that child
    // and recurse.
    if (min != i) {
        std::swap(heap[i], heap[min]);
        swapDown(min);
    }
}

void PriorityQueue::heapify() {
    long size = heap.size();
    for (long i = (size - 2) / 2; i >= 0; i--)
        swapDown(i);
}


/**
 * Inserts a new node in the heap
 * @param root root of tree
 * @param frequency key frequency to be inserted
 */
void PriorityQueue::insert(Node * node) {
    long n = heap.size();
    heap.insert(heap.end(), *node);
    swapUp(n-1);
}

/**
 *
 * @return
 */
Node * PriorityQueue::popMin() {
    if (heap.size() == 0) {
        return NULL;
    }
    Node * min = &heap[0];
    heap.erase(heap.begin());
    swapDown(0);

    return min;
}

