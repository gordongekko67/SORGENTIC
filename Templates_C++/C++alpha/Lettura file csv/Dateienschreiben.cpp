// Dateienschreiben.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//Objekt zur Ausgabe in eine Textdatei (Output File Stream)
	//Erzeugt eine neue Textdatei falls keine vorhanden, ansonsten überschreibt er die alte Datei
	ofstream ausgabeStrom("neu.txt");

	//Prüfen, ob Datei beschrieben werden kann
	if (ausgabeStrom.good())
	{
		for (int i = 0; i < 100; i++)
		{
			// << Pfeil-Operator, um Inhalte an die Datei zu senden
			ausgabeStrom << i+10 << " ";
		}
	}
	ausgabeStrom.close();
	ifstream file("neu.txt");
	string zeile;
	if (file.is_open()) {
		while (getline(file, zeile)) {cout << zeile << endl;}}
	else { cout << "Fehler !" << endl; }
	//Datei als Eingabestrom öffnen (input file stream)
	//Dateipfad eingeben mit namen der Datei
	ifstream dateiStrom("C:\\Users\\Alfa-Dozent\\Documents\\Visual Studio 2017\\Projects\\Dateienschreiben\\Dateienschreiben\\test.txt"); 
	//Gleiche Bedeutung wie oben
	ifstream dateiStream;
	dateiStream.open("test1.txt");
	//Testen, ob Datei geöffnet werden konnte, keine Fehler vorliegen 
	// und das Ende der Datei noch nicht erreicht wurde
	while (dateiStrom.good())
	{
		cout << "Erfolgreich !" << endl;
		//zeilenweise einlesen
		string eineZeile;
		getline(dateiStrom, eineZeile);
	}
	dateiStrom.close();


	system("pause");
    return 0;
}

