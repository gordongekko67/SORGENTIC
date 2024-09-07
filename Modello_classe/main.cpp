#include "Persona.h"
#include <iostream>

using namespace std;

int main() {
    // Creazione di una persona con il costruttore di default
    Persona persona1;
    persona1.stampa();
    persona1.stampaSaluto();

    // Creazione di una persona con il costruttore parametrizzato
    Persona persona2("Marco", 30);
    persona2.stampa();
    persona2.stampaSaluto();

    // Modifica dei valori con i setter
    persona1.setNome("Luca");
    persona1.setEta(25);
    persona1.stampa();
    persona1.stampaSaluto();

    return 0;
}
