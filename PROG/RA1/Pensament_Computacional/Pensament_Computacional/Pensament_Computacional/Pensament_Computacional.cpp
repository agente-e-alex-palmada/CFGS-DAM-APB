#include <iostream>
using namespace std;
int main()
{
    //Part 1
    int puntuacio, vides, copiaVides;
    cout << "PART 1\n";
    cout << "Digues una puntuacio: " << endl;
    cin >> puntuacio;
    puntuacio = puntuacio + 100;
    cout << "La teva puntuacio ara es: " << puntuacio << endl;
    puntuacio = puntuacio + 100;
    cout <<"La teva puntuacio ara es: " << puntuacio<< endl<<endl;
    //Part 2
    cout << "PART 2\n";
    cout << "Digues el numero de vides: " << endl;
    cin >> vides;
    copiaVides = vides;
    cout <<"La teva vida ara es: " << ++vides << endl;
    cout <<"Y la copia de vides es: " << copiaVides++ << endl;
    cout <<"La teva vida multiplicada per 10: " << vides * 10 << endl;
    cout << "Les teves vides copiades multiplicades per 10: " << copiaVides * 10 << endl<< endl;
    //Part 3
    cout << "PART 3\n";
    unsigned int varala;
    varala = 4294967295;
    cout <<"Nombre maxim de caracters: " << varala << endl<< "Ara sumem 1\n";
    varala = varala + 1;
    cout <<"Sumant 1 surt axio: " << varala << endl;
}

