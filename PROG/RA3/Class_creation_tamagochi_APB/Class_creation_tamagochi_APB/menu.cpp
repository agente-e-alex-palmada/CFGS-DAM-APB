#include "myheader.h"
#include "Farm.h"
#include "Critter.h"

void menu(Farm myFarm) {
	cout << "0. Exit\n";
	cout << "1. Create a new Critter\n";
	if (myFarm.getCritterCount() != 0)
	{
		cout << "2. Interact with Critters";
	}
}