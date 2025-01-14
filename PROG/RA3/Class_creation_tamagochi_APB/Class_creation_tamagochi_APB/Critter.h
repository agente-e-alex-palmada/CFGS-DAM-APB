#pragma once
class Critter
{
public:
	Critter(int hunger, int boredom, string& name, time_t& timePassed);
	int getHunger() const;
	int getBoredom() const;
	int setHunger(int hunger);
	int setBoredom(int boredom);
	void talk(int hunger, int boredom, time_t& timePassed);
	int eat(int hunger, time_t& timePassed);
	int play(int boredom, time_t& timePassed);
private:
	void passTime(time_t& obtainedTime);
	int m_Hunger, m_Boredom;
	time_t m_Time;
};