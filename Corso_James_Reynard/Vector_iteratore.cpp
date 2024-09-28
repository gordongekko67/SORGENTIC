#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main (){

    
    // iterazione basata su iteratori per std::vector
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);



    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
    std::cout << *it << ' ';
    }
    









    return 0;
}