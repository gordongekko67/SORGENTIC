// Classe di scrittura generica di un file
// per la memorizzazione dei risultati di sistema
//
// SCRIVIFILE.CPP
//
//
#include <iostream>
#include <fstream>

using namespace std;

class Scrivifile
{

public: int numgiorni;
public: int operazioni_vincita;
public: int operazioni_perdita;

public: int Scrivi()

{

    ofstream out("Risultati"); //   file dei risultati

	if(!out) {

		cout << "Impossibile aprire il file.\n";
		return 1;

	}

		out << numgiorni << operazioni_vincita << operazioni_perdita << endl;

	out.close();
	return 0;

		}

};
