#include "Persona.h"
#include <iostream>

using namespace std;

// Costruttore di default
Persona::Persona() : nome("Sconosciuto"), eta(0) {}

// Costruttore con parametri
Persona::Persona(string n, int e) : nome(n), eta(e) {}

// Getter per nome
string Persona::getNome() const {
    return nome;
}

// Setter per nome
void Persona::setNome(const string& n) {
    nome = n;
}

// Getter per età
int Persona::getEta() const {
    return eta;
}

// Setter per età
void Persona::setEta(int e) {
    eta = e;
}

// Metodo per stampare nome e età
void Persona::stampa() const {
    cout << "Nome: " << nome << ", Età: " << eta << endl;
}

// Metodo per stampare un saluto
void Persona::stampaSaluto() const {
    cout << "Ciao, mi chiamo " << nome << " e ho " << eta << " anni." << endl;
}
