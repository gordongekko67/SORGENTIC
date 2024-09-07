// Quersumme.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int quersum_calc(int x);

int main()
{
	int in_quersumme;
	cout << " geben Sie bitte eine Nummer fur die Quersumme" << endl;
	cin >> in_quersumme;
	cout << " Die Rechnung ist " << quersum_calc(in_quersumme) << endl;

	return 0;
};

int quersum_calc(int x)
{
	int calc = x;
	int quersumma = 0;
	while (calc > 0)
	{
		int rest = calc % 10;
		calc = calc / 10;
		quersumma = quersumma + rest;
	}
	return quersumma;
}