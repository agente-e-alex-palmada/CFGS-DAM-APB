//Header to include all declarations and libraries
#include "header.h"

//Function to insert puntiation
vector<int> insertPuntuation(int& numPlayers)
{
    //Declare local variables, vector type to save an array
	vector<int> scores;
	int score;

    //A loop for every player
    for (int i = 0; i < numPlayers; i++) {
        while (true) {
            cout << "Insert the score for player " << i + 1 << ": ";
            cin >> score;

            //It checks if the value introduced is valid
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid number." << endl;
            }
            else {

                //Saves the value and stores it on scores
                scores.push_back(score);
                break;
            }
        }
    }
	return scores;
}