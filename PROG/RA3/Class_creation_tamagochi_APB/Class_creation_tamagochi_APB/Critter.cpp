#include "myheader.h"
#include "Critter.h"

Critter::Critter(int hunger, int boredom, string& name, time_t& timePassed)
{
    m_Hunger = hunger;
    m_Boredom = boredom;
    m_Time = timePassed;
    cout << "Hello, I'm " << name << ". I've just born.\nNice to meet you.\n\n";
}

int Critter::getHunger() const
{
    return m_Hunger;
}

int Critter::getBoredom() const
{
    return m_Boredom;
}

int Critter::setHunger(int hunger)
{
    if (m_Hunger + hunger < 0)
    {
        return 0;
    }
    else if (m_Hunger + hunger > 100)
    {
        return 100;
    }
    else
    {
        return m_Hunger += hunger;
    }
}

int Critter::setBoredom(int boredom)
{
    if (m_Boredom - boredom < 0)
    {
        return 0;
    }
    else if (m_Boredom - boredom  > 100)
    {
        return 100;
    }
    else
    {
        return m_Boredom += boredom;
    }
}

void Critter::talk(int hunger, int boredom, time_t& timePassed)
{
    string actualBoredom;
    string actualHunger;
    time_t currentTime = timePassed;
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
        actualBoredom = "entertained";
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

    passTime(currentTime);
    cout << "I'm a Critter and I feel " << actualBoredom << ".\nAlso, I'm " << actualHunger << endl;
}

int Critter::eat(int hunger, time_t& timePassed)
{
    int hungerToSum = 5;
    int actualHunger = setHunger(hungerToSum);
    time_t currentTime = timePassed;
    passTime(currentTime);
    return actualHunger;
}

int Critter::play(int boredom, time_t& timePassed)
{
    int boredomToSub = 5;
    int actualBoredom = setBoredom(boredomToSub);
    time_t currentTime = timePassed;
    passTime(currentTime);
    return actualBoredom;
}

void Critter::passTime(time_t& obtainedTime)
{
    int hungerToSub = 0, boredomToSum = 0;
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    while (timeDifference >= 3)
    {
        timeDifference -= 3;
        hungerToSub--;
        boredomToSum++;
    }
    setHunger(hungerToSub);
    setBoredom(boredomToSum);
    cout << getBoredom() << endl << endl << getHunger() << endl << endl;
}