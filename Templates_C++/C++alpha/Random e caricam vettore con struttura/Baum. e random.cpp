#include "stdafx.h"
#include "Baum.h"
#include <iostream>
#include <ctime>
#include "Wald.h"

int counter = 1;


Baum::Baum()
{
	alter = 0;
	hohe = 0.0f;
	typeBaum = "Laub";
}

Baum::Baum(int a , float h, string t)
{
	alter = a;
	hohe = h;
	typeBaum = t;
}

Baum::~Baum()
{
}


void Baum::ausgabeBaum()
{
	std::cout << " Die Wert von Baum sind " << " " << "alter " << alter << "    hohe " << hohe << "      Typebaum " << typeBaum << std::endl;
} 

void Baum::zufaelling()
{
	srand(static_cast<unsigned>(time(NULL)*counter));
	counter++;

	alter = rand() % (100 + 1);
	hohe = rand() % (10000 + 1);
	hohe = hohe / 100;

	if (alter < 50)
		typeBaum = "Laub";
	else
		typeBaum = "NadelBaum";

}

void Baum::zufaellingb()
{
	Baum::zufaelling();
	if (alter < hohe)
	{
		float c = alter;
		alter = hohe;
		hohe = c;
	}

}

int   Baum::getAlter()
{ 
	return alter; 
}
float Baum::getHohe() { return hohe; }
string Baum::getType() { return typeBaum; }


void Baum::wachsen()
{
	srand(static_cast<unsigned>(time(NULL)*counter));
	counter++;

	alter++;
	float hohetmp =  rand() % (100 + 1);
	hohetmp  = hohetmp / 100;
	hohe = hohe + hohetmp;

}

void Baum::printWerteBaum() {

	std::cout << "die value auf die Baum sind " << std::endl;
	std::cout << " alter      " << alter << std::endl;
	std::cout << " hohe       " << hohe << std::endl;
	std::cout << " Typebaume  " << typeBaum << std::endl;
}

void Baum::zufaeling() {

	srand(time(0));

	int alter = rand() % 100 + 1;
	int hohe = rand() % 100 + 1;

	std::cout << " alter      " << alter << std::endl;
	std::cout << " hohe       " << hohe << std::endl;
	std::cout << " Typebaume  " << typeBaum << std::endl;
}