#include <iostream>
#include "mmr.h"

/// <summary>
/// Utilitzem els namespaces de std, per els cout cin... 
/// I el mmr, de la nostra llibreria
/// </summary>
using namespace std;
using namespace mmr;

int main()
{
    // VARIABLES //
    int mmrClient = 600;    // mmr inicial
    int suma_resta = 10;    // suma o resta de victoria o derrota
    float multiplicador = 1;// multiplicador    
    char selection;         // partida gunyada o perduda
    char seguir = 'n';      // per si ha fet mes pertides o no 

    // bucle on es fara peguntara si ha fet mes pertides i si ha guanyat o perdut
    do
    {
        // pregunta si ha guanyat i la guarda en minuscula
        cout << "Has ganado? (s/n): ";  
        cin >> selection;
        selection = tolower(selection);

        // si ha guanyat
        if (selection == 's')
        {
            // i el multiplicador no supera 3 suma X
            if (multiplicador < 3)
            {
                multiplicador = MMR_class::AddMultiplyer(multiplicador);
            }

            // mostra el mmr que te el client despres de la victoria
            mmrClient = MMR_class::Add(mmrClient, suma_resta, multiplicador);
            cout << mmrClient;
        }

        // si ha perdut
        else if (selection == 'n')
        {
            // i el multiplicador no es inferior a 0 resta X
            if (multiplicador > 0)
            {
                multiplicador = MMR_class::SubtractMultiplyer(multiplicador);
            }

            // mostra el mmr que te el client despres de la derrota
            mmrClient = MMR_class::Subtract(mmrClient, suma_resta, multiplicador);
            cout << mmrClient;
        }

        // si no ha posat s o n que ho torni a al main per tant tornara a fer el bucle (seria millor amb una funcio)
        else
        {
            cout << "Invalid number. Try again.\n";
            continue;
        }
        cout << "\nHas jugat una altre partida (s): ";
        cin >> seguir;
        seguir = tolower(seguir);

    } while (seguir == 's');

    cout << "Has acabat amb un MMR de " << mmrClient << ", gracies per jugar. Torna aviat!!\n";
  

    return 0;
}