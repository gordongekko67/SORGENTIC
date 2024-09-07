// Regular ausdruck.cpp : spezzare testo con espressioni regolari 
//

#include "stdafx.h"
#include <regex>
#include <iostream>

int main()
{
	{
		std::string s("aaaa aaaa aaaa ma vaffangul this a fessa e 333  4444 66666  ssort subject has a submarine as a subsequence");
		std::regex rgx("\\s+");
		std::sregex_token_iterator iter(s.begin(),	s.end(),rgx,-1);
		std::sregex_token_iterator end;
		int num = 1;
		for (; iter != end; ++iter)
		{
			std::cout << "  " << num << "  " <<  *iter << '\n';
			num++;
		}

	}

	return 0;
}

