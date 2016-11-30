#include <iostream>
#include <cstdlib> // for atoi

/**
 * Inserts n elements, incrementing
 * -- mostly for differentiation score
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

    // insert incrementing
    for (int i = 1; i <= n; i++) {
        std::cout << "I " << i << std::endl;
    }

    return 0;
}
