// bubblesort6.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

int const Num_ele = 20;
int v[] = { 7,5,67,55,67,34,34,23,90,-33,32,12,56,4,5,6,7,8,9, 22 };

int main()
{
	int a = 0;
	int num_ele = Num_ele;

	for (a = 0; a <= Num_ele; a++)

	{
		for (int x = 0; x < num_ele - 1; x++)
		{
			int scambia;
			if (v[x] > v[x + 1])
			{
				scambia = v[x];
				v[x] = v[x + 1];
				v[x + 1] = scambia;
			}

		}
		num_ele--;
	}
	int n = 0;
	for (n = 0; n < Num_ele; n++)
	{
		std::cout << " " << v[n] << " vecchia  " << n << std::endl;
	}

	int myints[] = { 7,5,67,55,67,34,34,23,90,-33,32,12,56,4,5,6,7,8,9, 22 };
	std::vector<int> myvector(myints, myints + 20);

	std::sort(myvector.begin(), myvector.begin() + 20);           //(12 32 45 71)26 80 53 33

	for (n = 0; n < Num_ele; n++)
	{
		std::cout << " " << myvector[n] << " nuova  " << n << std::endl;
	}








	return 0;
}

