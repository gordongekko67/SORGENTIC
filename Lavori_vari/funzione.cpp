#include <iostream>
#include <string>

using namespace std;

int funzione(int a, int b)
{

    int c = a + b;
    return c;
}

int main()
{

    int d = funzione(2, 3);
    cout << " valore di d" << d << endl;
}
