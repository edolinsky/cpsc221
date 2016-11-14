
#ifndef PROJECT_NODE_H
#define PROJECT_NODE_H


class Node {

public:
    char character;
    int frequency;
    Node *left;
    Node *right;

    // -1 used for value of null character
    Node(int frequency, Node *left = NULL, Node *right = NULL, char character = -1);

    ~Node();
};


#endif //PROJECT_NODE_H
