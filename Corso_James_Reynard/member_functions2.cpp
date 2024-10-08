#include <iostream>

using namespace std;

int main()
{
    int x = 0;

    while (true)
    {
        cout << "Inserisci un numero intero: ";
        cin >> x;

        if (cin.bad())
        {
            cout << " Hai immesso un numero veramete scorretto prova di inuovo \n";
            cin.clear();            // Resetta lo stato di errore di cin
            cin.ignore(1000, '\n'); // Ignora i caratteri rimanenti nel buffer fino alla nuova linea
        }
        else
        {

            if (cin.fail()) // Se l'input non è valido
            {
                cout << "Hai immesso un valore non valido. Prova di nuovo.\n";
                cin.clear();            // Resetta lo stato di errore di cin
                cin.ignore(1000, '\n'); // Ignora i caratteri rimanenti nel buffer fino alla nuova linea
            }
            else

            {
                cout << "Hai immesso il numero corretto: " << x << "\n";
                break; // Esce dal ciclo una volta che l'input è valido
            }
        }
    }

    return 0;
}
