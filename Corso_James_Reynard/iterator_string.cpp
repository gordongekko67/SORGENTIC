#include <iostream>
#include <string>

using namespace std;

int func(int x){


    return x;
}


int main()
{

    string s = "Hello";

    for (std::string::iterator it = s.begin(); it != s.end(); ++it)
        std::cout << *it << endl;
    std::cout << '\n';



    for (auto& it : s) {
    cout << it << endl;
    }

    int a=1;

    auto  x=func(a);
    cout << x << endl;

    const int a2= 1;
    auto b1=&a2;


    //b1=2;
    




    return 0;
}