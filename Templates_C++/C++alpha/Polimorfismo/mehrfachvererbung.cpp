// mehrfachvererbung.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include<string>

using namespace std;

class Mensch {
public:
	string name;
	virtual void print() = 0;
};

class Student : public Mensch {
public:
	string matrikelnummer;
	void print() { cout << "Student: " << name << ", " << matrikelnummer << endl; }
};

class Uni_Mitarbeiter : public Mensch {
public:
	string personalnummer;
	void print() { cout << "Mitarbeiter: " << name << ", " << personalnummer << endl; }
};

class SHK : public Student, public Uni_Mitarbeiter //erbt von 2 Oberklassen
{
public:
	string projekt;
	void print()
	{
		cout << "SHK: " << Student::name << ", " << projekt << endl;
		cout << matrikelnummer << ", " << personalnummer << endl;
	}
};


int main() {
	SHK h;

	h.Student::name = "Maier";
	//h.Uni_Mitarbeiter::name = "Magath";
	h.matrikelnummer = "1234567";

	h.personalnummer = "Q64829";
	h.projekt = "Multi-Grid Verfahren";
	h.Student::print();
	
	h.Uni_Mitarbeiter::print();
	h.print();
	
	system("pause");
	return 0;
}