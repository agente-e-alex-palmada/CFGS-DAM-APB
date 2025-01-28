#include "Farm.h"
#include "Critter.h"
#include "myheader.h"

// Constructor for initializing the farm with a list of critters
Farm::Farm(std::vector<Critter> critters)
    : m_critters(critters) {}

// Add a critter to the farm
void Farm::addCritter(const Critter& critter) {
    // Buscar el primer critter muerto para reemplazarlo
    for (size_t i = 0; i < m_critters.size(); ++i) {
        if (m_critters[i].isDead()) {
            // Reemplazar el critter muerto por el nuevo critter
            m_critters[i] = critter;
            return;
        }
    }
    // Si no hay espacio, agregar al final
    m_critters.push_back(critter);
}


// Show all existing Critters
void Farm::listCritters() const
{
    for (size_t i = 0; i < getCritterCount(); ++i)
    {
        cout << i + 1 << ". " << m_critters[i].getName() << endl;
    }
}

// Get the total count of critters in the farm
size_t Farm::getCritterCount() const {
    return m_critters.size();
}

// Function to check if any critter is dead and remove it
void Farm::checkAndRemoveDeadCritters() {
    for (size_t i = 0; i < m_critters.size(); ++i) {
        if (m_critters[i].isDead()) {
            cout << "Critter " << m_critters[i].getName() << " has died.\n";
            // No eliminamos el critter, solo lo marcamos como muerto
            m_critters[i].markAsDead();
        }
    }
}


// Friend function that performs actions based on numeric input (1 for eat, 2 for play, etc.)
void performAction(Farm& farm, int index, int actionNumber) {
    if (index >= 0 && index < farm.m_critters.size()) {
        Critter& critter = farm.m_critters[index];

        switch (actionNumber) {
        case 1:
            critter.talk();  // Calls the eat method of Critter
            break;
        case 2:
            critter.eat();  // Calls the play method of Critter
            break;
        case 3:
            critter.play();  // Calls the talk method of Critter
            break;
        case 4:
            critter.secretTalk();  // Calls the secretTalk method of Critter
            break;
        default:
            break;
        }
    }
}
