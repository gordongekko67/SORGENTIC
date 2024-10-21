#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



bool is_shorter(std::vector <int>&  arr1, std::vector<int> & arr2){

        return arr1[].size() < arr2[].size();



}



int main()
{

    std::vector<std::string> names;
    names.push_back("Gino");
    names.push_back("Franco");

    for (auto a : names)
    {

        std::cout << a << std::endl;
    }

    sort(begin(names), end(names));

    for (auto a : names)
    {

        std::cout << a << std::endl;
    }


    

    std::vector<int> v1;
    v1.push_back(123);
    v1.push_back(23);

    
    sort (begin (v1),  end(v1), is_shorter(v1,v1) );
    for (auto a : v1)
    {

        std::cout << a << std::endl;
    }





    return 0;
}