#include <iostream>
#include <fstream>
#include <algorithm>
#include "CodeTree.h"

// Print the Huffman code tree and list of codes for a given text file.

void usage() {
  std::cerr << "Usage: huftree text.txt" << std::endl;
  throw std::exception();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    usage();
  }

  int freq[256] = {0};  // array initialized to 0

  std::ifstream fin(argv[1]);
  if (fin.is_open()) {
    char ch;
    while (fin >> std::noskipws >> ch) {  // don't skip whitespace
      if (ch != '\n') {
        freq[(int) ch]++;
      }
    }

    fin.close();
  }

  PriorityQueue *queue = new PriorityQueue();
  for (int i = 0; i < 256; i++) {
    if (freq[i] != 0) {
      queue->insert(new Node(freq[i], i));
    }
  }
  CodeTree ct = CodeTree(queue);

  ct.printTree();
  ct.printCode();

  return 0;
}
