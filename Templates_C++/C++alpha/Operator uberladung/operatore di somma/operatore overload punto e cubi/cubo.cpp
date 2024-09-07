#include "stdafx.h"
#include "Cubo.h"
#include <iostream>


//Additionsoperator " + " wird �berladen f�r das Objekt +
Cubo operator+(Cubo p1, Cubo p2)
{
	//Hilfsvariable f�r die R�ckgabe
	Cubo ergebnis;

	//Addition der Einzelwerte
	ergebnis.setX(p1.getX() + p2.getX());
	ergebnis.setY(p1.getY() + p2.getY());
	ergebnis.setZ(p1.getZ() + p2.getZ());
	return ergebnis;
}

std::ostream &operator << (std::ostream &ausgabestrom, Cubo &cubo)
{
	//Ausgabe der Werte eines Cuboes
	ausgabestrom << "(" << cubo.getX() << "," << cubo.getY() << "," << cubo.getZ() << ")";

	//notwendig, um bei der Verwendung danach weitere Werte auszugeben
	return ausgabestrom;
}
