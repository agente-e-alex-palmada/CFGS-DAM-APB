#include <iostream>
using namespace std;

/// <summary>
/// This function is used to calculate if a number is prime or not.
/// </summary>
void exercice2() {
    
    //Used to save the number that will be used to calculate if its prime or not
    int first, prime = 0;

    //Used to handle the menu
    bool m = true;
    cout << "Write a number: ";
    while (m)
    {
        cin >> first;
        
        //Handles if the user types wrong console input
        if (cin.fail())
        {
            system("cls");
            cout << "You have to write a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            m = true;
        }

        //The number can't be 0 or less because they can be divided
        else if (first <= 0)
        {
            cout << "The number can't be 0 or less because they can be divided\n";
            cout << "Write a number: ";
            m = true;
        }

        //If the input it's ok, breaks the loop and continues
        else {
            system("cls");
            m = false;
        }
    }

    /*Calculates if the residue is 0 or 1, if is it 0, means that the number prime, if is it
    1, it isn't*/
    for (int i = 2; i <= sqrt(first); i++) {
        if (first % i == 0)
        {
            prime = 1;
            break;
        }
    }
    if (prime == 0)
    {
        cout << "Your number is prime\n\n";
    }
    else
    {
        cout << "Your number is not prime\n\n";
    }
}
    