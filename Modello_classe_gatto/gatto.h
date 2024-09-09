#include <iostream>
#include <string>

class Gatto
{
private:
    // Attributi privati
    std::string nome;
    int zampe;
    int orecchie;

public:
    // Costruttori
    Gatto() : nome(""), zampe(4), orecchie(2) {}  // Costruttore di default
    Gatto(std::string vnome, int vzampe, int vorecchie) : nome(vnome), zampe(vzampe), orecchie(vorecchie) {}  // Costruttore parametrico

    // Distruttore
    ~Gatto() {
        std::cout << "Il gatto " << nome << " è stato distrutto." << std::endl;
    }

    // Metodi pubblici getter
    std::string getName() const {
        return nome;
    }

    int getZampe() const {
        return zampe;
    }

    int getOrecchie() const {
        return orecchie;
    }

    // Metodi pubblici setter
    void setName(const std::string &vnome) {
        nome = vnome;
    }

    void setZampe(int vzampe) {
        zampe = vzampe;
    }

    void setOrecchie(int vorecchie) {
        orecchie = vorecchie;
    }

    // Metodo per miagolare
    void miagola() const {
        std::cout << "Miaoooooo io sono " << nome << "!" << std::endl;
    }

    
};

