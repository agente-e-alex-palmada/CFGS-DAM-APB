#pragma once
class Critter
{
public:
	Critter(int hunger, int boredom, string& name, time_t& timePassed);
	int getHunger() const;
	int getBoredom() const;
	time_t getTime() const;
	int setHunger(int hunger);
	int setBoredom(int boredom);
	time_t setTime(time_t timePassed);
	void talk();
	int eat();
	int play();
private:
	void passTime(time_t lastUpdateTime);
	int m_Hunger, m_Boredom;
	time_t m_Time;
};