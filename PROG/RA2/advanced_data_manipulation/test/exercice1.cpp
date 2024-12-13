#include <iostream>

using namespace std;

/// <summary>
/// Asks for the player to write a number and shows the factorial number of it and the square root
/// </summary>
void exercice1() {

    //n is the number we want to know the factorial
    //facotrial is to calculate the factorial number of n
    int  n, factorial = 1;

    //Handles the menu
    bool m = true;

    //It's usetd to make the square root of the number
    double sqrt_of_n;
    cout << "Write a number: ";
    while (m)
    {
        cin >> n;

        //Handles if the user types wrong console input
        if (cin.fail())
        {
            system("cls");
            cout << "You have to write a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            m = true;
        }

        //The factorial number of 0 is 1 and can't be 0
        else if (n <= 0)
        {
            cout << "The factorial number of 0 is 1, but I can't caluclate the square root of 0 or negative number\n";
            cout << "Write a number: ";
            m = true;
        }

        //If the input it's ok, breaks the loop and continues
        else {
            system("cls");
            m = false;
        }
    }
    //Calculates the factorial number multiplying the number by many times until it stops
    for (int i = n; i >= 1; i--)
    {
        factorial = factorial *= i;
    }

    //Shows the factorial number and the square root
    cout << "The factorial number of " << n << " is " << factorial;
    sqrt_of_n = n;
    cout << "\n\nAnd the square root of " << n << " is " << sqrt(sqrt_of_n) << endl << endl;  
}