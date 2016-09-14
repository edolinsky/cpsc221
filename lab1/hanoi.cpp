//
// Created by erik on 12/09/16.
//

// Towers of Hanoi -------------------------

#include <cstdlib> // for atoi
#include <iostream>

// prototype
void moveDisks(int n, const char* FROM, const char* VIA, const char* TO);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " number_of_disks" << std::endl;
        return -1;
    }
    int n = atoi(argv[1]);
    moveDisks(n, "peg A", "peg B", "peg C");
    return 0;
}

// put your moveDisks() function here
void moveDisks(int n, const char* FROM, const char* VIA, const char* TO) {

    // Base case: stop before we run out of disks
    if (n > 0) {
        moveDisks(n - 1, FROM, TO, VIA);  // Recursively move n-1 disks from A to B
        std::cout << "Move disk from " << FROM << " to " << TO << std::endl; // Move disk n from A to C
        moveDisks(n - 1, VIA, FROM, TO); // Recursively move n-1 disks from B to C
    }
}