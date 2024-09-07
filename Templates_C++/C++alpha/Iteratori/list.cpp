// list.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <list> //list-Container der STL
#include <algorithm> //diverse Algorithmen der STL, z.B. find()

using namespace std;

//Ausgabe des Inhalts eines list-Containers:
template <class T>
ostream& operator<<(ostream& os, const list<T>& a) {

	//hier muss const_iterator verwendet werden, da a const deklariert ist!
	list<T>::const_iterator it = a.begin(); //argument dependent name lookup
	
	while (it != a.end()) {
		os << *it << " ";
		++it;
	}
	return os;
}


int main() {
	list<int> a, b; //zwei list-Container a und b anlegen
					//Container mit geraden Zahlen fuellen, Reihenfolge beachten!

	for (int i = 1; i < 5; i++) { 
		a.push_front(2 * i); 
	}
	
	cout << a << endl; //8 6 4 2
	
	b = a; //Zuweisung fuer Container list<int> // 8 6 4 2

	list<int>::pointer p;
	
	
	p = &(*( ++a.begin() ));
	cout << "Zweites Listenelement: " << *p << endl; //Zweites ...: 6

	a.sort(); //Memberfunktion der Klasse list
	cout << a << endl; //2 4 6 8
	cout << b << endl; //8 6 4 2

	list<int>::iterator pos = find(a.begin(), a.end(), 6);
	cout << *pos << endl;	//6
	pos = b.begin();		//Erste Position der Liste b.
	b.splice(pos, a);		//Liste a wird vor Position pos in b eingefuegt.
	cout << *pos << endl;					
								//Dabei wird Liste a geleert.
	cout << b << endl;		//2 4 6 8 8 6 4 2
	cout << a << endl;		//Leerzeichen

	cout << "Anzahl der Elemente: " << a.size() << endl; //Anz. ...: 0
	cout << "Liste a leer: " << boolalpha << a.empty() << endl; //true
	pos = a.insert(a.begin(), 7);
	cout << a << endl; //7

	a.insert(pos, 3); //Element 3 wird vor Position pos eingefuegt
	cout << a << endl; //3 7
	a.pop_back(); //Letztes Element loeschen
	cout << a << endl; //3

	const list<char> c(5, 'x'); //Liste mit 5 Kopien des Elements ’x’
	cout << c << endl; //x x x x x
					   //c.pop_front(); //waere Fehler, da c die Qual. mit const besitzt
	cout << a << endl;
	a.clear(); //alle Listenelemente loeschen
	a = b;
	auto e = a.end();	//2 4 6 8 8 6 4 2    //automatische Typableitung (kuerzer)
	e--; e--;				 //e = e - 2 ist bei list nicht moeglich!
	a.erase(a.begin(), e); //Elemente von a.begin() bis e loeschen.
						   //Dabei wird das Element auf welches e zeigt
						   //nicht geloescht.
	cout << a.empty() << endl;
	cout << a << endl;


	system("pause");
	return 0;
}