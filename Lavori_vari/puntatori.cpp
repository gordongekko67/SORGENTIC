#include <string>
#include <iostream>


using namespace std;


void stampa_array(int arr1[10]){

    int num = sizeof(arr1[10])/arr1[0];

    for (size_t i = 0; i < num; i++)
    {
        /* code */
    }
    


}


int main(){

    int i = 0;

    std::cout <<  " reference di i " <<  &i <<   endl;
    std::cout <<  " valore di i  " <<  i <<   endl;


    int *ptri = &i;

    std::cout <<  " reference di i " << ptri <<   endl;
    std::cout <<  " valore di i  " <<  *ptri <<   endl;
    std::cout <<  " memoroia del puntatore  " <<  &ptri <<   endl;

    int arr[10]= {1,2,3,4,5,6,7,8};
    int num= sizeof(arr)/sizeof(arr[0]);
    

    for (size_t i = 0; i < num; i++)
    {
        std::cout << arr[i]<<  endl;
    }
    
    
    stampa_array(arr);
    



    return 0;
}