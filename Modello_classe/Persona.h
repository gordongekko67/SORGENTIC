#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
private:
    std::string nome;
    int eta;

public:
    // Costruttore di default
    Persona();

    // Costruttore con parametri
    Persona(std::string n, int e);

    // Getter per nome
    std::string getNome() const;

    // Setter per nome
    void setNome(const std::string& n);

    // Getter per età
    int getEta() const;

    // Setter per età
    void setEta(int e);

    // Metodo per stampare nome e età
    void stampa() const;

    // Metodo per stampare un saluto
    void stampaSaluto() const;
};

#endif // PERSONA_H

















