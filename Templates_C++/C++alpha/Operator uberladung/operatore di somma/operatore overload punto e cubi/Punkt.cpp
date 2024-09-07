#include "stdafx.h"
#include "Punkt.h"
#include <iostream>


//Additionsoperator " + " wird �berladen f�r das Objekt +
Punkt operator+(Punkt p1, Punkt p2)
{
	//Hilfsvariable f�r die R�ckgabe
	Punkt ergebnis;

	//Addition der Einzelwerte
	ergebnis.setX(p1.getX() + p2.getX());
	ergebnis.setY(p1.getY() + p2.getY());

	return ergebnis;
}

std::ostream &operator << (std::ostream &ausgabestrom, Punkt &punkt)
{
	//Ausgabe der Werte eines Punktes
	ausgabestrom << "(" << punkt.getX() << "," << punkt.getY() << ")";

	//notwendig, um bei der Verwendung danach weitere Werte auszugeben
	return ausgabestrom;
}
