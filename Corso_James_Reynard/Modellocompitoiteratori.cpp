#include <iostream>
#include <string>
#include <algorithm>
#include <random>


int main(){
    std::vector<int> v;
   std::uniform_int_distribution<> d(1, 1000);

    
    
    
    for (int i=0; i < 10; i++){

        int randomNum = rand() % 1001;
        v.push_back(randomNum);
    }

    for (auto i : v){

        std::cout << i << std::endl;

    }

    auto result = std::max_element(v.begin(), v.end());

    //std::cout << result << std::endl;




    return 0;
}