//Header to include all declarations and libraries
#include "header.h"

vector<string> insertPlayers(vector<string> names) {
    
    //Variable declaration, vector to save an array
    vector<string> playerNames;
    string playerName;

    while (true) {
        cout << "Enter player name (leave empty to continue): ";
        
        //Gets the next line writed by the user
        getline(cin, playerName);

        //If the line entered by the player is empty, it will break the loop
        if (playerName.empty()) {
            break;
        }

        //Saves the value for every player in the array
        playerNames.push_back(playerName);
    }

    //Clears the screen
    system("cls");

    //Shows how many players have been entered
    cout << "Players entered:" << endl;
    for (const string& name : playerNames) {
        cout << name << endl;
    }
    cout << endl;

    //Returns the value that stores the names as an array
    return playerNames;
}