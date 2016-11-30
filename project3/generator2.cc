#include <iostream>
#include <cstdlib> // for atoi

/**
 * Inserts a set of decrementing integers, then attempts to find integers that do not exist
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

    // insert, decrementing
    for (int i = n / 2; i >= 1; i--) {
        std::cout << "I " << i << std::endl;
    }

    // find elements not inserted
    for (int i = n / 2 + 1; i <= n; i++) {
        std::cout << "F " << i << std::endl;
    }

    return 0;
}
