#include <iostream>
#include <string>


using namespace std;


int main(){

    string s1 ="Hello world";
    string s2 = s1.substr(6);

    string s3 = s1.substr(6,2 );


    std::cout << s2 <<  s3 << endl;


    size_t  numero =s1.find("ell");
    std::cout << numero;





    return 0;
}