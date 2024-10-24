#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class ge_5
{
public:
    bool operator()(const std::string &s)
    {
        return s.size() > 5;
    }
};

bool return_5(const std::string &s, const int& n)
{
    return s.size() > n;
}

int main()
{

    std::vector<std::string> v;
    v.push_back("AAAA");
    v.push_back("bbb");
    v.push_back("ccccccccAAAA");
    v.push_back("cfdsdsdfdfdfdfcccccccAAAA");
    v.push_back("d");

    for (auto a : v) {
        std::cout << a << std::endl;
        if (a.size() > 5){
            std::cout << " trovato stringa superiore a 5 " << a << std::endl;
            break;
        }
    }

    for (auto a : v) {
        std::cout << a << std::endl;
        if (a.size() > 5){
            std::cout << " trovato stringa superiore a 5 " << a << std::endl;
            break;
        }
    }



    // Find the first element with more than 5 characters
    // Pass a functor object as predicate
    auto res = find_if(std::begin(v), std::end(v), ge_5());

    // Display it
    if (res != std::end(v))
        std::cout << "Algorithm: the first name with > 5 characters is \"" << *res << "\"\n";

    return 0;
}