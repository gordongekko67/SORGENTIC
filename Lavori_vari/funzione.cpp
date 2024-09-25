#include <iostream>
#include <string>

using namespace std;

int funzione(int a, int b)
{

    int c = a + b;
    return c;
}


int funzioneb(int a, int b){

    std::cout << " questa e' la somma " << a+b <<  endl;
    return a+b;
}



int main()
{

    int d = funzione(2, 3);
    cout << " valore di d" << d << endl;



    int a =5;
    int b =6;
    int somma = funzioneb(a , b);
}
