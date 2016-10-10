#ifndef PROJECT_SKIPLIST_H
#define PROJECT_SKIPLIST_H

#include "Entry.h"

#define MAX_HEIGHT 16

class skiplist {
    struct Node {
        Entry* entry; // head needs to be able to be null so again we need a pointer here...
        int height;
        Node *next[MAX_HEIGHT];
    };

    Node* head;

public:
    skiplist();
    int randHeight();
    Entry* find(std::string word); // needs a pointer return type in order to signal not found with a NULL
    Entry* insert(std::string word);
    void printInOrder(std::ostream & output);
    ~skiplist();
};

#endif //PROJECT_SKIPLIST_H