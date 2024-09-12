#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

#pragma once

class Persona
{
private:
    std::string nome;
    std::string cognome;

public:
    Persona() {
        nome = "Mario";
        cognome = "Rossi";  // Correzione del cognome
    };

    Persona(const std::string vnome, const std::string vcognome) {
        nome = vnome;
        cognome = vcognome;
    };

    ~Persona() {
        // Se non hai risorse da liberare, puoi lasciare vuoto o omettere
    };

    // metodo getter
    std::string getname() {
        return nome;
    }

    // metodo setter
    void setname(std::string n) {
        nome = n;
    }

    void stampaPersona() {
        std::cout << " stampa " << nome << " " << cognome << std::endl;  // Aggiunta di spazio tra nome e cognome
    };
};

#endif
