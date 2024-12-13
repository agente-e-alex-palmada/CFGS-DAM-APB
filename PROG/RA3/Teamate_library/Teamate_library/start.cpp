#include "myheader.h"
void start() {
    
    // Variable declaration
    int mmr = 600;
    int mmrChange = 1;
    char yn;
    float multiplier = 1;
    bool menu = true;

    cout << "You start with an mmr of " << mmr << ".\n";

    // Repeats until menu the menu ends
    do {
        cout << "Did you win the last match? (y/n): ";

        // Input validation for the first question
        if (!validInput(yn)) continue;

        // Switch that hanldes the menu
        switch (yn) {
        case 'y':
            mmr = mmrAdd(mmr, mmrChange, multiplier);
            system("cls");
            cout << "Your MMR is now " << mmr << ".\n\n";
            break;
        case 'n':
            mmr = mmrSub(mmr, mmrChange, multiplier);
            system("cls");
            cout << "Your MMR is now " << mmr << ".\n\n";
            break;
        }

        // Ask if they played another match
        cout << "Did you play another match? (y/n): ";
        if (!validInput(yn)) continue;
        system("cls");
        if (yn == 'n') {
            menu = false;
        }
    } while (menu);
    cout << "You finished with an mmr of " << mmr << "!\n";
}
