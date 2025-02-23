#include <iostream>
#include <string>

using namespace std;

int retornasomma(int x, int y) { return x + y; }

int main() {
    int a = 1;
    int b = 3;
    int c = retornasomma(a, b);
    std::cout << c << "\n";

    return 0;
}