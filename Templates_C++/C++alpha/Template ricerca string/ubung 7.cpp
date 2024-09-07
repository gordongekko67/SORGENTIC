// ubung 7.cpp : definisce il punto di ingresso dell'applicazione console.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

void foo(double& d, float f) {
	d *= f;
	cout << " funktion  1" << endl;
}
template<typename T, typename S> // #2
void foo(T& t, S s) {
	cout << " funktion  2" << endl;
	t += s;
}
template<>
void foo<double, float>(double& d, float f) { // #3
	cout << " funktion  3" << endl;
	d -= f;
}

template<typename T, typename S>
T calc(T a, S b, T c = 0) {
	return a / b + c;

}

template<typename T, typename S>
void searchecarica(T a, S b, static std::string array1[]) {

	string x = a;
	std::string s = b;
	std::string::size_type n;
	bool cerca = true;
	int npos = 0;
	while (cerca)
	{
		// search from position npos
		n = s.find(x, npos);
		if (n == std::string::npos) {
		    break;
		}
		else {
			array1[n] = x;
			npos = n + 1;
		}
	}
}

int main()
{
	static string array1[100] = {};

	std::string const s = "3 * sin ( x ) + pi * 3.45 / ( tan ( x ) + cos ( x ) )";
	searchecarica<std::string, std::string const >("+", s,array1);
	searchecarica<std::string, std::string const >("-", s, array1);
	searchecarica<std::string, std::string const >("*", s, array1);
	searchecarica<std::string, std::string const >("/", s, array1);
	searchecarica<std::string, std::string const >("(", s, array1);
	searchecarica<std::string, std::string const >(")", s, array1);
	searchecarica<std::string, std::string const >("3", s, array1);
	searchecarica<std::string, std::string const >("3.45", s, array1);
	searchecarica<std::string, std::string const >("sin", s, array1);
	searchecarica<std::string, std::string const >("cos", s, array1);
	searchecarica<std::string, std::string const >("tan", s, array1);
	searchecarica<std::string, std::string const >("pi" , s, array1);
	searchecarica<std::string, std::string const >("x"  , s, array1);

	for (int i = 0; i < 100; i++) {
		cout << array1[i] << " ";
	}
	system("pause");
	return 0;
}