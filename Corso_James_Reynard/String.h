#ifndef STRING_H
#define STRING_H
#include <string>
#include <iostream>

#pragma once



class String
{
public:
    String();
    String(std::string vprotocol,std::string vresource ){

        protocol = vprotocol;
        resource = vresource;
    };

    ~String(){

        std::cout <<  "endclass" << std::endl;
    };


    void stampaStringa (){

        std::cout <<  protocol << ".//"<< resource << std::endl;

    }


private:

    std::string protocol;
    std::string resource;


};

#endif