#include <iostream>
#include <string>
using namespace std;
int main()
{
	int edat;
	bool esmajor = false;
	int option;
	int numalt;
	int valor;
	bool res;
	int puntu1, puntu2;
	int rang;
	int DNI;
	string letraDNI = "TRWAGMYFPDXBNJZSQVHLCKE";
	int length;
	int opcio;
	double duracio;
	cout << "1.Realitza un programa que demana l'edat i l'indiqui si es major de d'edat amb un booleà (true o false)\n";
	cout << "2.Realitza un programa que adivina si un numero donat per l'usuari es par o no\n";
	cout << "3.Realitza un programa que donat un numero indiqui la quantitat que falta per se un múltiple de 7\n";
	cout << "4.Realitza un programa que indica quan ha durant una partida (en hores, minuts i segons) com a dada origen indicara el numero total de segons jugats\n";
	cout << "5.Realitza un programa que al indicar dues puntuacions indiqui si és: més gran, mes petit o iguals\n";
	cout << "6.Realitza un programa que indiqui el rang en que ha quedat un jugador entre els 10 primer, els 100 primers, els 1000 primers, etc.\n";
	cout << "7.Realitza un programa que al introduir un DNI validi si la lletra es correcte\n";
	cout << "8.The Menu Chooser program presents the user with a menu that lists three difficulty levels and asks him to make a choice. If the user enters a number that corresponds to a listed choice, then he is shown a message confirming the choice. If the user makes some other choice, he is told that the choice is invalid. Then the program asks the user if he wants to play again.\n";
	cout << "Digues quin exercici en vols anar: ";
	cin >> option;
	switch (option)
	{
	case 1:
		//Exercici 1
		cout << "Digues la teva edat: ";
		cin >> edat;
		if (edat >= 18)
		{
			esmajor = true;
			cout << "Ets major de edat\n\n";
		}
		else
		{
			cout << "No ets major de edat\n\n";
		}
		break;
	case 2:
		//Exercici 2
		cout << "Digues un numero: ";
		cin >> numalt;
		res = numalt % 2;
		if (res == 0)
		{
			cout << "El numero que has posat es par.";
		}
		else
		{
			cout << "El numero que has posat no es par\n\n";
		}
		break;
	case 3:
		//Exercici 3
		cout << "Digues un numero: ";
		cin >> numalt;
		if (numalt % 7 == 0)
		{
			cout << "Es multiuple de 7";
		}
		else {
			int valor = ((numalt / 7) + 1) * 7;
			int edat = valor - numalt;
			cout << "Falten " << edat << " numeros per ser un multiple de 7\n";
		}
		break;
	case 4:
		cout << "Digues quants segons ha durat la partida: ";
		cin >> duracio;
		cout << "Aquesta partida ha durat:\n";
		cout << "Minuts: " << duracio / 60 << endl;
		cout << "Hores: " << duracio / 60 / 60 << endl;
		cout << "Dies " << duracio / 60 / 60 / 24 << endl;
		break;
	case 5:
		//Exercici 5
		cout << "Digues dues puntuacions: ";
		cin >> puntu1;
		cout << "Ara l'altre: ";
		cin >> puntu2;
		if (puntu1 < puntu2)
		{
			cout << "La primera puntuacio es mes petita que la segona";
		}
		else if (puntu1 > puntu2)
		{
			cout << "La primera puntuacio es mes gran que la segona";
		}
		else
		{
			cout << "Les dues puntuacions son iguals.";
		}
		break;
	case 6:
		cout << "Digues el teu rang: \n";
		cin >> rang;
		if (rang <= 10)
		{
			cout<< "Estas entre els 10 primers";
		}
		else if (rang <= 100)
		{
			cout << "Estas entre els 100 primers";
		}
		else if (rang <= 1000)
		{
			cout << "Estas entre els 1000 primers";
		}
		else
		{
			cout << "Estas per debaix dels 1000 primers";
		}
		break;
	case 7:
		cout << "Indtrodueix el DNI: ";
		cin >> DNI;

		break;
	case 8:
		cout << "Selecciona una opcio\n";
		cout << "Opcio 1, 2 o 3: ";
		cin >> opcio;
		switch (opcio)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
}