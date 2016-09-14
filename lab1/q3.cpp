//
// Created by erik on 12/09/16.
//
#include <iostream>

#define ARRAY_SIZE 10

void fill_array(); // for part (a)
void fill_array(int first_value, int increment);// for part (b)
void print_array();

int arr[ARRAY_SIZE];

void fill_array() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i + 1;
    }
}

void fill_array(int first_value, int increment) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = first_value + (i * increment);
    }
}

void print_array() {
    /*
     * Prints the elements of an array of size ARRAY_SIZE, with some pretty formatting
     */

    // Open string representation with bracket
    std::cout << "[ ";

    // Iterate through
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << arr[i];

        // print comma if i is not the last element
        if (i < ARRAY_SIZE - 1) {
            std::cout << ", ";
        }

    }

    // Closing bracket and newline
    std::cout << " ]" << std::endl;


}

int main() {
    // part (a)
    fill_array();
    print_array();

    // part (b)
    fill_array(4,2);
    print_array();

    return 0;
}