// MMR_calc.cpp : Define las funciones de la biblioteca estática.
//

#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "mmr.h"


namespace mmr
{
    int MMR_class::Add(int totalMmr, int addMmr, float multiplicadorWin)
    {
        return totalMmr += (addMmr * multiplicadorWin);
    }

    int MMR_class::Subtract(int totalMmr, int subtractMmr, float multiplicadorLose)
    {
        return totalMmr -= (subtractMmr * multiplicadorLose);
    }
    float MMR_class::AddMultiplyer(float multiply) {
        return multiply + 0.2;
    }
    float MMR_class::SubtractMultiplyer(float multiply) {
        return multiply - 0.2;
    }
}