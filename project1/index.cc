#include <iostream>
#include <fstream>
#include <sstream>
#include <string>       // provides string class
#include <cctype>       // provides isalpha() and tolower()
#include <vector>
#include <algorithm>
#include <cmath>
#include "Entry.h"

#define PAGE_LENGTH 40

long find(std::string targetWord, std::vector<Entry>& words);
Entry * insert(std::string, std::vector<Entry>& words);

// The following function should be moved into your skiplist.cc file when you
// write that.  It implements the random bit generation.
#include <ctime>                // for time()
#include <cstdlib>              // for rand(), srand(), and RAND_MAX

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

// Remove all characters except letters (A-Z,a-z) from line,
// except keep '-' or '\'' if they are between letters.
void lowercaseWords(std::string & line) {
    for( std::string::iterator it = line.begin(); it != line.end(); ++it ) {
        if( !isalpha(*it) ) {
            if( (*it != '-' && *it != '\'') ||
                it == line.begin() || it+1 == line.end() ||
                !isalpha(*(it-1)) || !isalpha(*(it+1)) ) {
                    *it = ' ';
                }
        } else {
            *it = tolower(*it);
        }
    }
}

void print(std::ostream & output, std::string & word) {
    output << word << std::endl;
}
/**
 * Find the index of a particular Entry in a list using a non-recursive binary search
 * @param targetWord A string containing a single word which we wish to find in words
 * @param words A vector of Entry structs, ordered by the value of their string 'word'
 * @return index of targetWord in words, or -1 if not found
 */
long find(std::string targetWord, std::vector<Entry>& words) {
    long bottom = 0;
    long top = (long)words.size() - 1;
    unsigned long middle;

    while (bottom <= top) {                            // exit only if we did not find anything

        middle = (unsigned long)bottom + ((top - bottom) / 2);     // find integer middle index (left on even size) in words

        if (targetWord.compare(words.at(middle).getWord()) == 0) {        // return middle if it matches our word
            return middle;
        } else if (targetWord.compare(words.at(middle).getWord()) < 0) {  // take lower half if target is less than middle
            top = middle - 1;
        } else if (targetWord.compare(words.at(middle).getWord()) > 0) {  // take upper half if target is more than middle
            bottom = middle + 1;
        }
    }

    return -1;      // we have not found anything
}

/**
 *
 * @param newWord string containing a single word to be inserted
 * @param words vector of word entries in which to insert newWord
 * @return index of inserted newWord in words
 */
Entry * insert(std::string newWord, std::vector<Entry>& words) {

    // create new entry
    Entry *newEntry = new Entry(newWord);
    std::vector<Entry>::iterator it;

    if (words.size() == size_t(0)) {    // if words is empty, add first word
        words.push_back(*newEntry);
    } else {                            // otherwise, find insertion point

        for (it = words.begin(); it != words.end(); ++it) {
            if (it->getWord() > newWord) {   // if word here is alphabetically larger, this is where this word should go
                break;
            }
        }
        words.insert(it, *newEntry);    // insert word here
    }

    return newEntry;
}

void printInOrder(std::ostream & output, std::vector<Entry>& words) {
    std::stringstream info; // message buffer
    std::string out;        // string output

    for( std::vector<Entry>::iterator it = words.begin(); it != words.end(); it++) {    // iterate through word list
        it->printTo(&info);
    }
    out = info.str();       // convert buffer to string
    print(output, out);     // print string
}

int main(int argc, char *argv[]) {
    if( argc != 3 ) {
        std::cerr << "Usage: " << argv[0] << " book.txt index.txt" << std::endl;
        exit(1);
    }

    std::ifstream fin;
    fin.open(argv[1]);
    if( !fin.is_open() ) {
        std::cerr << "Unable to open " << argv[1] << std::endl;
        exit(2);
    }

    std::ofstream fout;
    fout.open(argv[2]);
    if( !fout.is_open() ) {
        std::cerr << "Unable to open " << argv[2] << std::endl;
        exit(3);
    }

    std::string line, word;
    std::vector<Entry> words;
    int lineNum = 1;    // line tracker

    while( !fin.eof() ) {                   // iterate over lines
        getline(fin,line);
        lowercaseWords(line);               // convert to lowercase
        std::istringstream iss(line, std::istringstream::in);
        while( iss >> word ) {              // iterate over words in line
            long index = find(word, words); // find word in list of words
            Entry *entry;
            if(index >= 0){                             // if found
                entry = &words.at((unsigned long)index);
                entry->incrementCount();                // increment count
            } else {
                entry = insert(word, words);                    // if not found, add to list

            }

            // add page number to this word's page list if unique
            entry->foundOnPage((int) std::floor(lineNum / PAGE_LENGTH + 1));
        }
        // increment line tracker
        lineNum++;
    }

    // print result to file
    printInOrder(fout, words);
}
