#include <iostream>
using namespace std;
int main()
{
    cout << "Indica l'ordre del puzzle per resoldre'l\n";
    cout << "Digues entre a, b o c en l'ordre correcte tres cops: ";
    char pregunta1 = 'c', pregunta2 = 'a', pregunta3 = 'a', resposta;
    int acabat = false;
    while (acabat != true)
    {
        cin >> resposta;
        if (resposta == pregunta1) {
            cout << "Correcte, torna a adivinar entre a, b i c: ";
            cin >> resposta;
            if (resposta == pregunta2) {
                cout << "\nCorrecte, torna a adivinar entre a, b i c: ";
                cin >> resposta;
                if (resposta == pregunta3) {
                    acabat = true;
                }
                else {
                    cout << "Ordre incorrecte, torna a intentar desde el principi" << endl;
                }
            }
            else {
                cout << "Ordre incorrecte, torna a intentar desde el principi" << endl;
            }
        }
        else {
            cout << "Ordre incorrecte, torna a intentar desde el principi" << endl;
        }
    }
    cout << "\nPuzle resolt";
    return 0;
}