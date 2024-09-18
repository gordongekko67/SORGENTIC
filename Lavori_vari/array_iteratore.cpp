#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

 
    int i={1};
    std::cout << "hello world \n";
    std::cout << "hello world \n";



    // iteratore su stringhe co const 
   
   std::string str="ABCD";
   string::const_iterator cit;
   int giro =0;

   for(cit= str.begin(); cit != str.end(); cit++)
   {
        
        cout <<*cit << "|";
        giro++;
        if (giro ==2){
            std::cout << " questo è il sccondo elemento " << *cit <<  endl;
        }


   }
        
    vector <int> vec2= {1,2,3};

    auto iter = begin(vec2);

    





    return 0;
}