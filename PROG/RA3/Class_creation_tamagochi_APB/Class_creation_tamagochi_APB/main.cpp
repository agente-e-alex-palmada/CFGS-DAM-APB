#include "myheader.h"
#include "Critter.h"
#include "Farm.h"

int main(){
	
	// Select option
	int selection, selectedCritter;

	// Handles menus
	bool programRunning = true;
	
	// Creates an empty farm
	Farm myFarm({});
	Critter defaultCritter(0, 0, "i", 0);
	cout << "Welcome to Critter Caretaker\n\n";

	// Starts the first menu
	while (programRunning)
	{
		menu(myFarm);
		cin >> selection;
		if (cin.fail() || selection < 0)
		{
			programRunning = true;
		}
		switch (selection)
		{
		case 0:
			system("cls");
			programRunning = false;
			break;
		case 1:
			system("cls");
			programRunning = true;
			//defaultCritter = critterCreator();
			//myFarm.addCritter(defaultCritter);
		case 2:
			system("cls");
			/*if (myFarm.getCritterCount() > 0)
			{
				selectedCritter = critterSelector(myFarm);
			}
			else
			{
				cout << "You have no Critters.\n";
			}*/
			programRunning = true;
			break;
		default:
			system("cls");
			programRunning = true;
			break;
		}
	}
	system("cls");
	cout << "Goodbye\n";
	return 0;
}

void menu(Farm myFarm) {
	cout << "0. Exit\n";
	cout << "1. Create a new Critter\n";
	if (myFarm.getCritterCount() != 0)
	{
		cout << "2. Interact with Critters\n";
	}
}


Critter critterCreator() {
	string name;
	cout << "What name you want to put to your new Critter?\n\nWrite: ";
	getline(cin, name);
	system("cls");

	// Saves the moment the critter has born
	auto now = chrono::system_clock::now();
	time_t bornTime = chrono::system_clock::to_time_t(now);
	Critter newCritter(HUNGER, BOREDOM, name, bornTime);
	return newCritter;
}

int critterSelector(const Farm& myFarm) {
	bool selectingCritter = true;
	int selection;
	while (selectingCritter)
	{
		system("cls");
		cout << "Critters at farm:\n";
		myFarm.listCritters();
		size_t crittersCount = myFarm.getCritterCount();
		cout << "Select which Critter you want to interact: ";
		cin >> selection;
		if (cin.fail() || selection < 0 || selection > crittersCount)
		{
			selectingCritter = true;
		}
	}
	return selection;
}

// This should go to another func

//// Starts the menu
//while (programRunning)
//{
//	menu();
//	cin >> selection;
//	system("cls");
//	if (cin.fail() || selection < 0)
//	{
//		programRunning = true;
//	}
//
//	// Does an interaction depending of the user selection
//	switch (selection)
//	{
//	case 0:
//		programRunning = false;
//		break;
//	case 1:
//		actualHunger = myCritter.getHunger();
//		deathHandler(actualHunger);
//		myCritter.talk();
//		programRunning = true;
//		break;
//	case 2:
//		actualHunger = myCritter.getHunger();
//		deathHandler(actualHunger);
//		myCritter.eat();
//		programRunning = true;
//		break;
//	case 3:
//		actualHunger = myCritter.getHunger();
//		deathHandler(actualHunger);
//		myCritter.play();
//		programRunning = true;
//		break;
//	case 7:
//		myCritter.secretTalk();
//		programRunning = true;
//		break;
//	default:
//		actualHunger = myCritter.getHunger();
//		deathHandler(actualHunger);
//		programRunning = true;
//		break;
//	}
//}