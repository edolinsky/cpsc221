//
// Created by erik on 07/10/16.
//

#include "Entry.h"

Entry::Entry(std::string newWord) {
    word = newWord;
    count = 1;
}

Entry::~Entry() {
}

std::string Entry::getWord() {
    return word;
}

int Entry::getCount() {
    return count;
}

int Entry::incrementCount() {
    return count++;
}

void Entry::printTo(std::stringstream * info) {
    std::string page_separator = "";                // initialize separator for page numbers
    *info << word << " (" << count << ") ";  // concat word and number of times it was found

    // iterate over page list
    for (std::vector<int>::iterator page = pages.begin(); page != pages.end(); page++) {

        *info << page_separator << *page;    // add page number
        page_separator = ",";               // change separator after first iteration

    }
    *info << std::endl;                      // end line after page numbers
}

std::vector<int> Entry::getPages() {
    return pages;
}
/**
 * Inserts a page number into vector of pages only if the page does not already exist in that vector
 * @param page integer denoting page number
 * @param pages vector of page numbers
 */
void Entry::foundOnPage(int page) {
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