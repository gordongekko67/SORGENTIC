// Ubung12c.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include "Baum.h"
#include <string>
#include "Wald.h"
#include <ctime>

using namespace std;
counter = 1;

string arr[50];

int main()
{

	Baum b1;
	b1.zufaelling();
	b1.ausgabeBaum();


	for (int i = 0; i < 50; i++)
	{
		b1.zufaellingb();
		b1.ausgabeBaum();
	}

	int durschrittTotalAlter = 0;
	float durschrittTotalHohe = 0;

	for (int i = 0; i < 50; i++)
	{
		b1.zufaelling();
		arr[i] = std::to_string(b1.getAlter()) + std::to_string(b1.getHohe()) + b1.getType();
		durschrittTotalAlter = durschrittTotalAlter + b1.getAlter();
		durschrittTotalHohe = durschrittTotalHohe + b1.getHohe();
		std::cout << arr[i] << std::endl;
	}
	int durschittAlter = durschrittTotalAlter / 10000;
	float durschittHohe = durschrittTotalHohe / 10000;
	std::cout << "die value durschritte Alter ist " << durschittAlter;
	std::cout << "die value durschritte Hohe ist " << durschittHohe;

	system("cls");

	b1.zufaelling();
	for (int i = 0; i < 50; i++)
	{
		b1.wachsen();
		arr[i] = std::to_string(b1.getAlter()) + std::to_string(b1.getHohe()) + b1.getType();
		std::cout << arr[i] << std::endl;
	}
	system("pause");

	
	//Objekt wald von der Klasse Wald
	Wald wald;
	wald.fuellen();
	wald.printWald();

	std::cout << " die wald wachsen fur wie viele jahrne" << endl;
	int jahrne;
	cin >> jahrne;

	for (int i = 0; i < jahrne; i++)
	{
		wald.wachsenWald();
		
	} 

	wald.printWald();
	wald.altestvalueWald();
	wald.durschnitteWald();


	std::cout << " die wald wachsen fur wie viele jahrne fur StuM simulation" << endl;
	int jahrne;
	cin >> jahrne;
	int tot1 = 0;
	int tot2 = 0;
	bool flagstorm = false;
	int casual = 0;
		
	for (int i = 0; i < jahrne; i++)
	{
		
		int rest = i % 20;
		if 	(i == 0 || rest == 0) && (flagstorm = false ){
			int casual = rand() % (20 + 1);
			casual = i + casual;
			flagstorm = true;
		} 
			
		if (casual = i)	{
			int rest5 = i% 5;
			if (rest5 == 0)

				alter = 0;
			hohe = 0;



		} 


			srand(static_cast<unsigned>(time(NULL)*counter));
		counter++;

		alter++;
		float hohetmp = rand() % (100 + 1);
		hohetmp = hohetmp / 100;
		hohe = hohe + hohetmp;

		


		

	}







	system("pause");
	return 0;
}

