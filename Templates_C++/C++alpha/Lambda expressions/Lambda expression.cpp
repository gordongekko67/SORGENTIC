// Lambda expression.cpp : definisce il punto di ingresso dell'applicazione console.
//
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

struct isOdd // ritorna true se e' dispari
{
	bool operator () (int x)	{return x % 2;	}

};


int main()
{

	std::vector <int >  v = { 1, 2, 3, 4, 5, 6, 7, 7, 8, 8, 78, 55, 667, 45, 34, 34, 23, 89, 7, 67};
	// conta in c tutti i dispari 
	auto c = std::count_if (begin(v), end(v),  isOdd());
	std::cout << c << std::endl;
	return 0;
}

