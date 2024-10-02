// punt a funzione.cpp : definisce il punto di ingresso dell'applicazione console.
//

//#include "stdafx.h"
#include <iostream>

using namespace std;

int Add(int nx, int ny){
	return nx + ny;
}

int Subd(int nx, int ny){
	return nx - ny;
}

int Mult(int nx, int ny){
	return nx * ny;
}

void func(int x, int y){

	cout << x << y <<  endl;
}


int main()
{
	int nx = 5; int ny = 6;
	int operation;
	do	{
		std::cout << " immetter il tipo di operazione : 0 = add, 1= sub, 2= mult" << endl;
		std::cin >> operation;

	} while (operation < 0 || operation > 2);


	// create a function pointer
	int(*pFcn)(int, int);

	switch (operation)	{

	case 0: pFcn = Add; break;
	case 1: pFcn = Subd; break;
	case 2: pFcn = Mult; break;
	}
	//
	std::cout << " die answer is" << pFcn(nx, ny) << std::endl;

	auto func_ptr = &func;
	(*func_ptr)(1, 2);

	switch (operation)
	{

	case 0:
		(*func_ptr)(1, 2);
		break;
	case 1:
		(*func_ptr)(3, 4);
		break;
	case 2:
		(*func_ptr)(5, 5);
		break;
	}
}