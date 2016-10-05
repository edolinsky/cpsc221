#include <iostream>
#include <fstream>
#include <sstream>
#include <string>       // provides string class
#include <cctype>       // provides isalpha() and tolower()
#include <vector>
#include <algorithm>

struct entry {
    std::string word;
    int count;
};

long find(std::string targetWord);
void insert(std::string);
void printInOrder(std::ostream & output);

std::vector<entry> words;

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
 * Find the index of a particular entry in a list using a non-recursive binary search
 * @param targetWord A string containing a single word which we wish to find in words
 * @param words A vector of entry structs, ordered by the value of their string 'word'
 * @return index of targetWord in words, or -1 if not found
 */
long find(std::string targetWord) {
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

void insert(std::string newWord) {

    // create new entry
    entry *newEntry = new entry;
    newEntry->word = newWord;
    newEntry->count = 1;

    if (words.size() == size_t(0)) {
        words.push_back(*newEntry);
    } else {

        // Find insertion point and insert new entry
        std::vector<entry>::iterator it;
        for (it = words.begin(); it != words.end(); ++it) {
            if (it->word > newWord) {
                break;
            }
        }
        words.insert(it, *newEntry);
    }
}

void printInOrder(std::ostream & output) {
    std::stringstream info;
    std::string out;
    for(std::vector<entry>::iterator it = words.begin(); it != words.end(); it++) {
        info << it->word << " (" << it->count << ")" << std::endl;
    }
    out = info.str();
    print(output, out);
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


    while( !fin.eof() ) {
        getline(fin,line);
        lowercaseWords(line);
        std::istringstream iss(line, std::istringstream::in);
        while( iss >> word ) {
            long index = find(word);
            if(index >= 0){
                words.at((unsigned long)index).count++;
            } else {
                insert(word);
            }
        }
    }

    printInOrder(fout);
}
