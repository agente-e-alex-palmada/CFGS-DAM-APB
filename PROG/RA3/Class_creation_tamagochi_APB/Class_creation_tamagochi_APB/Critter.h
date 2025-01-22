#pragma once
class farm 
{
public:

private:

};

class Critter
{
public:
	Critter(int hunger, int boredom, string name, time_t timePassed);
	int getHunger() const;
	int getBoredom() const;
	time_t getTime() const;
	void setHunger(int hunger);
	void setBoredom(int boredom);
	void setTime(time_t timePassed);
	void talk();
	void eat();
	void play();
	void secretTalk();
private:
	void passTime(time_t lastUpdateTime);
	int m_Hunger, m_Boredom;
	string m_Name;
	time_t m_Time;
};