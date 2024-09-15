#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;


int main()
{

    int arr[5] = {1, 2, 3, 2, 1};

    const int gir = sizeof(arr) / sizeof(arr[0]);

    // purtroppo non c'e modo di iterare un array in modo decente

    for (unsigned int i = 0; i < gir; i++)
    {
        cout << " stampa dei valori dell' array " << arr[i] << endl;
    }

    int myNumbers[100] = {10, 20, 30, 40, 50};
    for (int i : myNumbers)
    {
        cout << i << "\n";
    }

    
    
    
    int arr1[5] = {1, 2, 3, 2, 1};
       
   for(auto it:arr1)
      cout<<it<<"primo loop  \n";
   //print the elements of array



    for (auto it= begin(arr1);  it != end(arr1); ++it) {

        cout << *it << "secondo loop \n" <<endl;
        
        
}

    int arr2[] = {1, 2, 3, 4, 5};
	
	cout << "Iterator: ";
	for (auto it = begin(arr2); it != end(arr2); ++it)
		cout << *it << ", ";
	
	cout << endl << "Const iterator: ";
	for (auto it = cbegin(arr2); it != cend(arr2); ++it)
		cout << *it << ", ";
	
	cout << endl << "Reverse iterator: ";
	for (auto it = rbegin(arr2); it != rend(arr2); ++it)
        cout << *it << ", ";
	
	cout << endl << "Const reverse iterator: ";
	for (auto it = crbegin(arr2); it != crend(arr2); ++it)
        cout << *it << ", ";







    return 0;
}