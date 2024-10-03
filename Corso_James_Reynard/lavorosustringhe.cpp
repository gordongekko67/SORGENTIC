#include <iostream>
#include <string>
#include <vector>


int main(){

    std::string s1="Hello world";
    std::string s2=s1.substr(6);
    std::string s3=s1.substr(6,2);


    
    
    std::cout << "   "  <<  s1 << "   "  << s2 << "  " << s3 <<  std::endl;




    return 0;
}