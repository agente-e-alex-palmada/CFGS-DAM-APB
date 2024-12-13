#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    //Exercici 1

    //Exercici 2
    int catet1, catet2, hipotenusa;
    cout << "Introdueix la longitud del primer catet:";
    cin >> catet1;
    cout << "Introdueix la longitud del segon catet:";
    cin >> catet2;
    hipotenusa = sqrt((catet1 * catet1) + (catet2 * catet2));
    cout << "La hipotenusa del triangle es: " << hipotenusa<< endl;
    //Exercici 3
    /*El personatge té 100 de vida, cada vegada que puja de nivell augmenta la vida un 10%
    if level+1, health+10%
    */
    int health = 100, level = 0, lvlup;
    while (level != 10)
    {
        cout << "Fes que el teu personatge puji de nivell\nQuants nivells vols que pugi? ";
        cin >> lvlup;
        if (lvlup > 10)
        {
            cout << "El nivell maxim es 10, expresa un valor inferior";
        }
        else
        {
            lvlup + level;
        }
        if (level + 1)
        {
            cout << (health + (health * 0.1));
        }
        cout << "El nivell del personatge es: " << level<< endl;
    }
}