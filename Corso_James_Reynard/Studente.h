#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Individuo.h"

class Studente : public Individuo
{
public:
    Studente();
    Studente (Individuo(std::string n, std::string c , std::string vmatricola )
    {
        
        numMatricola = vmatricola;
        
    }
    ~Studente();

    void setNumMatricola(std::string &vnome)
    {
        numMatricola = vnome;
    }

    std::string getName()
    {
        return numMatricola;
    }

    void stampaMatricola()
    {
        std::cout << "  " << numMatricola << std::endl;
    }

private:
    std::string numMatricola;
    
};

#endif