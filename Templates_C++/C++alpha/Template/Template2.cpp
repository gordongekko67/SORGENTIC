#include <iostream>
#include <string>
#include <vector>

using namespace std;


template <typename T>
T minimum(const T& lhs, const T& rhs)
{
    return lhs < rhs ? lhs : rhs;
}


template <typename T>
T ordina(const T& a[])
{

    std::sort a;

    return a;
}




int main(){

    //std::cout <<  Max(7.2, 6) << endl;
    std::cout << minimum(7.2, 6.9) << endl;
    std::cout << minimum(7, 6) << endl;
    std::cout << minimum("AAAA", "BBBB6") << endl;

    int arr[10]= {1,2,3,4,5};


    return 0;
}