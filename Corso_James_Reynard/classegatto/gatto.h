#include <iostream>

class Gatto {
   private:
    int numZampe;
    std::string colorePelo;
    std::string nomeGatto;

   public:
    Gatto() {
        numZampe = 4;
        colorePelo = "BiancoNero";
        nomeGatto = "Fufi";
    }

    Gatto(int numZampeS, std::string colorePeloS, std::string nomeGattoS) {
        numZampe = numZampeS;
        colorePelo = colorePeloS;
        nomeGatto = nomeGattoS;
    }

    void stampaGatto() {
        std::cout << " il gatto " << nomeGatto << " numero Zampe " << numZampe
                  << " colore del Pelo " << colorePelo << "\n";
    }
};
