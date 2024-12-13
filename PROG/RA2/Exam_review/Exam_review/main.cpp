//Header to include all declarations and libraries
#include "header.h"

//Main function, starts the program
void main() {
	//Assigns the function value to the variable string names, it is a vector to save an array
	vector<string> names = insertPlayers(names);
	
	//Assigns the function value to the variable integer names, it is an integer to get how many players there are, so it will ask only for the the number of players.
	int numPlayers = names.size();

	//Assigns the function value to the variable integer scores, it is a vector to save anr array, and every puntuation is saved with the same position as the names
	vector<int> scores = insertPuntuation(numPlayers);

	//It will show the winner name and score
	cout << checkWinner(names, scores);
}