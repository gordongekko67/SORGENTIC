// ÜB17_2.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Fahrzeug {
protected:
	int geschwindigkeit;
public:
	Fahrzeug(int g) : geschwindigkeit(g) {}

	friend std::ostream& operator << (std::ostream& ausgabestrom, Fahrzeug& f);
};
/*Auto erbt von Fahrzeug und ruft im eigenen Konstrukor den Oberklassen Konstruktor auf und belegt diesen mit der Geschwindigkeit
, da Attribut geschwindigkeit von Fahrzeug ist
*/
class Auto : public virtual Fahrzeug {
protected:
	int plaetze;
public:
	Auto(int g, int p) : Fahrzeug(g), plaetze(p) {}

	friend std::ostream& operator << (std::ostream& ausgabestrom, Auto& a);
};
/*Boot erbt von Fahrzeug und ruft im eigenen Konstrukor den Oberklassen Konstruktor auf und belegt diesen mit der Geschwindigkeit
, da Attribut geschwindigkeit von Fahrzeug ist
*/
class Boot : public virtual Fahrzeug {
protected: 
	std::string ladung;

public:
	Boot(int g, std::string l) : Fahrzeug(g), ladung(l) {}

	friend std::ostream& operator << (std::ostream& ausgabestrom, Boot& b);
};

/*Amphibienfahrzeug erbt von Auto und boot und ruft im eigenen Konstrukor die Oberklassen Konstruktoren von Auto und Boot auf
, da das Attribut geschwindigkeit erstmals nicht direkt angesprochen werden kann.
, Das Attribut geschwindigkeit von Fahrzeug ist in Amphibienfahrzeug nicht ansprechbar, da dieses unter Protected nur für die direkte 
Unterklasse gültig ist
*/
class Amphibienfahrzeug : public Auto, public Boot{
protected: 
	double leistung;

public:
	Amphibienfahrzeug(int g, int p, std::string l, double le) : Fahrzeug(g), Auto(g,p), Boot(g,l), leistung(le) {}

	friend std::ostream& operator << (std::ostream& ausgabestrom, Amphibienfahrzeug& a);
};



std::ostream& operator << (std::ostream& ausgabestrom, Fahrzeug& f) {
	ausgabestrom << "Klasse: Fahrzeug, Geschwindigkeit " << f.geschwindigkeit<<std::endl;

	return ausgabestrom;
}

std::ostream& operator << (std::ostream& ausgabestrom, Auto& a) {
	ausgabestrom << "Klasse: Auto, Geschwindigkeit " << a.geschwindigkeit << ", Plaetze: " << a.plaetze << std::endl;

	return ausgabestrom;
}

std::ostream& operator << (std::ostream& ausgabestrom, Boot& b) {
	ausgabestrom << "Klasse: Boot, Geschwindigkeit " << b.geschwindigkeit << ", ladung: " << b.ladung << std::endl;

	return ausgabestrom;
}

std::ostream& operator << (std::ostream& ausgabestrom, Amphibienfahrzeug& a) {
	ausgabestrom << "Klasse: Amphibienfahrzeug, Geschwindigkeit " << a.geschwindigkeit << ", Plaetze: " << a.plaetze << ", Ladung: " << a.ladung << ", Leistung: " << a.leistung << std::endl;

	return ausgabestrom;
}


int main()
{
	Fahrzeug f(180);
	Auto a(150, 4);
	Boot b(90, "Fische");
	Amphibienfahrzeug af(110, 2, "Autos", 45.2);

	std::cout << f << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << af << std::endl;


	system("pause");
    return 0;
}

