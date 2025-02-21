#pragma once
#include <string>
#include <vector>
#include <iostream>
class Counter
{
public:
	Counter(std::string titularName, int gold, std::vector<std::string> magicObjects);
	~Counter();
	void income(int gold, std::vector<std::string> magicObjects);
	void income(int gold);
	void income(std::vector<std::string> magicObjects);
	void showAccount() const;


private:
	std::string m_titularName;
	int m_gold;
	std::vector<std::string> m_magicObjects;
};

