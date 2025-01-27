#pragma once
#include "Critter.h"
#include "myheader.h"
class Farm
{
public:
	// Constructors
	Farm();
	Farm(vector<Critter> critters);
	
	// Manage Critters
	void addCritter(const Critter& critter);
	void removeCritter(int index);
	
	// List and count Critters
	void listCritters() const;
	size_t getCritterCount() const;

	// 

private:
	vector<Critter> m_critters;
};