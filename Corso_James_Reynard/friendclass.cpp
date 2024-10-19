#include <iostream>
#include <string>

class Test
{
    int i = 42;
    std::string s = "Hello";

public:
    friend class Example;
};

class Example
{
public:
    void print(const Test& test)
    {
        std::cout <<" questo e' il valore di test"<<   test.i << std::endl;
    }
};

int main()
{
    Test test;
    Example ex;
    ex.print(test);
    return 0;
}