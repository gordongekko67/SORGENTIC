#include <iostream>
#include <string>

using namespace std;

int main()
{

    string s = "Hello";

    for (std::string::iterator it = s.begin(); it != s.end(); ++it)
        std::cout << *it << endl;
    std::cout << '\n';

    return 0;
}