/*#include <iostream>
using namespace std;

int main()
{
	int number_of_candy;
	double weight_candy_bar;

	cout << "Enter the number of candy bars in a package and the weight in ounces of one candy bar:\n";
	cout << "Then press return\n";

	cin >> number_of_candy;
	cin >> weight_candy_bar;

	cout << number_of_candy;
	cout << " candy bars\n";
	cout << weight_candy_bar;
	cout << " ounces each\n";
	cout << "Total weight is ";
	cout << number_of_candy * weight_candy_bar;
	cout << " ounces";

	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	char symbol1, symbol2, symbol3;
	cout << "Enter two initials, without any periods:\n";
	cin >> symbol1 >> symbol2;
	cout << "The two initials are:\n";
	cout << symbol1 << symbol2 << endl;
	cout << "Once more with a space\n";
	symbol3 = ' ';
	cout << symbol1 << symbol3 << symbol2 << endl;
	cout << "That's all";
	cout << a;
}*/
#include <iostream>
using namespace std;
int main()
{
	//Exercici 1
	int peus = 0, polzades = 0;
	cout <<"Hi han " << peus << " peus\n" << "Hi han " << polzades <<" polzades\n";
	//Exercici 2
	int var1, var2, var3, var4, var5;
	cout << "Indica quins valors vols posar a les seguents variables (hi han 5):\n";
	cout << var1 << var2, var3, var4, var5;
	//No surt el resultat perque no hem expresat un cin per escoltar quines variables volem que surtin.
	//Exercici 3
	int ftemp;
	cout << "Converteix la teva temperatura Fahrenheit a Celsuis\nIndica la teva temperatura y fes enter: ";
	cin >> ftemp;
	cout << "La teva temperatura Fahrenheit en Celsisus es: ";
	cout << (ftemp - 32) / 1.8;
}

