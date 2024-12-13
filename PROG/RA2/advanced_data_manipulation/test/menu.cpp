//This library is standard by the program
#include <iostream>

//This includes are local libraries created by me :P
#include "selection.h"
#include "exercice1.h"
#include "exercice2.h"

using namespace std;

/// <summary>
/// This is the menu function
/// </summary>
void menu() {
    
    //Use this variable to select an option
    int value = 0;
    
    //Loop that handles wrong console inputs, and when the user types 3, the program will end
    while (value != 3) {
        cout << "Select which exercice you want to go:\n";

        //Calls the function to display on screen the options that the user has
        selection();
        cin >> value;
    
        /*If the user types, for example "A",the program will response with a 
        message telling the user that needs to write a number*/
        if (cin.fail())
        {
            cout << "\nYou have to write a number: ";
        
            //Clears the last console input
            cin.clear();
            
            //Ignores the rest of the current line
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            //Restarts the value and the loop
            value = 0;
        }

        /*Swith that depending of the selection of the user will go to an exercice.
        If types any other character or number, it will displayh again the screen*/
        switch (value) {
        case 1:

            //Clears the console screen
            system("cls");

            //Calls the function
            exercice1();

            //Evade to execute next cases
            break;
        case 2:
            system("cls");
            exercice2();
            break;
        default:
            system("cls");
            break;
        }
    }
}