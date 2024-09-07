// Lettura file csv.cpp : definisce il punto di ingresso dell'applicazione console.
//
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ifstream ip("Articol.txt");

	if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

	string date;
	string open;
	string high;
	string low;
	string close;
	string closeadj;
	string volume;

	while (ip.good())
	{

		string riga;
		getline(ip, riga);

		getline(ip, date, ',');
		getline(ip, open, ',');
		getline(ip, high, ',');
		getline(ip, low, ',');
		getline(ip, close, ',');
		getline(ip, closeadj, ',');
		getline(ip, volume, ',');

		std::cout << "Data:" << date << "     ";
		std::cout << "Close:" << close << "     ";
		std::cout << "Volume:" << volume << endl;
		double a = stof(close);
		a = a + 1;
		std::cout << "a:    " << a << endl;
	}
	return 0;
}