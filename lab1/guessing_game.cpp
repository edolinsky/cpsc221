//
// Created by erik on 12/09/16.
//

#include <cstdlib>
#include <iostream>
#include <cstring>

#define MAX 100
#define BASE_TEN 10
#define INPUT_LENGTH 1024
#define QUIT "quit"

int main () {

    srand(time(NULL));                      // seed random number
    long int answer = rand() % MAX + 1;     // get random number between 1 and 100
    // std::cout << std::endl << std::to_string(answer) << std::endl;    // DEBUG: print answer

    // Print welcome message
    std::cout << "Welcome! Pick a number between 1 and " << MAX << "\nType '" << QUIT << "' to exit\n";

    // main control loop
    while (true) {

        // Initialize input array and take input from user
        char input[INPUT_LENGTH];
        std::cin >> input;

        // quit game if user types 'quit'
        if (std::strcmp(input, QUIT) == 0) {
            // Quit game
            std::cout << "Ok, Bye!" << std::endl;
            break; // Exit control (game) loop

            // Compare input to answer
            // strtol returns 0 if input is not a number
            // as 0 is not in the set of possible answers, this also checks for input validity
        } else if (strtol(input, NULL, BASE_TEN) == answer) {
            // Correct Answer!
            std::cout << "Correct!" << std::endl;
            break;   // Exit control (game) loop

            // If valid and incorrect, print message
        } else {
            // Incorrect or meaningless answer
            std::cout << std::endl << "Hmmm... That isn't right. Try again, or type 'quit' to end game!" << std::endl;
        }
    }

    return 0;
}