#include <iostream>
#include <cstdlib> // for atoi

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

    // find 1 a bunch of times (will give away mtf and splay)
    for (int i = 1; i <= n / 4; i++) {
        std::cout << "F " << 1 << std::endl;
    }

    // find elements inserted
    for (int i = 1; i <= n / 4; i++) {
        std::cout << "F " << i << std::endl;
    }

    // find 2 a bunch of times
    for (int i = 1; i <= n / 4; i++) {
        std::cout << "F " << 2 << std::endl;
    }

    return 0;
}
