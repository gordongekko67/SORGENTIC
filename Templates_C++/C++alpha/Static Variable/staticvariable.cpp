// staticvariable.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int calcola(int a, int b);

int varGlobale;
int x = 6;
double merda = 999999999.999999999999999999999999;


int main()
{
	std::cout << " Var globale vale " << varGlobale << endl;
	varGlobale++;
	std::cout << " Var globale vale " << varGlobale << endl;
	// lanci routine
	calcola(5, 6);
	calcola(5, 6);
	calcola(5, 6);
	calcola(5, 6);
	calcola(5, 6);
	calcola(5, 6);
	varGlobale++;
	std::cout << " Var globale fuori la routine vale " << varGlobale << endl;
	std::cout << " valore di x fuori  la routine  \n " ;
	cout << sizeof(x) << endl;
	cout << sizeof(x) << endl;
	cout << sizeof(merda) << endl;
    return 0;
}

int calcola(int x, int y)
{
	x = 5;
	// variabile statica definizione 
	int  static lanc = 0;
	// variabile locale 
	int valore = 0;
	// incr var locale
	valore = valore + 1;
	// incr variabile statica
	lanc = lanc + 1;
	std::cout << " num di volte progr lanciato" << lanc << " \n";
	std::cout << " variabile valore " << valore << endl;
	varGlobale++;
	std::cout << " Var globale dentro la routine vale " << varGlobale << endl;
	std::cout << " valore di x dentro la routine  \n" << x;

	return x + y;

}