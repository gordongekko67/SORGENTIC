#include <iostream>
#include <string>


std::string exclaim( std::string& s){

    for (int i =0; i < s.size(); i++){

        if (s[i]==','){
            s[i]='!';
        }

    }


    return s;
}



int main(){

    std::string s = "Hello World";

    for (int i=0; i < s.size(); i++)    {
        if (isupper(s[i]))
        {
            std::cout << s[i] << "is upper" << std::endl;
        }
        else{
            if(islower(s[i]))
                std::cout << s[i] << "is lower" << std::endl;
            else
                std::cout << s[i] << "e' na cacata" << std::endl;
        }
    }


    std::string s1= "To be, or not to be, this is the question ";
    std::string s2 =exclaim(s1);

    std::cout << s2 << std::endl;



    return 0;
}