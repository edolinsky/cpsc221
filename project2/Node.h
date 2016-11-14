
#ifndef PROJECT_NODE_H
#define PROJECT_NODE_H


class Node {

public:
    static const int NULL_CHAR  = -1; // -1 used for value of null character
    char character;
    int frequency;
    Node *left;
    Node *right;

    Node(int frequency, Node *left = NULL, Node *right = NULL, char character = NULL_CHAR);

    ~Node();
};


#endif //PROJECT_NODE_H
