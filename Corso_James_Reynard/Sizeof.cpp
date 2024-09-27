#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(){

    int i =1;
    char a = 'A';

    uint16_t uin=16;
    int8_t   int8=2;



    std:: cout << "size of int  " << sizeof(i) << endl;
    std:: cout << "size of char  " << sizeof(a) << endl;
    std:: cout << "size of uint16  " << sizeof(uin) << endl;
    std:: cout << "size of int8  " << sizeof(int8) << endl;

    int Hexadecimal = 0X5674;

    int Octal = 067;

    int Binary = 0b101010;




    return 0;
}