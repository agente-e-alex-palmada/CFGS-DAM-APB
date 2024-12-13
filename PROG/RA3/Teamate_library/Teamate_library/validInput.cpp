#include "myheader.h"
bool validInput(char& yn) {
    string input;
    getline(cin, input);  // Get the whole line of input

    // Check if the input is exactly 1 character and if it is 'y' or 'n'
    if (input.length() != 1 || (input[0] != 'y' && input[0] != 'n')) {
        cout << "Invalid input. Please enter 'y' or 'n'.\n";
        return false;
    }

    yn = input[0];  // Assign the valid input to yn
    return true;
}