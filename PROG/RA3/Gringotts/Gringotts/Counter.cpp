#include "Counter.h"

Counter::Counter(std::string titularName, int gold, std::vector<std::string> magicObjects)
{
	m_titularName = titularName;
	m_gold = gold;
	m_magicObjects = magicObjects;
}

Counter::~Counter()
{
}

void Counter::income(int gold, std::vector<std::string> magicObjects)
{
	if (gold < gold * 1.10)
	{
		std::cout << "Interest rate not fullfiled";
	}
	else
	{
		m_gold += gold;
	}
}

void Counter::income(int gold)
{
	if (gold < gold * 1.10)
	{
		std::cout << "Interest rate not fullfiled";
	}
	else
	{
		m_gold += gold;
	}
}

void Counter::income(std::vector<std::string> magicObjects)
{

}

void Counter::showAccount() const
{
	std::string localMagicObjects = (m_magicObjects);
	std::cout << "Titular name: " << m_titularName << std::endl;
	std::cout << "Gold: " << m_gold << std::endl;
	std::cout << "Magic Objects: \n";
	for (size_t i = 0; i < m_magicObjects.size(); i++)
	{
		std::cout << "	" << m_magicObjects[i] << std::endl << std::endl;
	}
	
}
