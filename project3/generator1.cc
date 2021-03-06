#include <iostream>
#include <cstdlib> // for atoi

/**
 * Inserts a set of incrementing integers, then removes them, decrementing
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
    for (int i = 1; i <= n / 2; i++) {
        std::cout << "I " << i << std::endl;
    }

    // remove, decrementing
    for (int i = n / 2; i >= 1; i--) {
        std::cout << "R " << i << std::endl;
    }

    return 0;
}
