#include <iostream>
#include <string>
 
using std::string;
 
template <typename T>
void swap_generic(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
 
int main()
{
    int i1 = 2;
    int i2 = 6;
     
    string s1("hello");
    string s2("world");
     
    swap_generic(i1, i2);
    std::cout << i1 << ", " << i2 << "\n";
    swap_generic(s1, s2);
    std::cout << s1 << ", " << s2 << "\n";
     
    return 0;
}