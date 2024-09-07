// Qsort.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */

int values[] = { 40, 10, 100, 90, 20, 25, 1001, 1034, 4500, 34, 45, 67, 90 };

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}



int main()
{
	int numArray = 0;
	numArray = sizeof(values) /sizeof( values[0]);
	qsort(values, numArray, sizeof(int), compare);
	for (int n = 0; n<numArray; n++)
		printf("%d ", values[n]) ;
	system("pause");
    return 0;
}

