#include "Farm.h"
#include "myheader.h"

// 
Farm::Farm(vector<Critter> critters) : m_critters(critters)
{

}

// Add a new Critter to the Vector
void Farm::addCritter(const Critter& critter)
{
    m_critters.push_back(critter);
}

// Erase a Critter from existence
void Farm::removeCritter(int index)
{
    if (index >= 0 && index < m_critters.size())
    {
        m_critters.erase(m_critters.begin() + index);
    }
}

// Show all existing Critters
void Farm::listCritters() const
{
    for (size_t i = 0; i < getCritterCount(); ++i)
    {
        cout << i + 1 << ". " << m_critters[i].getName() << endl;
    }
}

// Get all existing critters
size_t Farm::getCritterCount() const
{
    return m_critters.size();
}
