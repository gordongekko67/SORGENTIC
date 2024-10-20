#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

    return 0;
}