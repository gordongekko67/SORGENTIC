// Scambiaconpuntatori.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// chiamata per riferimento
void scambia(int &a, int &b)
{

	int temp = a;
	a = b;
	b = temp;

}
// chiamata per indirizzo
void scambia2(int *a, int *b)
{

	int temp = *a;
	*a = *b;
	*b = temp;

}


int main()
{
	// Scambio valori con reference


	
	int n1 = 1;
	int n2 = 2;

	scambia(n1, n2);

	cout << n1 << endl;
	cout << n2 << endl;


	system("pause");

	n1 = 9;
	n2 = 6;

	scambia2(&n1, &n2);

	cout << n1 << endl;
	cout << n2 << endl;


	system("pause");

	 return 0;
}

