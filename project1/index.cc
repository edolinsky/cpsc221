#include <iostream>
#include <fstream>
#include <sstream>
#include <string>       // provides string class
#include <cctype>       // provides isalpha() and tolower()
#include <vector>
#include <algorithm>
#include <cmath>
#include "Entry.h"
#include "skiplist.h"

#define PAGE_LENGTH 40

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
    skiplist words;
    int lineNum = 1;    // line tracker

    while( !fin.eof() ) {                   // iterate over lines
        getline(fin,line);
        lowercaseWords(line);               // convert to lowercase
        std::istringstream iss(line, std::istringstream::in);
        while( iss >> word ) {              // iterate over words in line

            Entry* entry = words.find(word); // find word in list of words
            if(entry){                             // if found
                entry->incrementCount();                // increment count
            } else {
                entry = words.insert(word);                    // if not found, add to list
            }

            // add page number to this word's page list if unique
            entry->foundOnPage((int) std::floor(lineNum / PAGE_LENGTH + 1));
        }
        // increment line tracker
        lineNum++;
    }
    fin.close();

    // print result to file
    words.printInOrder(fout);
    fout.close();
}
