#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main(){

    int x=2;
    bool is_negative = x <0;

    cout  << "the value of is negative is "<< is_negative<< "\n";

    cout << "is negative is " << boolalpha << is_negative;

    x=-2;
    is_negative = x <0;

    cout  << "the value of is negative is "<< is_negative<< "\n";

    cout << "is negative is " << boolalpha << is_negative<< "\n";

    cout << setfill('#');
    cout << left << setw(15 )<< "Penguins"<<  5 <<  endl;
    cout << setw(15 )<< "Polar bears"<<  5 <<  endl;

    cout << setfill(' ');
    cout << right << setw(12 )<< "Penguins "<<  5 <<  endl;
    cout << setw(12 )<< "Polar bears "<<  2 <<  endl;


    cout << setfill('#');
    cout << right << setw(15 )<< "Penguins "<<  5 <<  endl;
    cout << setw(15 )<< "Polar bears "<<  2 <<  endl;





    return 0;
}
