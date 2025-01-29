#include <iostream>

int main(){

    std::vector<int> v{1,2};
    v.push_back(1);

    for (auto i : v) {
        std::cout << "  prova " << '\n';


    }

    return 0;
}