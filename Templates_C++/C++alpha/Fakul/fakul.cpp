// fakul.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include "time.h"


using namespace std;



int main()
{
	srand(time(NULL));
	int a = rand() % 6 + 1;

	int nummer;
	cout << " schrieben Sie eine nummer " << endl;
	cin >> nummer;
	nt fakul = nummer;
	while (nummer > 1)

	{
		fakul = fakul *(nummer - 1);
		nummer--;

	};
	while (nummer > 1)

	{
		fakul = fakul *(nummer - 1);
		nummer--;

	}

	cout << " Die Fakul fur " << "ist   " << fakul << endl;

	return 0;
}

