#include "myheader.h"
#include "Critter.h"

void main(){
	int selection, hunger = 75, boredom = 75, actualHunger;
	bool programRunning = true;
	string name;
	auto now = chrono::system_clock::now();
	time_t actualTime = std::chrono::system_clock::to_time_t(now);
	std::cout << "What name you want to put to your new Critter?\n\nWrite: ";
	getline(cin, name);
	system("cls");
	Critter myCritter(hunger, boredom, name, actualTime);
	while (programRunning)
	{
		menu();
		cin >> selection;
		system("cls");
		if (cin.fail() || selection < 0 || selection > 4)
		{
			programRunning = true;
		}
		switch (selection)
		{
		case 0:
			programRunning = false;
			break;
		case 1:
			actualHunger = myCritter.getHunger();
			deathHandler(actualHunger);
			myCritter.talk();
			programRunning = true;
			break;
		case 2:
			actualHunger = myCritter.getHunger();
			deathHandler(actualHunger);
			myCritter.eat();
			programRunning = true;
			break;
		case 3:
			actualHunger = myCritter.getHunger();
			deathHandler(actualHunger);
			myCritter.play();
			programRunning = true;
			break;
		case 7:
			myCritter.secretTalk();
			programRunning = true;
			break;
		default:
			actualHunger = myCritter.getHunger();
			deathHandler(actualHunger);
			programRunning = true;
			break;
		}
	}
	system("cls");
	std::cout << "Goodbye\n";
}