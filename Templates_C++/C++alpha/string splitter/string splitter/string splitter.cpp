/* cppbuch/k23/strings/split.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 4. Aufl., korr. Nachdruck 2016
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "showContainer.h"

std::vector<std::string> split(const std::string &s,
	const std::string &trenn) {
	std::vector<std::string> v;
	std::string::size_type start{ 0 };
	std::string::size_type pos;
	do {
		pos = s.find_first_of(trenn, start);
		v.push_back(s.substr(start, pos - start));
		start = pos + 1;
	} while (pos != std::string::npos);
	return v;
}

using namespace std;

int main() {
	string text("The quick brown,fox jumps.over the lazy dog's back.");
	showContainer(split(text, " ,."), "", "*\n");
}