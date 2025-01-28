#include "myheader.h"
#include "Critter.h"

Critter::Critter()
{
    // It's just a constructor
}

// What does the Critter when it's created
Critter::Critter(int hunger, int boredom, string name, time_t timePassed)
{
    // Saves all stats passed
    m_Hunger = hunger;
    m_Boredom = boredom;
    m_Time = timePassed;
    m_Name = name;
}

// Getters and setters
int Critter::getHunger() const
{
    return m_Hunger;
}

int Critter::getBoredom() const
{
    return m_Boredom;
}

string Critter::getName() const
{
    return m_Name;
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

void Critter::setName(string name)
{
    m_Name = name;
}

void Critter::setTime(time_t timePassed)
{
    m_Time = timePassed;
}

void Critter::deathHandler()
{
    if (m_Hunger <= 0 || m_Boredom <= 0) {
        system("cls");
        cout << m_Name << " has died. RIP :c.\n\n";
        // Additional actions for the critter's death can be added here
        m_Hunger = 0;
        m_Boredom = 0;  // Set both stats to 0 to ensure the critter is fully dead
    }
}

// Agregar un flag que indique si el critter está muerto
bool isDead() const {
    return m_Hunger == 0 && m_Boredom == 0;
}

void markAsDead() {
    m_Hunger = 0;  // Marca que está muerto
    m_Boredom = 0;
}

// Interact with Critter to know their stats
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
// Secret talk to know the values of the variables
void Critter::secretTalk() {
    cout << "Stats:\nHunger: " << m_Hunger << "\nBoredom: " << m_Boredom << endl << endl;
    auto now = chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    passTime(currentTime);
}

// Interact with Critter to sum hunger stat
void Critter::eat()
{
    int hungerToSum = 5;
    setHunger(hungerToSum);
    cout << m_Name << ": Om nom nom nom nom nom\n*Your critter gets " << hungerToSum << " points of hunger*\n\n";
    auto now = chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    passTime(currentTime);
}

// Interact with Critter to sum boredom stat
void Critter::play()
{
    int boredomToSum = 5;
    setBoredom(boredomToSum);
    cout << m_Name << ": Yippieee, yay yay yippie :3 :3\n*Your critter gets " << boredomToSum << " points of boredom*\n\n";
    auto now = chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    passTime(currentTime);
}

// Function called everytime when interacting that saves the last interaction and checks how much time has pased since new interaction, every 3 seconds will substract points to the stats
void Critter::passTime(time_t lastUpdateTime)
{
    int rest = 0;
    time_t currentTime = getTime();
    time_t timeDifference = lastUpdateTime - currentTime;
    while (timeDifference >= 1)
    {
        rest -= 1;
        timeDifference -= 1;
    }
    if (rest < 0)
    {
        setBoredom(rest);
        setHunger(rest);
        setTime(lastUpdateTime);
    }
}
