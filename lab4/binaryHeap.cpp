#include <iostream>
#include <set>

using namespace std;

//PRE:  The capacity of the array pointed to by heap is at least size.
//POST: The first size elements of heap are printed to the screen.
void printList(int* heap, int size) {
    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";
    cout << endl;
}

// PRE:  subtrees rooted at leftChild and rightChild of i are heaps.
// POST: subtree rooted at i is a heap.
void swapDown(int* heap, int i, int size) {
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int min = i;
    // find who holds smallest element of i and its two children
    if (leftChild < size && heap[leftChild] < heap[min])
        min = leftChild;
    if (rightChild < size && heap[rightChild] < heap[min])
        min = rightChild;
    // if a child holds smallest element, swap i's element to that child
    // and recurse.
    if (min != i) {
        swap(heap[i], heap[min]);
        swapDown(heap, min, size);
    }
}

//PRE:  The capacity of the array pointed to by heap is at least size.
//POST: The first size elements of heap are a heap.
void heapify(int* heap, int size) {
    for (int i = (size - 2) / 2; i >= 0; i--)
        swapDown(heap, i, size);
}

//PRE:  The capacity of the array pointed to by heap is at least size.
//POST: The first size elements of heap are sorted in descending order.
void sort(int* heap, int size) {
    heapify(heap, size);  // Heapify algorithm
    for (int i = size - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
        swapDown(heap, 0, i);
    }
}

//PRE:  The capacity of the array pointed to by heap is at least size.
//      node is the index of the root of the current sub-tree and
//      it is at depth d in the whole heap
//POST: The first size elements of heap are printed as a tree
void printHeap(int *heap, int size, int node=0, int d=0) {

     //Q1
    /*
    if (size > 0) {
        cout << string((unsigned long) d, '*') << *(heap + node) << endl;    // print this node

        if (node * 2 + 1 < size) {      // if left child exists, print it and its children
            printHeap(heap, size, node * 2 + 1, d + 1);
            if (node * 2 + 2 < size) {   // if right child exists, print it and its children
                printHeap(heap, size, node * 2 + 2, d + 1);
            }
        }
    }
     */

    // Q2
    if (size > 0) {
        if (node * 2 + 2 < size) {       // if right child exists, print it and its children (children first)
            printHeap(heap, size, node * 2 + 2, d + 1);
        }

        cout << string((unsigned long) 2 * d, ' ') << *(heap + node) << endl;    // print this node

        if (node * 2 + 1 < size) {      // if left child exists, print it and its children (children first)
            printHeap(heap, size, node * 2 + 1, d + 1);
        }
    }

}

//PRE:  heap points to an array representing a heap
//      key is the value to be removed from the heap
//      size is the number of elements in the heap
//POST: all elements with key value = key have been removed from
//	the heap and size is the new heap size.
void remove(int* heap, int key, int & size) {

    // Asymptotic time complexity is O(size * lg(size)) worst case, as we evaluate each node only once; swapDown takes O(lg(size))
    for (int i = 0; i < size; i++) { // iterate over nodes in heap
        if (heap[i] == key) {           // if node matches key,
            heap[i] = heap[size - 1];   // swap out for element at end
            size--;                     // decrement size
            swapDown(heap, i,size);     // swap node down to validate heap
            i--;                        // evaluate this node again in case key node was swapped in
        }
    }

    /*
    // O(size) when all nodes match, but up to O(4 * size) when no nodes match
    // Asymptotic time complexity is O(size), as first iteration takes O(size), heapify takes O(newSize),
    // second iteration takes O(newSize), and newSize <= size.
    int newSize = 0;
    int* newHeap = new int[size];

    for (int i = 0; i < size; i++) {
        if (heap[i] != key) {
            newHeap[newSize] = heap[i];
            newSize++;
        }
    }

    heapify(newHeap, newSize);

    for (int i = 0; i < newSize; i++) {
        heap[i] = newHeap[i];
    }

    size = newSize;
    delete newHeap;
     */
}

//PRE:  heap1 and heap2 contain size1 and size2 elements respectively.
//POST: output a new heap (whose size is size1+size2) containing all
//      the elements in heap1 and heap2 (including duplicates).
int* mergeHeap(int* heap1, int* heap2, int size1, int size2) {

    // Asymptotic time complexity is O(size1+size2), as heap1 iteration takes O(size1), heap2 iteration takes O(size2),
    // and heapify takes O(size1+size2).

    int* mergedHeap = new int[size1 + size2];    // allocate space for new heap

    int size = 0;   // size of merged heap
    for (int i = 0; i < size1; i++, size++) {   // copy elements from heap 1
        mergedHeap[size] = heap1[i];
    }
    for (int i = 0; i < size2; i++, size++) {   // copy elements from heap 2
        mergedHeap[size] = heap2[i];
    }

    heapify(mergedHeap, size);      // heapify merged list

    return mergedHeap;
}

int input1[] = {8,3,5,6,2,9,1,7,4,0};
int input2[] = {4,6,1,8,2,3};
int input3[] = {2,2,2,2,2,2,2};

int main() {
    int size1 = sizeof(input1)/sizeof(int);
    int *heap1 = new int[size1];
    for (int i = 0; i < size1; ++i) {
        heap1[i] = input1[i];
    }

    heapify(heap1, size1);
    cout << "heap1: ";
    printList(heap1, size1);
    printHeap(heap1, size1);

    int size2 = sizeof(input2)/sizeof(int);
    int *heap2 = new int[size2];
    for (int i = 0; i < size2; ++i) {
        heap2[i] = input2[i];
    }

    heapify(heap2, size2);
    cout << "heap2: ";
    printList(heap2, size2);
    printHeap(heap2, size2);

    int size3 = sizeof(input3)/sizeof(int);
    int *heap3 = new int[size3];
    for (int i = 0; i < size3; ++i) {
        heap3[i] = input3[i];
    }

    heapify(heap3, size3);
    cout << "heap3: ";
    printList(heap3, size3);
    printHeap(heap3, size3);

    remove(heap1, 0, size1);
    cout << "heap1, remove(0): ";
    printList(heap1, size1);
    printHeap(heap1, size1);

    remove(heap2, 8, size2);
    cout << "heap2, remove(8): ";
    printList(heap2, size2);
    printHeap(heap2, size2);

    remove(heap3, 2, size3);
    cout << "heap3, remove(2): ";
    printList(heap3, size3);
    printHeap(heap3, size3);

    remove(heap3, 2, size3);
    cout << "heap3, remove(2): ";
    printList(heap3, size3);
    printHeap(heap3, size3);

    int *heap = mergeHeap(heap1, heap2, size1, size2);
    int size = size1 + size2;

    if (heap != NULL) {
        cout << "merged: ";
        printList(heap, size);
        printHeap(heap, size);
        
        remove(heap, 2, size);
        
        cout << "remove(2): ";
        printList(heap, size);
        printHeap(heap, size);
        
        delete[] heap;
    }
    
    delete[] heap1;
    delete[] heap2;
    delete[] heap3;
    
    return 0;
}
