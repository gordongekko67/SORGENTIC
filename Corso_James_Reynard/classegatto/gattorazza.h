#include <iostream>
#include "gatto.h"

class GattoRazza : public Gatto {
   private:
    std::string nomeRazza;

   public:
    GattoRazza() {
        Gatto();
        nomeRazza = "generico";
    }

    GattoRazza(int numZampeS, std::string colorePeloS, std::string nomeGattoS,
               std::string nomeRazzaS) {
        numZampe = numZampeS;
        colorePelo = colorePeloS;
        nomeGatto = nomeGattoS;
        nomeRazza = nomeRazzaS;
    }

    void stampaGatto() {
        std::cout << " il gatto " << nomeGatto << " numero Zampe " << numZampe
                  << " colore del Pelo " << colorePelo << "\n";
    }
};
