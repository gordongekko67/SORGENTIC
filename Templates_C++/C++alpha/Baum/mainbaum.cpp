// mainbaum.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "baum.h"
#include  <iostream>
#include "time.h"
#include <string>
#include <ctime>
#include "Wald.h"
#include <vector>
#include "mainbaum.h"

using namespace std;


int main()
{
	int counter = 1;

	Baum arrayBaum[50];
	
	Baum b1(80, 40, "Laub");
	
	b1.printWerteBaum();
	b1.zufaeling();
	b1.zufaelingb();
	
	int totalAlter = 0;
	int totalHohe = 0;

	for (int i = 0; i < 50; i++) {
		
		arrayBaum[i].zufaelingb();
		
		totalAlter += arrayBaum[i].getAlter();
		totalHohe += arrayBaum[i].getHoehe();
	}

	totalAlter = totalAlter / 50;
	totalHohe = totalHohe/ 50;


	std::cout << " die durchshritte di halte ist " << totalAlter;
	std::cout << " die durchshritte di hohe ist " << totalHohe;

		
	Wald wald;
	wald.fuellen();
	wald.printWald();
	wald.wachsenWald();
	wald.printWald();

	std::cout << " die alterste Baum" << endl;


	system("pause");
    return 0;
}







