
#include <iostream>
#include "CodeTree.h"
#include "PriorityQueue.h"

CodeTree::CodeTree(PriorityQueue *queue) {

    // create codetree by combining two smallest nodes, until only one node is left
    while (queue->size() > 1) {
        Node *one = queue->popMin();
        Node *two = queue->popMin();

        Node *parent = new Node(one->frequency + two->frequency, NULL, one, two);
        queue->insert(parent);
    }

    // get codetree
    tree = queue->popMin();
}

CodeTree::~CodeTree() {

}

/**
 * Prints a full codetree, including branch labels and characters at leaves
 */
void CodeTree::printTree() {
    printTreeHelper(tree, "");
}


/**
 * @deprecated
 *
 * Prints a (rather funky) codetree.
 * @param head head node of codetree
 * @param level depth of node in tree
 */
void CodeTree::recursePrintTree(Node *head, int level) {
    if (head->character != NULL) {
        // leaf
        printChar(head->character);
        std::cout << std::endl;

    } else {
        // start subtree with a dot
        std::cout << '.' << std::endl;

        // print right subtreetree:
        printBars(level);
        std::cout << "`1-";
        recursePrintTree(head->right, level + 1);

        // print middle
        printBars(level);
        std::cout << std::endl;

        // print left subtree
        printBars(level);
        std::cout << "`-0-";
        recursePrintTree(head->left, level + 1);
    }

}

/**
 * Recursive helper function for formatting printed tree
 * @param r node in tree
 * @param pre string to be printed before node
 */
void CodeTree::printTreeHelper(Node *r, std::string pre) {

    if (r == NULL) return;

    if (r->right == NULL) { // implies r->left == NULL
        printChar(r->character);
        std::cout << std::endl;

    } else {
        std::cout << "." << std::endl;
        std::cout << pre << "|`1-";
        printTreeHelper(r->right, pre + "|   ");
        std::cout << pre + "|   " << std::endl;
        std::cout << pre << "`-0-";
        printTreeHelper(r->left, pre + "    ");
    }
}

/**
 * @deprecated
 *
 * Prints bars for use in printing a code tree
 * @param level number of spaced bars to be printed
 */
void CodeTree::printBars(int level) {

    std::cout << '|';
    for (int i = 0; i < level; i++) {
        std::cout << '\t' << '|';
    }
}

/**
 * Prints list of characters and codes in codetree
 */
void CodeTree::printCode() {
    recursePrintCodes(tree, "");
}

/**
 * Recursively prints a list of characters and codes in codetree
 * @param head root node in codetree
 * @param trail path to node in codetree (start with empty string)
 */
void CodeTree::recursePrintCodes(Node *head, std::string trail) {

    if (head->character != NULL) {
        printChar(head->character);
        std::cout << ":" << trail << std::endl;

    } else {
        recursePrintCodes(head->left, trail + "0");
        recursePrintCodes(head->right, trail + "1");
    }
}

/**
 * Prints the character corresponding to the specified integer (hex value if invalid character)
 * @param ch integer representing character to be printed
 */
void CodeTree::printChar(int ch) {

    if (ch < 16) {
        std::cout << "x0" << std::hex << ch;

    } else if (ch < 32 || ch > 126) {
        std::cout << "x" << std::hex << ch;

    } else {
        std::cout << "\"" << (char) ch << "\"";
    }
}
