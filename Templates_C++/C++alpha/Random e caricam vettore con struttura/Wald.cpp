#include "stdafx.h"
#include "Wald.h"
#include <iostream>
#include "Baum.h"



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
			baeume[i+1].zufaelling();
		}

}
void Wald::printWald() {
	std::cout << "  print wald " << endl;

	for (unsigned int i = 1; i <baeume.size(); i++) {
		baeume[i].printWerteBaum();
		std::cout << "baum" << i << std::endl;
	}

}
void Wald::wachsenWald() {
	std::cout << "  print wald " << endl;

	for (unsigned int i = 0; i <baeume.size(); i++) {
		baeume[i].wachsen();
	}

}

void Wald::altestvalueWald() {
	std::cout << "  cerco i valori piu altri " << endl;
	int grosseAlter = 0;
	float grosseHohe = 0.0;
	

	for (unsigned int i = 0; i <baeume.size(); i++) {

		if (baeume[i].getAlter() > grosseAlter)
			grosseAlter = baeume[i].getAlter();
		if (baeume[i].getHohe() > grosseHohe)
			grosseHohe = baeume[i].getHohe();
		
	}

	std::cout << " Die Wert grosser von Baum sind " << " " << "alter " << grosseAlter << "    hohe " << grosseHohe  << std::endl;




}


void Wald::durschnitteWald() {
	std::cout << "  cerco i valori medi" << endl;
	float TotalAlter = 0;
	float TotalHohe = 0.0;
	int numBaum =0;


	for (unsigned int i = 1; i <baeume.size(); i++) {

		TotalAlter = TotalAlter + baeume[i].getAlter();
		TotalHohe = TotalHohe + baeume[i].getHohe();
		numBaum++;

	}

	std::cout << " Die Durschnitt von alter ist " << numBaum << TotalAlter/numBaum << std::endl;
	std::cout << " Die Durschnitt von Hohe ist " << numBaum << TotalHohe / numBaum << std::endl;



}


void Wald::wachsenWaldSturm () {
	
	}

}