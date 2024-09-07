#pragma once
/* cppbuch / include / showContainer.h
Beispiel zum Buch von U.Breymann: Der C++ Programmierer; 4. Aufl., korr.Nachdruck 2016
Diese Software ist freie Software.Website: http://www.cppbuch.de/ 
*/
#ifndef SHOWCONTAINER_H
#define SHOWCONTAINER_H
#include <iostream>

template <class Container>
void showContainer(const Container &container,
	const char *abschluss = "\n",
	const char *trennzeichen = " ") {
	for (const auto &element : container) {
		std::cout << element << trennzeichen;
	}
	std::cout << abschluss;
}

#endif
