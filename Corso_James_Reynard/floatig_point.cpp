#include <ios>
#include <iostream>
#include <string>

int main(){

    float pi= 3.1456767676767676766767;
    std::cout << std::scientific << std::uppercase << pi << "\n";

    std::cout << std::fixed <<  pi;
    std::cout << std::defaultfloat <<  pi;

    return 0;
}