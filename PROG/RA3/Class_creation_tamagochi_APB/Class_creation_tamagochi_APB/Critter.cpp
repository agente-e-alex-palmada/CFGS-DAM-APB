#include "myheader.h"
#include "Critter.h"

Critter::Critter(int hunger, int boredom, string name, time_t timePassed)
{
    m_Hunger = hunger;
    m_Boredom = boredom;
    m_Time = timePassed;
    m_Name = name;
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

void Critter::setHunger(int hunger)
{
    if (m_Hunger + hunger < 0)
    {
        m_Hunger = 0;
    }
    else if (m_Hunger + hunger > 100)
    {
        m_Hunger = 100;
    }
    else
    {
        m_Hunger += hunger;
    }
}

void Critter::setBoredom(int boredom)
{
    if (m_Boredom + boredom < 0)
    {
        m_Boredom = 0;
    }
    else if (m_Boredom + boredom  > 100)
    {
        m_Boredom = 100;
    }
    else
    {
        m_Boredom += boredom;
    }
}

void Critter::setTime(time_t timePassed)
{
    m_Time = timePassed;
}

void Critter::talk()
{
    int boredom = getBoredom(), hunger = getHunger();
    string actualBoredom;
    string actualHunger;
    if (boredom >= 75)
    {
        actualBoredom = "entertained";
    }
    else if (boredom >= 50)
    {
        actualBoredom = "bored";
    }
    else if (boredom >= 25)
    {
        actualBoredom = "mad";
    }
    else
    {
        actualBoredom = "frustrated";
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
    auto now = chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    passTime(currentTime);
    cout << "I'm a Critter and I feel " << actualBoredom << ".\nAlso, I'm " << actualHunger << endl;
}

void Critter::secretTalk() {
    cout << "Stats:\nHunger: " << m_Hunger << "\nBoredom: " << m_Boredom << endl << endl;
}

void Critter::eat()
{
    int hungerToSum = 5;
    setHunger(hungerToSum);
    cout << m_Name << ": Om nom nom nom nom nom\n*Your critter gets " << hungerToSum << " points of hunger*\n\n";
    auto now = chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    passTime(currentTime);
}

void Critter::play()
{
    int boredomToSum = 5;
    setBoredom(boredomToSum);
    cout << m_Name << ": Yippieee, yay yay yippie :3 :3\n*Your critter gets " << boredomToSum << " points of boredom*\n\n";
    auto now = chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    passTime(currentTime);
}

void Critter::passTime(time_t lastUpdateTime)
{
    int rest = 0;
    time_t currentTime = getTime();
    time_t timeDifference = lastUpdateTime - currentTime;
    while (timeDifference >= 1)
    {
        rest -= 3;
        timeDifference -= 3;
    }
    if (rest < 0)
    {
        setBoredom(rest);
        setHunger(rest);
        setTime(lastUpdateTime);
    }
}
