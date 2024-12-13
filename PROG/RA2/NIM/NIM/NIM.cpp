//Imported libraries
#include <iostream>

//Standart declaration
using namespace std;

//Function declarations
int player1(int& player1Select, int& start);
int player2(int& player2Select, int& start);
void playAgain(bool& m2, char& selection, bool& inputP1, bool& inputP2, int& start, int& player1Select, int& player2Select, bool& m3);

//Function that manages the main logic of the game
void gameStart(char& selection, bool& m2, bool& inputP1, bool& inputP2, int& start, int& player1Select, int& player2Select, bool& m3) {
    cout << "Select which number you want to start: ";

    //While menu3 isn't true, it will continue to request the player a number
    while (m3) {
        cin >> start;

        //Conditional that allows the management to validate the input of the players 
        if (cin.fail()) {
            cout << "\nYou have to write a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        //To play the game, the number must be bigger than 2
        else if (start <= 2)
        {
            cout << "You have to put a bigger number: ";
            m3 = true;
        }
        
        //Exists the menu
        else {
            m3 = false;
        }
    }
    m3 = true;
    system("cls");
    cout << "First will start player 1\n\n";
    while (m3) {
        cout << "The number is now: " << start;
        
        //Checks if its the turn of player 1
        if (inputP1) {
            
            //Calling the function
            player1(player1Select, start);
            
            //Checks if start is lower or equal to 0
            if (start <= 0) {
                system("cls");
                cout << "Player 1 won the game!!!\n";
                m3 = false;
            }

            //Changes the turn of the player
            else {
                inputP1 = false;
                inputP2 = true;
            }
        }

        //Checks if its the turn of player 2
        else if (inputP2) {
            
            //Calling the function
            player2(player2Select, start);

            //Checks if the number is lower or equal to 0
            if (start <= 0) {
                system("cls");
                cout << "Player 2 won the game!!!\n";
                m3 = false;
            }

            //Changes the turn of the player
            else {
                inputP2 = false;
                inputP1 = true;
            }
        }
    }

    //Restarting the variables
    start = 0;
    player1Select = 0;
    player2Select = 0;
    selection = '0';
    m2 = true;
    m3 = true;
    inputP1 = true;
    inputP2 = false;
    playAgain(m2, selection, inputP1, inputP2, start, player1Select, player2Select, m3);
}

//The input for the first player
int player1(int& player1Select, int& start) {
    cout << "\n\n##Player 1##\n\nYou can substract 1 or 2\n\nYour number: ";
    
    //Restarts the variable
    player1Select = 0;

    //A loop that makes the player write 1 or 2
    while (player1Select != 1 && player1Select != 2)
    {
        cin >> player1Select;

        //Checks if the player has written the written the number correctly and if is it lower or higher between the allowed numbers
        if (cin.fail() || player1Select < 1 || player1Select > 2)
        {
            cout << "\nWrite between 1 and 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        //If the number is 1 and the player for some reason substracts 2, it will make the variable to 0
        else if (start - player1Select <= 0)
        {
            start = 0;
            return start;
        }

        //Returns the new value
        else
        {
            system("cls");
            start -= player1Select;
            return start;
        }
    }
}

//The input for the second player
int player2(int& player2Select, int& start) {
    cout << "\n\n##Player 2##\n\nYou can substract 1 or 2\n\nYour number: ";
    
    //Restarts the variable
    player2Select = 0;

    //A loop that makes the player write 1 or 2
    while (player2Select != 1 && player2Select != 2)
    {
        cin >> player2Select;

        //Checks if the player has written the written the number correctly and if is it lower or higher between the allowed numbers
        if (cin.fail() || player2Select < 1 || player2Select > 2)
        {
            cout << "\nWrite between 1 and 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        //If the number is 1 and the player for some reason substracts 2, it will make the variable to 0
        else if (start - player2Select <= 0)
        {
            start = 0;
            return start;
        }

        //Returns the new value
        else
        {
            system("cls");
            start -= player2Select;
            return start;
        }
    }
}

//A menu that allows the player to start the game
void menu(bool& m2, char& selection, bool& m1, bool& inputP1, bool& inputP2, int& start, int& player1Select, int& player2Select, bool& m3) {
    cout << "Welcome to NIM, do you want to start the game?\n(y/n): ";
    while (m1)
    {
        cin >> selection;

        //Checks if the introduced character is y
        if (selection == 'y' || selection == 'Y')
        {
            m1 = false;
            system("cls");
            gameStart(selection, m2, inputP1, inputP2, start, player1Select, player2Select, m3);
        }

        //Checks if the introduced character is n
        else if (selection == 'n' || selection == 'N')
        {
            system("cls");
            cout << "Then goodbye :3\n";
            m1 = false;
        }

        //If the character isn't correct or it is a number, it will prompt to write again
        else if (cin.fail())
        {
            cout << "\nYou have to write (y/n): ";
            m1 = true;
        }

        //If anything else happends
        else
        {
            cout << "\nYou have to write (y/n): ";
            m1 = true;
        }
    }
}

//The same menu as before but changing the first cout
void playAgain(bool& m2, char& selection, bool& inputP1, bool& inputP2, int& start, int& player1Select, int& player2Select, bool& m3) {
    cout << "Would you like to play again?: ";
    while (m2)
    {
        cin >> selection;
        
        //Checks if the introduced character is y
        if (selection == 'y' || selection == 'Y')
        {
            m2 = false;
            system("cls");
            start = 0;

            gameStart(selection, m2, inputP1, inputP2, start, player1Select, player2Select, m3);
        }
        
        //Checks if the introduced character is n
        else if (selection == 'n' || selection == 'N')
        {
            system("cls");
            cout << "Then goodbye :3\n";
            m2 = false;
        }
        
        //If the character isn't correct or it is a number, it will prompt to write again
        else if (cin.fail())
        {
            m2 = true;
            cout << "\nYou have to write (y/n):";
        }

        //If anything else happends
        else
        {
            m2 = true;
            cout << "\nYou have to write (y/n):";
        }
    }
}

//Init variables, main function
int main()
{
    int start = 0, player1Select, player2Select;
    char selection = 'a';
    bool m1 = true, m2 = true, m3 = true, inputP1 = true, inputP2 = false;
    
    //Calling the functions
    menu(m2, selection, m1, inputP1, inputP2, start, player1Select, player2Select, m3);
    return 0;
}