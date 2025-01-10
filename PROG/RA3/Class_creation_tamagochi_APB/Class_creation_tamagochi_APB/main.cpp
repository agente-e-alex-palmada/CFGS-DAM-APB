#include "myheader.h"

void main(){
	int selection;
	bool programRunning = true;
	while (programRunning)
	{
		menu();
		cin >> selection;
		switch (selection)
		{
		case 0:
			
			programRunning = false;
			break;
		case 1:

			system("cls");
			programRunning = true;
			break;
		case 2:

			system("cls");
			programRunning = true;
			break;
		case 3:

			system("cls");
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
}