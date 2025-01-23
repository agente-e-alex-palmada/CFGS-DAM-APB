#pragma once
#include "myheader.h"
// The class Critter
class Critter
{
public:

	// The object Critter with their stats
	Critter(int hunger, int boredom, string name, time_t timePassed);
	
	// Getters and setters
	int getHunger() const;
	int getBoredom() const;
	string getName() const;
	time_t getTime() const;
	void setHunger(int hunger);
	void setBoredom(int boredom);
	void setName(string name);
	void setTime(time_t timePassed);

	// Functions to interact with the Critter
	void talk();
	void eat();
	void play();
	void secretTalk();


private:

	// Handling of time in real time
	void passTime(time_t lastUpdateTime);
	
	// Variables that saves the data from the Critter
	int m_Hunger, m_Boredom;
	string m_Name;
	time_t m_Time;
};