// linked_list.cc -- functions for linked_list lab (cs221) 

#include "linked_list.h"

/**
 * Inserts a new Node (with key=newKey) at the head of the linked_list.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: newKey is the value for the key in the new Node 
 * POST: the new Node is now the head of the linked_list
 */ 
void insert(Node*& head, int newKey) {
    Node * curr = new Node;
    curr->key  = newKey;
    curr->next = head;

    head = curr;
}

/**
 * Print the keys of a linked_list in order, from head to tail 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
void print(Node* head) {
    std::cout << "[";
    for (Node* curr = head; curr != NULL; curr = curr->next){
        std::cout << curr->key;
        if (curr->next != NULL) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

/** 
 * Returns the size (number of Nodes) of the linked_list  
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
int size(Node* head){ 
    if (! head) return 0;
    return 1 + size(head->next);
}

/**
 * Copies the keys in a linked list to a vector.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * POST: a new vector<int> containing the keys in the correct order has been returned.  
 */ 
std::vector<int> to_vector(Node* head) {
    std::vector<int> result;
    for (Node* curr = head; curr != NULL; curr = curr->next){
        result.push_back(curr->key);
    }
    return result;
}

/** 
 * Delete the last Node in the linked_list
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * POST: the last Node of the linked_list has been removed
 * POST: if the linked_list is now empty, head has been changed
 * POST: else head remains the first Node in the linked_list
 */
void delete_last_element(Node*& head){

    if (head->next == NULL) {       // if head is only element,
        delete head;                // delete head
        head = NULL;

    } else if (&head != NULL) {     // otherwise
        Node* end = head->next;
        Node* penultimate = head;

        while (end->next != NULL){  // iterate over elements until we're at the end
            penultimate = end;
            end = end->next;
        }

        delete end;                 // delete end node and allocate new end
        penultimate->next = NULL;
    }
}

/**
 * Removes an existing Node (with key=oldKey) from the linked_list. 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value of the key in the Node to be removed 
 * PRE: if no Node with key=oldKey exists, the linked_list has not changed 
 * POST: if a Node with key=oldKey was found, then it was deleted
 * POST: other Nodes with key=oldKey might still be in the linked_list
 * POST: head is the new first Node of the linked_list, if updated
 */ 
void remove(Node*& head, int oldKey) {

    Node* right = head->next;
    Node* left = head;

    if (&head == NULL) {                    // do nothing if empty
        return;

    } else if (head->key == oldKey) {       // key corresponds to head

        if (head->next == NULL) {           // if head is sole member, delete and point to null
            delete head;
            head = NULL;
        } else {
            Node* temp = head;             // otherwise, delete and allocate new head
            head = head->next;
            delete temp;
        }

    } else {

        while (right->next != NULL) {       // iterate through list

            if(right->key == oldKey) {      // if a match is found, link previous node to next
                Node *temp = right;
                left->next = right->next;
                delete temp;                // and delete matching node
                return;
            }

            left = left->next;              // iterate to next pair
            right = left->next->next;
        }

        if (right->key == oldKey) {         // if at end, delete end node and allocate new end
            delete right;
            left->next = NULL;
        }
    }
}

/**
 * Insert a new Node (with key=newKey) after an existing Node (with key=oldKey)
 * If there is no existing Node with key=oldKey, then no action.
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value to look for (in the key of an existing Node)  
 * PRE: newKey is the value of the key in the new Node (that might be inserted) 
 * POST: if no Node with key=oldKey was found, then the linked_list has not changed
 * POST: else a new Node (with key=newKey) is right after the Node with key = oldKey.
 */
void insert_after(Node* head, int oldKey, int newKey){

    if (head != NULL) {                         // do nothing if empty
        Node* oldNode = head;

        while (oldNode->next != NULL) {         // iterate through list

            if(oldNode->key == oldKey) {        // if key of node matches oldKey
                Node* newNode = new Node;       // create new node with key newKey
                newNode->key = newKey;

                newNode->next = oldNode->next;  // and place it in list after oldNode
                oldNode->next = newNode;
                return;                         // return here; we don't want to do any more
            }
            oldNode = oldNode->next;
        }

        if (oldNode->key == oldKey) {           // If key of last node matches,
            Node* newNode = new Node;           // create new node with key newKey
            newNode->key = newKey;

            newNode->next = NULL;               // place new node at end of list, pointing to NULL
            oldNode->next = newNode;
        }
    }
}


/** 
 * Create a new linked_list by merging two existing linked_lists. 
 * PRE: list1 is the first Node in a linked_list (if NULL, then it is empty)
 * PRE: list2 is the first Node in another linked_list (if NULL, then it is empty)
 * POST: A new linked_list is returned that contains new Nodes with the keys from 
 * the Nodes in list1 and list2, starting with the key of the first Node of list1, 
 * then the key of the first Node of list2, etc. 
 * When one list is exhausted, the remaining keys come from the other list.
 * For example: [1, 2] and [3, 4, 5] would return [1, 3, 2, 4, 5]
 */
Node* interleave(Node* list1, Node* list2){
    Node* newList = new Node;
    Node* newNode = newList;
    Node* node1 = list1;
    Node* node2 = list2;

    if(node1) {                     // initialize first element if available
        newNode->key = node1->key;
        node1 = node1->next;
    } else if (node2){
        newNode->key = node2->key;
        node2 = node2->next;
    } else {                        // if no elements available, both lists are empty
        return NULL;
    }

    while (node1 != NULL && node2 != NULL) {    // iterate through both lists until we reach the end of one

        Node* tempNode1 = new Node;     // create new nodes
        Node* tempNode2 = new Node;

        tempNode1->key = node1->key;    // copy respective keys
        tempNode2->key = node2->key;

        newNode->next = tempNode2;      // add pair of nodes in order
        tempNode2->next = tempNode1;
        newNode = tempNode1;

        node1 = node1->next;            // get next pair
        node2 = node2->next;
    }

    if (node1 == NULL) {                    // if list 1 is empty, copy remainder of list 2
        while (node2 != NULL) {
            Node* tempNode = new Node;
            tempNode->key = node2->key;
            newNode->next = tempNode;
            newNode = tempNode;
            node2 = node2->next;
        }
    } else {                                // otherwise, list 2 is empty. Copy remainder of list 1.
        while (node1 != NULL) {
            Node* tempNode = new Node;
            tempNode->key = node1->key;
            newNode->next = tempNode;
            newNode = tempNode;
            node1 = node1->next;
        }
    }

    return newList;
}