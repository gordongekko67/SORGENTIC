// ohne STL.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
/*

   			                             begin    end
    0        1         2         3         4	   5       <--- Index
[   0   ,    2    ,    4    ,    6    ,    8    ]		  <--- Wert
                                          *begin

*/
// suchende Zahl 7

/* OHNE STL */
/*
template<typename Iterator, typename T>
Iterator finde(Iterator begin, Iterator end, T zahl) {

	while (begin != end && *begin != zahl) {
		begin++;
	}

	return begin;
}


int main()
{

	const int anzahl = 100;
	
	int einContainer[anzahl];

	int *begin = einContainer;			//Zeiger auf das erste element des einContainer ´s

	int *end = einContainer + anzahl;	//Zeiger auf eine stelle nach dem letzten Eintrag
	for (int i = 0; i < anzahl; i++) {
		einContainer[i] = 2 * i;
	}
	int zahl = 0;
	while (zahl != -1) {
		std::cout << "Geben Sie die suchende Zahl ein (-1 = abburch): " << std::endl;
		std::cin >> zahl;

		if (zahl != -1) {
			int *position = finde(begin, end, zahl);


			if (position != end) {
				std::cout << "gefunden an position: " << (position - begin) << std::endl;
			}
			else {
				std::cout << zahl << " nicht gefunden!" << std::endl;
			}
		}
	}
	system("pause");
    return 0;
}
*/
using namespace std;
int main()
{
	std::vector<int> eincontainer(100);

	for (int i = 0; i < eincontainer.size(); i++) {
		eincontainer[i] = 2 * i;
	}



	int zahl = 0;
	while (zahl != -1) {
		std::cout << "Geben Sie die suchende Zahl ein (-1 = abburch): " << std::endl;
		std::cin >> zahl;

		if (zahl != -1) {
			auto position = find(eincontainer.begin(), eincontainer.end(), zahl);
			

			if (position != eincontainer.end()) {
				std::cout << "gefunden an position: " << (position - eincontainer.begin()) << std::endl;
			}
			else {
				std::cout << zahl << " nicht gefunden!" << std::endl;
			}
		}
	}

	for (auto iter : eincontainer) {
		std::cout << iter << " ";
	}
	

	system("pause");
	return 0;
}