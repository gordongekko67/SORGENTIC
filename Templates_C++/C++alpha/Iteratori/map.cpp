// map.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	vector<int> v{ 5,2,8,3 };
	list<int> l{ 7,-3,9 };

	sort(v.begin(), v.end());
	sort(l.begin(), l.end());

	
	
	// Map definieren, Schlüssel ist char und Zusatzwert ist int
	map<char, int> mymap;
	
	mymap.insert(pair<char, int>('a', 100));
	mymap.insert(make_pair('z', 200));

	// Iterator definieren und initialisieren
	map<char, int>::iterator it = mymap.begin();
	//Fügt am Anfang in (it) 
	mymap.insert(it, pair<char, int>('b', 300));
	it = mymap.find('z');

	//Standardmäßig werden die Elemente in einer Map aufsteigend sortiert.
	for (it = mymap.begin(); it != mymap.end(); it++) {
		cout << (*it).first << "=> " << (*it).second << endl;
	}

	//(*it).first = 'd'; nicht erlaubt

	system("pause");
	return 0;
}