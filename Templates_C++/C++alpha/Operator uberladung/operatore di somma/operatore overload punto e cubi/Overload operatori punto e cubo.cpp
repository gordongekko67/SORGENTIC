// Operator�berladung.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Punkt.h"
#include "cubo.h"

int main()
{
	Punkt p1(15, 20);
	Punkt p2(18, -2.5);
	Punkt summe = p1 + p2;

	std::cout << summe << std::endl;
	std::cout << "Hallo somma punti " << std::endl;

	Cubo c1(10, 10, 10);
	Cubo c2(20, 20, 20);
	Cubo summe1 = c1 + c2;
	std::cout << summe1 << std::endl;
	std::cout << "Hallo somma cubi " << std::endl;

	system("pause");
	return 0;
}
