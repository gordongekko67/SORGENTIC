// Chrono.cpp : definisce il punto di ingresso dell'applicazione console.
//
#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <thread>

int f()
{
	int a = 5;
	// arbeit 
	for (int i = 0; i < 700000000; i++)		{
		int a = 5;
		} 

	return a;
}



int main()
{
	auto t1 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 7000000; i++) {
		f();
     }
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "f() took "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
		<< " milliseconds\n";








    return 0;
}

