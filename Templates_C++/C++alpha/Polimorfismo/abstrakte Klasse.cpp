// abstrakte Klasse.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Fahrzeug { //abstrakte (Basis-)Klasse
public:
	virtual void print()  = 0; //rein virtuelle Funktion
}; //Es sind Zeiger auf die abstrakte Klasse moeglich


class Auto : public Fahrzeug {
public:
	 virtual void print() final { cout << "Auto" << endl; }
private: 
	int a;
		 //... weitere zusaetzliche Elemente
};


class Boot : public Fahrzeug {
public:
	virtual void print() { cout << "Boot" << endl; }
private: 
	int b;
		 //... weitere zusaetzliche Elemente
};


int main() {
	const int n = 4;
	Fahrzeug* p[n];			//Feld von Zeigern auf Basisklasse

	
	p[0] = new Boot();
	p[1] = new Auto();
	p[2] = new Auto();
	p[3] = new Boot();

	for (int i = 0; i<n; i++) { 
		cout << i << " "; p[i]->print(); 
	}


	system("pause");
	return 0;
}

