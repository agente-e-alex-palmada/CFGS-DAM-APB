#include "myheader.h"
#include "Critter.h"

Critter::Critter(int hunger, int boredom, string& name)
{

}

const int Critter::getHunger()
{
    return m_Hunger;
}

const int Critter::getBoredom()
{
    return m_Boredom;
}

int Critter::setHunger(int hunger)
{
    if (hunger < 0)
    {
        cout << "You can't set a Critter's hunger to a negative number.\n\n";
    }
    else if (hunger > 100)
    {
        cout << "You can't set a Critter's hunger more than 100.\n\n";
    }
    else
    {
        return m_Hunger = hunger;
    }
}

int Critter::setBoredom(int boredom)
{
    if (boredom < 0)
    {
        cout << "You can't set a Critter's boredom to a negative number.\n\n";
    }
    else if (boredom > 100)
    {
        cout << "You can't set a Critter's boredom more than 100.\n\n";
    }
    else
    {
        return m_Boredom = boredom;
    }
}

void Critter::talk(int hunger, int boredom)
{
    string actualBoredom;
    string actualHunger;
    if (boredom >= 75)
    {
        actualBoredom = "frustrated";
    }
    else if (boredom >= 50)
    {
        actualBoredom = "mad";
    }
    else if (boredom >= 25)
    {
        actualBoredom = "bored";
    }
    else
    {
        actualBoredom = "content";
    }
    if (hunger >= 75)
    {
        actualHunger = "not hungry";
    }
    else if (hunger >= 50)
    {
        actualHunger = "kinda hungry";
    }
    else if (hunger >= 25)
    {
        actualHunger = "hungry";
    }
    else
    {
        actualHunger = "starving";
    }
    cout << "I'm a Critter and I feel " << actualBoredom << ".\nAlso, I'm ";
}

int Critter::eat(int hunger)
{
    return 0;
}

int Critter::play(int boredom)
{
    return 0;
}

void Critter::passTime()
{

}
