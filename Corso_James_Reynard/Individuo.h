#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Individuo
{
public:
    Individuo();
    Individuo(std::string vnome, std::string vcognome)
    {
        nome = vnome;
        cognome = vcognome;
    }
    ~Individuo();

    void setName(std::string &vnome)
    {
        nome = vnome;
    }

    std::string getName()
    {
        return nome;
    }

    void stampaIndividuo()
    {
        std::cout << "  " << nome << "   " << cognome << std::endl;
    }

private:
    std::string nome;
    std::string cognome;
};

#endif