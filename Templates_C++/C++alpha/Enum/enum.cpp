// enum.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

enum  Farbtyp { rot,grun, blau, gelb};

enum  class Einkaufe{ nicht_gut, medium, gut, sehr_gut };

struct Person
{
	string Vorname;
	string Nachname;
};

struct Mitarbeiter
{
	struct Person Person1;
	int einkaufe;
	bool isteinegutverkaufer;


};
struct Kunde
{
	struct Person kunde1;
	int einkaufe;
	bool isteinegutkunde;
};



	int main()
{
		cout << " immetti i dati del primo cliente" << endl;
		Kunde k1;
		getline(cin, k1.kunde1.Vorname);
		getline(cin, k1.kunde1.Nachname);
		cin >> k1.einkaufe;

		cout << " il cliente " << k1.kunde1.Vorname << " " << k1.kunde1.Nachname << endl;
		cout << " mit einkaufe " << k1.einkaufe;

		switch (k1.einkaufe)
		{
			case 20:
				cout << " nicht gut einkaufe" << endl;
				break;
			case 40:
				cout << " medium einkaufe" << endl;
				break;
			case 60:
				cout << " gut  einkaufe" << endl;
				break;
        
		}
		
		cout << " dati finali " << endl;
		//cout << " " << static_cast<int>(Einkaufe ::nicht_gut) << endl;
		cout << " " << static_cast<char>(Einkaufe::nicht_gut) << endl;
	return 0;
}

