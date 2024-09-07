#include "stdafx.h"
#include "Wald.h"
#include <iostream>
#include "baum.h"

using namespace std;

// ein baum in diese Vektor wird erzeugt 
Wald::Wald()
{
	baeume.push_back(Baum());
	
}

Wald::~Wald()
{
}

void Wald::fuellen() { 
	int anz = 0;
	std::cout << " wie viel " << endl;
	cin >> anz;

	if (anz > 0)
		for (int i = 0; i < anz; i++) {
			
			baeume.push_back(Baum());

		}
		
}
void Wald::printWald() {
	std::cout << "  print wald " << endl;
	
	for (unsigned int i = 0; i <baeume.size(); i++) {
			baeume[i].printWerteBaum();
	}

}
void Wald::wachsenWald() {

	std::cout << "wie viel jahrne soll die wakd wachsen  " << endl;
	
	for (unsigned int i = 0; i <baeume.size(); i++) {
		baeume[i].zufaeling();
	}

}

float  Wald::maxalter() {

	float  max = baeume[0].getAlter();

	for (unsigned int i = 0; i < baeume.size(); i++) {
		if (baeume[i].getAlter() > max) {

			max = baeume[i].getAlter();

		}

	}
	return  max;
}

float  Wald::maxhohe() {

	float  max = baeume[0].getAlter();

	for (int i = 0; i < baeume.size(); i++) {
		if (baeume[i].getHoehe() > max) {

			max = baeume[i].getHoehe();

		}

	}
	return max;
}