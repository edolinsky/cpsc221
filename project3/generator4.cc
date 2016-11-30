#include <iostream>
#include <cstdlib> // for atoi

/**
 * Inserts and removes integers repeatedly
 * This is the example provided in the assignment.
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

    for (int i = 1; i <= n / 2; i++) {
        std::cout << "I " << i << std::endl;
        std::cout << "R " << i << std::endl;
    }
    return 0;
}
