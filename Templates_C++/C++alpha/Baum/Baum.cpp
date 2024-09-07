#include "stdafx.h"
#include "baum.h"
#include <iostream>
#include <random>
#include "time.h"
#include <string>
#include <ctime>

int counter = 1;

Baum::Baum() {
	int alter = 0;
	int hohe = 0;
	std::string Typebaum = "";

}

Baum::Baum(int alter, int hohe, std::string Typebaum) {

	this->alter = alter;
	this->hohe = hohe;
	this->Typebaum = Typebaum;

}

Baum::~Baum() {}


void Baum::printWerteBaum() {

	std::cout << "die value auf die Baum sind " << std::endl;
	std::cout << " alter      " << alter << std::endl;
	std::cout << " hohe       " << hohe << std::endl;
	std::cout << " Typebaume  " << Typebaum << std::endl;
}

void Baum::zufaeling() {

	srand(time(0));

	int alter = rand() % 100 + 1;
	int hohe = rand() % 100 + 1;

	std::cout << " alter      " << alter << std::endl;
	std::cout << " hohe       " << hohe << std::endl;
	std::cout << " Typebaume  " << Typebaum << std::endl;
}


void Baum::zufaelingb() {

	srand(static_cast<unsigned>(time(NULL)*counter));
	counter++;

	int a = rand() % 100 + 1;
	int b = rand() % 100 + 1;

	if (a > b) {
		alter = a;
		hohe = b;
	}
	else {
		alter = b;
		hohe = a;
	}

	std::cout << " a      " << a << std::endl;
	std::cout << " b      " << b << std::endl;
	std::cout << " alter      " << alter << std::endl;
	std::cout << " hohe       " << hohe << std::endl;
	std::cout << " Typebaume  " << Typebaum << std::endl;

	
}

void Baum::setalter(int i ) { 
	alter = i;
	
}



	