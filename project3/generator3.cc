#include <iostream>
#include <cstdlib> // for atoi

/**
 * Inserts a set of incrementing integers, finds 'n/8' repeatedly, finds all in the set, then finds 'n/8+1' repeatedly
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    if (argc != 2)
    {
        std::cerr << "Wrong number of arguments!" << std::endl;
        return 1;
    }
    int n = atoi(argv[1]);

    // insert, incrementing
    for (int i = 1; i <= n / 4; i++) {
        std::cout << "I " << i << std::endl;
    }

    // find n/8 a bunch of times (will give away mtf and splay)
    for (int i = 1; i <= n / 4; i++) {
        std::cout << "F " << n/8 << std::endl;
    }

    // find elements inserted
    for (int i = 1; i <= n / 4; i++) {
        std::cout << "F " << i << std::endl;
    }

    // find 2 a bunch of times
    for (int i = 1; i <= n / 4; i++) {
        std::cout << "F " << n/8+1 << std::endl;
    }

    return 0;
}
