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




    return 0;
}