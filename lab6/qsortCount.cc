#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

int *x;
long comps = 0;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int randint(int a, int b) {
    return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {
    if (a >= b) return;
    int p = randint(a, b); // pivot
    swap(x[a], x[p]);
    int m = a;
    int i;
    // in-place partition:
    for (i = a + 1; i <= b; i++) {
        if (x[i] < x[a])
            swap(x[++m], x[i]);
        comps++;
    }
    swap(x[a], x[m]);
    quicksort(a, m - 1);
    quicksort(m + 1, b);
}

int qc(int n) {
    if (n <= 1) return 0;       // no comparisons required for 0 or 1 elements
    else if (n == 2) return 1;  // one comparison for 2 elements

    int count = n - 1;          // n - 1 comparisons otherwise

    int pivot = randint(0, n - 1);  // pick a random number for pivot
    count += qc(pivot);             // add comparisons on left partition
    count += qc(n - pivot - 1);     // add comparisons on right partition

    return count;
}

// Q4.
//
//           n
//          ___
//       1  \    (n-1) + C(m-1) + C(n-m)
// C(n)= -  /
//       n  ---
//          m=1
//
// Q5.
// Average-case runtime for quicksort is theta(nlogn), while worst-case runtime is theta(n^2).
// We are unlikely to see worst-case, as it would require us to pick the smallest or largest value pivot
// with every single call to quicksort, which is statistically unlikely.
// This implementation is not stable, but is in-place. We do not keep track of the order of
// equal elements, and they can easily be swapped around. Since we do not use any more space than
// what is required for the array and call stack, it is in-place.

#define NN 1000
#define NUM_TIMES 100

int main(int argc, char *argv[]) {

    for (int test = 0; test < NUM_TIMES; test++) {
        unsigned seed = std::chrono::duration_cast<std::chrono::nanoseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count();
        srand(seed);

        // actual quicksort
        /*
        x = new int[NN];
        for (int i = 0; i < NN; ++i) {
            x[i] = rand() % NN;
        }

        quicksort(0, NN - 1);
        for (int i = 0; i < NN; ++i) {
            std::cout << x[i] << " ";
        }
        std::cout << std::endl;
        delete[] x;
         */

        // counting number of comparisons in quicksort (not actually sorting)
        comps += qc(NN);

    }
    std::cout << "NN = " << NN << ". Mean number of comparisons: " << comps / NUM_TIMES << std::endl;
    //std::cout << NN << "," << comps / NUM_TIMES << std::endl; // CSV format (comment out above cout lines)
}


