#pragma once
#include "Critter.h"
#include "myheader.h"

class Farm
{
public:
    // Constructor to initialize the farm with a list of critters
    Farm(vector<Critter> critters = {});

    // Add a new critter to the farm
    void addCritter(const Critter& critter);

    // List all the critters in the farm
    void listCritters() const;

    // Get the total number of critters in the farm
    size_t getCritterCount() const;

    // Friend function that performs actions (e.g., eat, play) based on numeric input
    friend void performAction(Farm& farm, int index, int actionNumber);

    void checkAndRemoveDeadCritters();

private:
    // Vector that stores all critters in the farm
    vector<Critter> m_critters;
};
