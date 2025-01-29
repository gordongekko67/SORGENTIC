//
//  main.cpp
//  compito1
//
//  Created by Enrico Saccheggiani on 12/11/24.
//

#include <iostream>
#include <vector>

int main(int argc, const char* argv[]) {
    std::string str;
    std::cout << " Enter a string " << std::endl;
    std::cin >> str;

    std::vector<char> v;

    for (auto i : str) {
        std::cout << i << std::endl;
        v.push_back(i);
    }

    std::cout << " vettore " << std::endl;
    for (auto i : v) {
        std::cout << i << std::endl;
    }

    return 0;
}
