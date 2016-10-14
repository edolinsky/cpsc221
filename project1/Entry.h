//
// Created by erik on 07/10/16.
//

#ifndef PROJECT_ENTRY_H
#define PROJECT_ENTRY_H
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

class Entry {
    std::string word;
    int count;
    std::vector<int> pages;

public:
    Entry(std::string word);
    void foundOnPage(int page);
    int getCount();
    std::string getWord();
    int incrementCount();
    std::vector<int> getPages();
    void printTo(std::stringstream * info);
    ~Entry();

private:
    std::string getPageList();
};


#endif //PROJECT_ENTRY_H
