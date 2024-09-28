#include <iostream>
#include <string>


using namespace std;


int main(){

    int a = 25;
    int b = 33;

    float divide;

    //divide= static_cast<double>(a/b);
    divide = static_cast<double>(a) / b;

    std:: cout <<  divide << endl;

    int c='A';
    cout << c << endl;
    cout << (char)c << endl;



    return 0;
}