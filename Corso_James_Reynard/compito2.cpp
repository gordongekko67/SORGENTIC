//
//  main.cpp
//  compito1
//
//  Created by Enrico Saccheggiani on 12/11/24.
//

#include <iostream>
#include  <list>


int main(int argc, const char * argv[]) {
        
    std::string str;
    std::cout <<  " Enter a string " << std::endl;
    std::cin >>  str;
    
    std::list<char> l;
        
    for (auto i : str){
        
        std::cout << i << std::endl;
        l.push_back(i);
    }
    
       
    std::cout <<  " lista " << std::endl;
    for (auto i : l){
        
        std::cout << i << std::endl;
        
    }
    
         
    
    
    
    
    return 0;
}
