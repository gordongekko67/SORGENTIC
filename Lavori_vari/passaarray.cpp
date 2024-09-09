#include <iostream>
#include <typeinfo> // typeid()
void printArrayOf4(int a[4])
{
std::cout << "Type of arg: " << typeid(a).name() << "\n";
for (int i=0; i<4; i++)
{
std::cout << "index: " << i << " - value: " << a[i] << "\n";
}
}
int main()
{
std::cout << "\n-- Array test -------------\n";
int a1[4] = {1, 2, 3, 4};
std::cout << "Type of a1: " << typeid(a1).name() << "\n";
printArrayOf4(a1);
std::cout << "\n-- Pointer test ------------\n";

return 0;
}