//Including headers for the code
#include "pch.h"
#include "RPGLogic.h"

using namespace std;

//Logic for attack function
float attack(float userDmg)
{
    //Generate a random value between 1 and 10
    float randomModifier = static_cast<float>(rand() % 10 + 1);
    float dmgDealt = userDmg + randomModifier;
    //Return base damage plus random modifier
    return dmgDealt;
}

//Logic for defend function
float defend(float userDef, float dmgRecived)
{
    // Define a probability for perfect defense
    const int perfectDefenseChance = 30;//30% chance for perfect defense

    //Generate a random number between 0 and 100
    int defenseRoll = rand() % 100;

    //If the random number is less than the chance, the defense is perfect (no damage taken)
    if (defenseRoll < perfectDefenseChance)
    {
        return 0.0f;//Perfect defense: no damage
    }
    else
    {
        //Random value for base user defense
        float randomAddition = 1 + rand() % 5;//This will generate values from 1 to 5

        //Generate a random reduction amount between 1 and the base defense value (userDef)
        float newDef = userDef + randomAddition;

        //Calculate the final damage recived
        float finalDamage = newDef - dmgRecived;

        //Ensure the final damage is not negative (if defense is high enough)
        if (finalDamage < 0.0f)
        {
            finalDamage = 1.0f;
        }

        //Return the final damage after applying the reduction
        return finalDamage;
    }
}

