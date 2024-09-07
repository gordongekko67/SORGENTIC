#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <regex>
#include <iostream>

using namespace std;
std::vector<char> v;
std::vector<char> vr;

bool is_pali(string s);

int main()
{
	ifstream ip("source.txt");

	if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';


	while (ip.good())
	{
		string riga;
		getline(ip, riga);
		std::string s = riga;
		std::regex rgx("\\s+");
		std::sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
		std::sregex_token_iterator end;
		int num = 1;
		for (; iter != end; ++iter)
		{
			std::cout << "  " << num << "  " << *iter << '\n';
			string stringa = *iter;
			num++;
			bool pali = is_pali(stringa);
			if (pali == true) {
				std::cout << " die wort " << stringa << "ist palindrone" << endl;
			}

		}

	}


	system("pause");
	return 0;
}

bool is_pali(string s) {
		
	if (s.empty())
		return false;

	int i = 0;                // first characters
	int j = s.length() - 1; // last character

	while (i < j)
	{
		if (s[i] != s[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;


	
}