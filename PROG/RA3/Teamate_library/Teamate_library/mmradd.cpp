#include "myheader.h"

// Function to add mmr to the user
int mmrAdd(int& mmr, int& mmrChange, float& multiplier) {
    system("cls");

    // Executes only if the multiplier it's still below 2
    if (multiplier < 2)
    {
        multiplier = MMR_class::AddMultiplyer(multiplier);
    }

    // Limits the multiplier to two
    if (multiplier >= 2)
    {
        multiplier = 2;
    }
    mmrChange += rand() % 5 + 1;

    // Limiits the mmr added to the final mmr between ten and three
    if (mmrChange > 10) {
        mmrChange = 10;
    }
    else if (mmrChange < 3) {
        mmrChange = 3;
    }

    // Calls the library to add mmr
    mmr = MMR_class::Add(mmr, mmrChange, multiplier);
    mmr = int(mmr);
    return mmr;
}
