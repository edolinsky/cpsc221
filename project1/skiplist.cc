#include <ctime>                // for time()
#include <cstdlib>              // for rand(), srand(), and RAND_MAX
#include <string>
#include "skiplist.h"

skiplist::skiplist() {
    head = new Node;
    head->entry = NULL;
    head->height = MAX_HEIGHT;
}
skiplist::~skiplist() {
    // iterate through the nodes and delete each one
    Node* curr = head;
    Node* next;
    while (curr) {
        next = curr->next[0];
        delete curr;
        curr = next;
    }
}

int randBit(void) {             // return a "random" bit
    static int bitsUpperBd=0;
    static int bits;              // store bits returned by rand()
    if( bitsUpperBd == 0 ) {      // refresh store when empty
        bitsUpperBd = RAND_MAX;
        bits = rand();
    }
    int b = bits & 1;
    bits >>= 1;
    bitsUpperBd >>= 1;
    return b;
}

int skiplist::randHeight() {
    int height = 1;
    for (int i = 1; i < MAX_HEIGHT; i++) {
        if (randBit() == 1) {
            height = i;
            break;
        }
    }
    return height;
}

/**
 * Find the index of a particular Entry in a list using a non-recursive binary search
 * @param targetWord A string containing a single word which we wish to find in words
 * @param words A vector of Entry structs, ordered by the value of their string 'word'
 * @return index of targetWord in words, or -1 if not found
 */
Entry* skiplist::find(std::string targetWord) {
    Node* node = head;
    int height = MAX_HEIGHT - 1;

    while (height >= 0) {
        Node* search = node->next[height];

        while (search != NULL) {
            int compare = targetWord.compare(search->entry->getWord());

            if (compare == 0) {
                // if it is a match, return it
                return search->entry;
            } else if (compare > 0) {
                // compared string is shorter, advance to the searched node and repeat at same height level
                node = search;
                search = node->next[height];
            } else {
                break;
            }
        }

        // if search was null or bigger than the desired value we step down a height level
        height--;
    }

    return NULL;
}

/**
 *
 * @param newWord string containing a single word to be inserted
 * @param words vector of word entries in which to insert newWord
 * @return index of inserted newWord in words
 */
Entry* skiplist::insert(std::string newWord) {
    Node* node = head;
    int height = MAX_HEIGHT - 1;
    Node* visited[MAX_HEIGHT];

    while (height >= 0) {
        Node* search = node->next[height];

        while (search != NULL) {
            int compare = newWord.compare(search->entry->getWord());

            if (compare == 0) {
                // if it is a match, return it
                return search->entry;
            } else if (compare > 0) {
                // compared string is shorter, advance to the searched node and repeat at same height level
                node = search;
                search = node->next[height];
            } else {
                break;
            }
        }

        visited[height] = node;
        // if search was null or bigger than the desired value we step down a height level
        height--;
    }

    // didn't find it so do an insert:

    // create new entry and a random height
    Node* newNode = new Node;
    newNode->entry = new Entry(newWord);
    newNode->height = randHeight();

    // readjust pointers
    for (int h = 0; h < newNode->height; h++) {
        newNode->next[h] = visited[h]->next[h];
        visited[h]->next[h] = newNode;
    }

    return newNode->entry;
}

void print(std::ostream & output, std::string & word) {
    output << word << std::endl;
}

void skiplist::printInOrder(std::ostream & output) {
    std::stringstream info; // message buffer
    std::string out;        // string output

    Node* curr = head->next[0];
    while (curr) {
        curr->entry->printTo(&info);
        curr = curr->next[0];
    }

    out = info.str();       // convert buffer to string
    print(output, out);     // print string
}