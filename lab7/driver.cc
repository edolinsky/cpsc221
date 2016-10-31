#include "Hashtable.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


void usage(char *argv[]) {
    cerr << "Usage: " << argv[0] << " scheme numberOfKeys sizeOfTable" << endl;
    exit(-1);
}

/*
 * 1. Linear probing is just as good as quadratic when the table is sufficiently empty. Once the table starts to fill
 * up, linear probing starts to cluster, and quadratic probing begins to win out.
 *
 * 2. The choice of second hash function can affect the amount of clustering that occurs, and therefore the performance
 * of probing. Further, if a poor hash function is chosen (i.e. one that allows hashing to '0'), superfluous failures
 * may occur. Yes, and yes, depending on the hash functions chosen; probing rates would generally be lower, but the
 * number of failures may be higher, depending on the failure threshold chosen.
 *
 * 3. Double hashing begins to win against linear when linear begins to cluster, and begins to win against quadratic
 * when the number of keys reaches half of the table size, and always for tables of non-prime size.
 *
 * 4. I'd usually pick double hashing, as it offers the best performance with the fewest preconditions. However, if
 * the hash functions take a sufficiently long time, I'd probably stick to quadratic probing, as hashing would only
 * have to occur once in this case.
 */

int main(int argc, char *argv[]) {
    int n, m;
    srand(time(0));

    if (argc == 1) {
        cout << "Running your test code..." << endl;

        for (int size = 1; size <= 100; size++) {
            cout << endl << "=========================================================================================" << endl;
            cout << "Table Size: " << size << endl;
            cout << "=========================================================================================" << endl;

            for (int numKeys = 0; numKeys <= 2 * size; numKeys++) {
                Hashtable L(size);
                Hashtable Q(size);
                Hashtable D(size);

                for (int i = 0; i < numKeys; i++) {
                    L.linsert(rand() + 1);
                    Q.qinsert(rand() + 1);
                    D.dinsert(rand() + 1);
                }
                cout << endl << numKeys << endl;
                cout <<                 "Linear:    ";
                L.printStats();

                cout <<                 "Quadratic: ";
                Q.printStats();

                cout <<                 "Double:    ";
                D.printStats();
            }
        }

        return 0;
    }

    if (argc != 4) {
        usage(argv);
    }
    n = atoi(argv[2]);
    m = atoi(argv[3]);
    Hashtable H(m);

    switch (argv[1][0]) {
        case 'l':
            for (int i = 0; i < n; ++i) {
                H.linsert(rand() + 1);
            }
            //    H.print();
            cout << "Linear: ";
            H.printStats();
            break;
        case 'q':
            for (int i = 0; i < n; ++i) {
                H.qinsert(rand() + 1);
            }
            //    H.print();
            cout << "Quadratic: ";
            H.printStats();
            break;
        case 'd':
            for (int i = 0; i < n; ++i) {
                H.dinsert(rand() + 1);
            }
            //    H.print();
            cout << "Double Hashing: ";
            H.printStats();
            break;
        default:
            usage(argv);
    }
}

