#include <iostream>
#include <string>

using namespace std;


std::string exclaim( std::string & s ){


    for ( std::string::iterator it=s.begin(); it!=s.end(); ++it)
    std::cout << *it;


   





        return s;
}


int main(){

    std::string stringa ="To be, or not to be, that is the question: ";
    std:: string a = exclaim(stringa);


    return 0;
}