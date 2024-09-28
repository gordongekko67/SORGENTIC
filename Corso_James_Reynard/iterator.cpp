#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(){


    std::string str="Hello";

    std::string::const_iterator it;

    for (it=str.begin(); it <str.end() ; it++){

        std::cout << *it << endl;

    }

    std::string::const_iterator cit;

    for (cit=str.cbegin(); cit <str.cend() ; cit++){

        std::cout << *cit << endl;

    }






    std::string::reverse_iterator rit;

    for (rit=str.rbegin(); rit <str.rend() ; rit++){

        std::cout << *rit << endl;

    }

    std::string::reverse_iterator crit;

    for ( crit=str.crbegin(); crit <str.crend(); crit++){

        std::cout << *rit << endl;

    }


    std::string arrstr2[10] = {"aaaa", "bbbbb"};

    for (auto it2 = std::begin(arrstr2); it2 != std::end(arrstr2); it2++) {
        std::cout << *it2 << std::endl;  // Usa std::endl
    }






    #if __cplusplus > 201703L
        cout << "evviva" << endl;
   #endif



    return 0;
}