#include <iostream>
#include <string>

using  namespace std;


int main(){



    string s1= "Hello";
    std::string::size_type sz;   // alias of size_t
    int num= stoi(s1, &sz);
   
    std::cout <<  num;








}