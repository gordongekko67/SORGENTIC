// punt a funzione.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
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

int main()
{
	int nx = 5; int ny = 6;
	int operation;
	do	{
		cout << " immetter il tipo di operazione : 0 = add, 1= sub, 2= mult" << endl;
		cin >> operation;

	} while (operation < 0 || operation > 2);


	// create a function pointer
	int(*pFcn)(int, int);

	switch (operation)	{

	case 0: pFcn = Add; break;
	case 1: pFcn = Subd; break;
	case 2: pFcn = Mult; break;
	}
	//
	cout << " die answer is" << pFcn(nx, ny) << endl;
	system("pause");
}