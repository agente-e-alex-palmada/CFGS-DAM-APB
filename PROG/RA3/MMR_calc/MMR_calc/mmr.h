#pragma once

namespace mmr
{
    class MMR_class
    {
    public:
        // Sumara el mmr mes el de la victoria, per defecte 20 i Multiplicara la suma si hi ha +1 victories seguides, si guanya 2 seguides un 2x, 3 guaynades 3x ....
        static int Add(int totalMmr, int addMmr, float multiplicadorWin);

        // Restara el mmr menys el de la victoria, per defecte 20 i Multimplicara la resta si hi ha +1 perduda seguguida, si perd 2 2x, 3 perdudes 3x ....
        static int Subtract(int totalMmr, int subtractMmr, float multiplicadorLose);

        // Suma el multiplicador per cada victoria
        static float AddMultiplyer(float multiply);

        // Resta el multiplicador per cada derrota
        static float SubtractMultiplyer(float multiply);
    };
}