#include "MyForm.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>

System::Void Provagrafico::MyForm::pictureBox1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	

	
}

System::Void Provagrafico::MyForm::chart1_Click(System::Object ^ sender, System::EventArgs ^ e)
{


	std::ifstream ip("AApl.csv");

	if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

	std::string date;
	std::string open;
	std::string high;
	std::string low;
	std::string close;
	std::string closeadj;
	std::string volume;
	int count = 0;


	while (ip.good())
	{

		std::string riga;
		std::getline(ip, riga);

		getline(ip, date, ',');
		getline(ip, open, ',');
		getline(ip, high, ',');
		getline(ip, low, ',');
		getline(ip, close, ',');
		getline(ip, closeadj, ',');
		getline(ip, volume, ',');

		int a = stoi(close);
		count++;
				
		chart1->Series["Series1"]->Points->AddXY(count, a);
	}

}
