// try_catch.cpp: Hauptprojektdatei.
//
#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    //Im Falle einer nicht konvertierbaren Benutzereingabe soll das Programm nicht abstürzen
    //(Hier: Muss ein String als Zahl eingegeben werden und keine andere Zeichen)
	//Dafür müssen wir die Ausnahme abfangen durch try catch

	String^ eingabe;
	double zahl, wurzel;
	//Definiert den Code Abschnitt, für den die Sie Ausnahmen abfangen wollen
	try {
		Console::WriteLine("Geben Sie eine Zahl ein: ");
		eingabe = Console::ReadLine();

		zahl = Convert::ToDouble(eingabe);

		wurzel = Math::Sqrt(zahl);

		Console::WriteLine("\n Die Wurzel von {0:F} ist {1} \n", zahl, wurzel);
	}
	//Fangen die Ausnahmen aus try Block ab und definieren, was beim Auftreten einer Ausnahme geschehen soll
	catch(Exception ^e) {
		Console::WriteLine("ausnahme ausgelöst, fehler bei der Kompilierung");
	}



    return 0;
}
