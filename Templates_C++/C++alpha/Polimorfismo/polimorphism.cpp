// UB15.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Figur {
public:
	Figur() {}
	~Figur() {}
	virtual  double  flaeche() {
		return  0;
	}
	virtual	void  zeichnen() = 0;
private:
};

class Rechteck : public Figur {
public:
	Rechteck::Rechteck() {
		base = 0;
		altezza = 0;
	};
	Rechteck::Rechteck(double a, double b) {
		base = a;
		altezza = b;
	}
	virtual  double   flaeche() {
		return  base *altezza;
	}
	virtual	void zeichnen()  { 
		std::cout << " print a Rechteck" << std::endl;
		}
private:
	double  base;
	double altezza;
};

class Kreis : public Figur {
public:
	Kreis::Kreis() {
		ray  = 0;
	};

	Kreis::Kreis(int a) {
		ray = a;

	}
	virtual  double  flaeche() {
		return  ray*ray *3.14;
	}
	virtual	void zeichnen() {
		std::cout << " print a Kreis" << std::endl;
	}
private:
	double ray;
};

class Dreieck : public Figur {
public:
	Dreieck::Dreieck() {
		base = 0;
		altezza = 0; 
	};
	Dreieck::Dreieck(double a, double b) {
		base = a;
		altezza = b;
	}
	virtual double flaeche() 	{
		return base*altezza / 2;
	}

	virtual	void zeichnen() {

		std::cout << " print a Dreieck" << std::endl;
	}
private:
	double base;
    double altezza;
};


int main()
{
	vector<	Figur*> objekte;
	Rechteck	rechteck(10, 20);
	Kreis		kreis(23);
	Dreieck		dreieck(10, 20);

	objekte.push_back(&rechteck);
	objekte.push_back(&dreieck);
	objekte.push_back(&kreis);

	for (int i = 0; i < objekte.size(); i++)
	{
		//Aufruf der Methode zum jeweiligen Objekt
		cout << "   " <<  objekte[i]->flaeche() << endl;
		objekte[i]->zeichnen();
	}
		return 0;
	}
	