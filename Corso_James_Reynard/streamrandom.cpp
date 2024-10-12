#include <iostream>
#include <string>
#include <sstream>


int main(){

    std::ostringstream output;
    std::string data= ("it's time to say");

    output << data;
    
    auto marker = output.tellp();
    








    return 0;
}