
#ifndef PROJECT_NODE_H
#define PROJECT_NODE_H


class Node {
public:
    char character;
    int frequency;
    Node * left;
    Node * right;

    Node(int frequency, char character = NULL, Node *left = NULL, Node *right = NULL);
    ~Node();
};


#endif //PROJECT_NODE_H
