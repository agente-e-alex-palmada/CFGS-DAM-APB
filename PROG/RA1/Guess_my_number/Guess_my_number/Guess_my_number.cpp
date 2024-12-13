#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
//Declaro las funcions joc1 i joc2.
void joc1();
void joc2();
int main()
{
	int seleccio;
	cout << "Digues 1 o 2: ";
	cin >> seleccio;
	switch (seleccio)
	{
	case 1:
		cout << "Hola";
		break;
	case 2:
		cout << "Adios";
		break;
	}
	return 0;
}
void joc1() {
	int random, number, attempts = 0;
	bool finish = true;
	//Assigna a random un número aleatori.
	srand(time(NULL));
	random = rand() % 100 + 1;
	cout << "Try to guess which number I selected between 1 to 100: ";
	//Un bucle que mentres el numero introduit no sigui igual que el randomitzat, continuara reproduintse, si és més gran o petit o expresa.
	while (finish)
	{
		cin >> number;
		if (number < random)
		{
			cout << "Too low!\nTry again: ";
			attempts++;
			finish = true;
		}
		else if (number > random)
		{
			cout << "Too high!\nTry again: ";
			attempts++;
			finish = true;
		}
		else
		{
			cout << "\n\nThat's it! You got it in " << attempts << " guesses!\n\n";
			//Termina el bucle i torna al menu de selecció inicial.
			finish = false;
		}
	}
}
void joc2() {
	int number, random,max = 100, min = 1, attempts = 1;
	bool correct = true, truers = true;
	string yn;
	cout << "Please select a number between 1 and 100 and I will try to guess it: ";
	//Un bucle que serveix per validar que el numero introduit sigui el correcte
	while (correct)
	{
		cin >> number;
		if (number > 100 || number < 1 && number != 0)
		{
			cout << "You have to write a number between 1 and 100...\nSelect your number: ";
			correct = true;
		}
		else
		{
			correct = false;
		}
	}
	//Aquest bucle va preguntant si el numero que ha generat és el mateix que hem introduit, si li diem que si, ens diurà quans intents ha fet per endenvinar i tornara al menú de selecció de jocs.
	while (truers)
	{
		random = min+rand() % (max - min);
		cout << "\n\n(The machine can't see your number, you selected \"" << number << "\")";
		cout << "\n\nI selected the number \"" << random << "\"\nIt's your number lower, higher or correct?: \n";
		cin >> yn;
		if (yn == "Higher" || yn == "higher") {
			min = random + 1;
			attempts++;
			truers = true;
		}
		else if (yn == "Lower" || yn == "lower") {
			max = random - 1;
			attempts++;
			truers = true;
		}
		else if (yn == "Correct" || yn == "correct")
		{
			cout << "\nYes! I won!\n\n";
			cout << "It took me " << attempts << " attempts!\n\n";
			truers = false;
		}
		else if (yn == "test")
		{
			cout << min << " " << max;
		}
		else
		{
			cout << "\n\nYou have to write lower, higher or correct";
		}
	}
}
