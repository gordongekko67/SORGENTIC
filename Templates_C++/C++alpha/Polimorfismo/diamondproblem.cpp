// diamondproblem.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//
#include "stdafx.h"
#include <iostream>
#include<string>

/* Durch benutzung von virtual nach public in Zeile 14 und 19 erm�glicht uns das diamond problem zu l�sen.*/

using namespace std;

class X {
public:
	int a;
};

class Y : public virtual X {
public:
	int b;
};

class Z : public virtual X {
public:
	int c;
};

class W : public Y, public Z {};

int main() {
	W w;
	w.Y::a = 1; // a-Attribut von X geerbt ueber Y
	w.Z::a = 2; // weiteres a-Attribut von X geerbt ueber Z
				//w.a = 3; //geht nicht, da mehrdeutig //durch virtual wieder m�glich
				//denn es gibt nur ein einzg�ges Attribut mit Namen a.


	cout << w.Y::a << " " << w.Z::a << endl;
	w.a = 3;
	cout << w.a << endl;

	w.X::a = 3;
	w.Y::X::a = 4;
	w.Z::X::a = 5;

	cout <<"w.X::a " << w.X::a << endl;


	system("pause");
	return 0;
}