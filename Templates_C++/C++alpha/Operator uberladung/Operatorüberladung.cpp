// Operatorüberladung.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Punkt.h"

int main()
{
	Punkt p1(15,20);
	Punkt p2(18,-2.5);
	Punkt summe = p1 + p2;
	
	std::cout << summe << std::endl;
	std::cout << "Hallo" << std::endl;
	
	/*
	Punkt p3;
	p3.x = p1.x + p2.x;
	*/


	system("pause");
    return 0;
}

