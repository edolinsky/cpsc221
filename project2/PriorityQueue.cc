
#include <cstdlib>
#include <iostream>
#include "PriorityQueue.h"
#include "Node.h"

PriorityQueue::PriorityQueue() {
    heap = std::vector<Node *>();
}

PriorityQueue::~PriorityQueue() {

}

/**
 * Retrieves the size of this Priority Queue
 * @return the size of theis Priority Queue
 */
long PriorityQueue::size() {
    return heap.size();
}

/**
 * Swaps a node up to its rightful place in this Priority Queue
 * @param i original index of node in heap to swap up
 */
void PriorityQueue::swapUp(long i) {
    if (i <= 0) return;
    long p = (i - 1) / 2;
    if (heap[i]->frequency < heap[p]->frequency) {
        Node *tmp = heap[i];
        heap[i] = heap[p];
        heap[p] = tmp;
        swapUp(p);
    }
}

/**
 * Swaps a node down to its rightful place in this Priority Queue
 * @param i original index of node in heap to swap down
 */
void PriorityQueue::swapDown(long i) {
    long size = heap.size();
    long leftChild = 2 * i + 1;
    long rightChild = 2 * i + 2;
    long min = i;

    // find who holds smallest element of i and its two children
    if (leftChild < size && heap[leftChild]->frequency < heap[min]->frequency)
        min = leftChild;
    if (rightChild < size && heap[rightChild]->frequency < heap[min]->frequency)
        min = rightChild;

    // if a child holds smallest element, swap i's element to that child
    // and recurse.
    if (min != i) {
        std::swap(heap[i], heap[min]);
        swapDown(min);
    }
}

/**
 * @deprecated
 *
 * heapifies this Priority Queue's heap vector
 */
void PriorityQueue::heapify() {
    long size = heap.size();
    for (long i = (size - 2) / 2; i >= 0; i--)
        swapDown(i);
}


/**
 * Inserts a new node in the Priority Queue
 * @param root root of tree
 * @param frequency key frequency to be inserted
 */
void PriorityQueue::insert(Node *node) {
    long n = heap.size();
    heap.insert(heap.end(), node);
    swapUp(n);
}

/**
 * Removes and returns the root node in this Priority Queue
 * @return the smallest (by frequency) node in this priority queue, or null if Queue is empty
 */
Node *PriorityQueue::popMin() {

    // return null pointer if empty
    if (heap.size() == 0) {
        return NULL;
    }

    // store root node, erase it, and reorder remaining elements
    Node *min = heap[0];
    heap.erase(heap.begin());
    swapDown(0);

    return min;
}

