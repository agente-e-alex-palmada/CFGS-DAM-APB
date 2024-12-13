//Header to include all declarations and libraries
#include "header.h"

string checkWinner(vector<string>& names, vector<int>& scores) {
	
	//Variable declaration
	int maxScore = 0;
	int index = 0;

	//Checks in the score the highest number, when it finds one greater, it will save the position and the max score
	for (int i = 0; i < scores.size(); i++)
	{
		if (maxScore < scores[i])
		{
			maxScore = scores[i];
			index = i;
		}
	}
	system("cls");

	//It will return who's the winner as a string
	string winner = "The winner is " + names[index]+" with a score of "+to_string(scores[index])+".";
	return winner;
}