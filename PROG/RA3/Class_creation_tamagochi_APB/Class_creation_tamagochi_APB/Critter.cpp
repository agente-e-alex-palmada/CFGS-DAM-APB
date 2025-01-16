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

time_t Critter::getTime() const
{
    return m_Time;
}

int Critter::setHunger(int hunger)
{
    if (m_Hunger + hunger < 0)
    {
        return m_Hunger = 0;
    }
    else if (m_Hunger + hunger > 100)
    {
        return m_Hunger = 100;
    }
    else
    {
        return m_Hunger += hunger;
    }
}

int Critter::setBoredom(int boredom)
{
    if (m_Boredom + boredom < 0)
    {
        return m_Boredom = 0;
    }
    else if (m_Boredom + boredom  > 100)
    {
        return m_Boredom = 100;
    }
    else
    {
        return m_Boredom += boredom;
    }
}

time_t Critter::setTime(time_t timePassed)
{
    return m_Time = timePassed;
}

void Critter::talk()
{
    int boredom = getBoredom(), hunger = getHunger();
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
    auto now = std::chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    passTime(currentTime);
    cout << "I'm a Critter and I feel " << actualBoredom << ".\nAlso, I'm " << actualHunger << endl;
}

int Critter::eat()
{
    int hungerToSum = 5;
    setHunger(hungerToSum);
    int actualHunger = getHunger();
    auto now = std::chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    passTime(currentTime);
     return actualHunger;
}

int Critter::play()
{
    int boredomToSum = 5;
    setBoredom(boredomToSum);
    int actualBoredom = getBoredom();
    auto now = std::chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    passTime(currentTime);
    return actualBoredom;
}

void Critter::passTime(time_t lastUpdateTime)
{
    int rest = 0;
    time_t currentTime = getTime();
    time_t timeDifference = lastUpdateTime - currentTime;
    cout <<"Temps previ:" << timeDifference << endl;
    while (timeDifference >= 3)
    {
        rest--;
        timeDifference -= 3;
    }
    cout << "Temps post: " << timeDifference<<endl;
    if (rest < 0)
    {
        setBoredom(rest);
        setHunger(rest);
        setTime(lastUpdateTime);
    }
    cout << endl <<m_Boredom << endl << m_Hunger << endl << endl;
}
