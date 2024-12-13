#include "myheader.h"
int mmrSub(int& mmr, int& mmrChange, float& multiplier) {
    system("cls");

    // Calls the library to substract the multiplier
    multiplier = MMR_class::SubtractMultiplyer(multiplier);

    // Limits the multiplier to be one
    if (multiplier <= 1)
    {
        multiplier = 1;
    }

    // Limiits the mmr added to the final mmr between ten and three
    mmrChange -= rand() % 5 + 1;
    if (mmrChange > 10) {
        mmrChange = 10;
    }
    else if (mmrChange < 3) {
        mmrChange = 3;
    }

    // Calls the library to substract the mmr
    mmr = MMR_class::Subtract(mmr, mmrChange, multiplier);
    mmr = int(mmr);

    // Limits the mmr to 1
    if (mmr <= 0)
    {
        mmr = 1;
    }
    return mmr;
}
