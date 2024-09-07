// fakul1.cpp : fakul mit rekursion
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int calcFatt(int numero);	/*1*/

int main() {
	int n, fat;
	cout << "Calcola il fattoriale di un numero" << endl;
	cout <<"Introdurre il numero "<<endl;
	cin >> n;
	fat = calcFatt(n);	/*2*/
	printf("\n Fattoriale di %d = %d", n, fat);
}

/* Calcola Fattoriale utilizzando la Ricorsione*/

int calcFatt(int numero) {
	int f;
	if (!numero)	/*3*/
		f = 1;
	else
		f = numero*calcFatt(numero - 1);	/*4*/
	return f;
}