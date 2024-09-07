// DynamischeObjekte.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Mensch {
private:
	int alter;
	string name;
public:
	Mensch(int alter = 0, string name = "kein")
		: alter(alter), name(name) {
		cout << "Konstruktor Aufruf Klasse Mensch" << endl;
	}
	virtual ~Mensch() { cout << "Destruktor Klasse Mensch" << endl; }
};
class Student : public Mensch {
private:
	int matrNr;
public:
	Student(int x) { 
		matrNr = x;
		cout << "Konstruktor der Klasse Student" << endl;
	}
	virtual ~Student() { cout << "Destruktor Klasse Student" << endl; }
};

int main() {
	Mensch *felix;
	felix = new Student(2546512);
	delete felix;


	system("pause");
    return 0;
}

