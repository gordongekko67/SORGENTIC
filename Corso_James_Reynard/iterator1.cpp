#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

int main()
{

    std::string str = "Hello";

    for (auto i : str)
    {
        std::cout << i << "\n";
    }

    auto res = find(std::begin(str), std::end(str), 'l');
    if (res != std::end(str))
    {
        std::cout << " posizione trovata " << res - str.begin() << std::endl;
    }
    else
    {
        std::cout << " posizione non  trovata " << std::endl;
    }

    for (auto it = str.begin(); it < str.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    for (auto it = str.begin(); it <= str.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}