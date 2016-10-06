#include <iostream>
#include <fstream>
#include <sstream>
#include <string>       // provides string class
#include <cctype>       // provides isalpha() and tolower()
#include <vector>
#include <algorithm>
#include <cmath>

#define PAGE_LENGTH 40

struct entry {
    std::string word;
    int count;
    std::vector<int> pages;
};

long find(std::string targetWord, std::vector<entry>& words);
void insert(std::string, std::vector<entry>& words);
void printInOrder(std::ostream & output, std::vector<entry>& words);
void insertUniquePage(int page, std::vector<int>& pages);


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

/**
 * Inserts a page number into vector of pages only if the page does not already exist in that vector
 * @param page integer denoting page number
 * @param pages vector of page numbers
 */
void insertUniquePage(int page, std::vector<int>& pages) {
    std::vector<int>::iterator it;

    if (pages.size() == size_t(0)) {        // if pages is empty, add first page
        pages.push_back(page);
    } else {                                // otherwise, find where page number should belong

        for (it = pages.begin(); it != pages.end(); ++it) {
            if (*it > page) {           // if value at this index is greater, this is where page number should go
                break;
            } else if (*it == page) {   // if this page already exists in list, do nothing
                return;
            }
        }
        pages.insert(it, page);         // insert page at desired index
    }
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
 * Find the index of a particular entry in a list using a non-recursive binary search
 * @param targetWord A string containing a single word which we wish to find in words
 * @param words A vector of entry structs, ordered by the value of their string 'word'
 * @return index of targetWord in words, or -1 if not found
 */
long find(std::string targetWord, std::vector<entry>& words) {
    long bottom = 0;
    long top = (long)words.size() - 1;
    unsigned long middle;

    while (bottom <= top) {                            // exit only if we did not find anything

        middle = (unsigned long)bottom + ((top - bottom) / 2);     // find integer middle index (left on even size) in words

        if (targetWord.compare(words.at(middle).word) == 0) {        // return middle if it matches our word
            return middle;
        } else if (targetWord.compare(words.at(middle).word) < 0) {  // take lower half if target is less than middle
            top = middle - 1;
        } else if (targetWord.compare(words.at(middle).word) > 0) {  // take upper half if target is more than middle
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
void insert(std::string newWord, std::vector<entry>& words) {

    // create new entry
    entry *newEntry = new entry;
    newEntry->word = newWord;
    newEntry->count = 1;
    std::vector<entry>::iterator it;

    if (words.size() == size_t(0)) {    // if words is empty, add first word
        words.push_back(*newEntry);
    } else {                            // otherwise, find insertion point

        for (it = words.begin(); it != words.end(); ++it) {
            if (it->word > newWord) {   // if word here is alphabetically larger, this is where this word should go
                break;
            }
        }
        words.insert(it, *newEntry);    // insert word here
    }
}

void printInOrder(std::ostream & output, std::vector<entry>& words) {
    std::stringstream info; // message buffer
    std::string out;        // string output

    for( std::vector<entry>::iterator it = words.begin(); it != words.end(); it++) {    // iterate through word list
        std::string page_separator = "";                // initialize separator for page numbers
        info << it->word << " (" << it->count << ") ";  // concat word and number of times it was found

        // iterate over page list
        for (std::vector<int>::iterator page = it->pages.begin(); page != it->pages.end(); page++) {

            info << page_separator << *page;    // add page number
            page_separator = ",";               // change separator after first iteration

        }
        info << std::endl;                      // end line after page numbers
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
    std::vector<entry> words;
    int lineNum = 1;    // line tracker

    while( !fin.eof() ) {                   // iterate over lines
        getline(fin,line);
        lowercaseWords(line);               // convert to lowercase
        std::istringstream iss(line, std::istringstream::in);
        while( iss >> word ) {              // iterate over words in line
            long index = find(word, words); // find word in list of words
            if(index >= 0){                             // if found
                words.at((unsigned long)index).count++; // increment count
            } else {
                insert(word, words);                    // if not found, add to list
            }

            // add page number to this word's page list if unique
            insertUniquePage((int) std::floor(lineNum / PAGE_LENGTH + 1), words.at((unsigned long) find(word, words)).pages);
        }
        // increment line tracker
        lineNum++;
    }

    // print result to file
    printInOrder(fout, words);
}
