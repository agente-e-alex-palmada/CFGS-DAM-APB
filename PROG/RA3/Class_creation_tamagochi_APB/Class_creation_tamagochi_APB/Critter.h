#pragma once
class Critter
{
public:
	Critter(int hunger, int boredom, string& name);
	const int getHunger();
	const int getBoredom();
	int setHunger(int hunger);
	int setBoredom(int boredom);
	void talk(int hunger, int boredom );
	int eat(int hunger);
	int play(int boredom);
	void passTime();
private:
	int m_Hunger, m_Boredom;
};

