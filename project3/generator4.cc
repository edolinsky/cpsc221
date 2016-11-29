#include <iostream>
#include <cstdlib> // for atoi

int main(int argc, char *argv[]) {
    if (argc != 2)
    {
        std::cerr << "Wrong number of arguments!" << std::endl;
        return 1;
    }
    int n = atoi(argv[1]);

    for (int i = 2; i <= n - 1; i++) {
        std::cout << "I " << i << std::endl;
        std::cout << "R " << i << std::endl;
    }
    return 0;
}
