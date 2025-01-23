#pragma once
#include "Critter.h"
class Farm
{
public:
	// The object farm
	Farm(vector<Critter> critters);
	void addCritter(const Critter& critter);
	void removeCritter(int index);
	void listCritters() const;
	size_t getCritterCount() const;
private:
	vector<Critter> m_critters;
};