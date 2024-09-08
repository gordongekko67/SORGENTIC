// IronCondor.h
#include "Position.h"

class IronCondor {
    Position longCall;
    Position shortCall;
    Position longPut;
    Position shortPut;

public:
    IronCondor(Position lc, Position sc, Position lp, Position sp)
        : longCall(lc), shortCall(sc), longPut(lp), shortPut(sp) {}

    double getTotalPayout(double underlyingPrice) const {
        return longCall.getNetPayout(underlyingPrice)
             + shortCall.getNetPayout(underlyingPrice)
             + longPut.getNetPayout(underlyingPrice)
             + shortPut.getNetPayout(underlyingPrice);
    }

    // Calcolo del rischio massimo (somma dei rischi delle singole posizioni)
    double getRisk() const {
        double callSpreadRisk = longCall.getRisk() + shortCall.getRisk();
        double putSpreadRisk = longPut.getRisk() + shortPut.getRisk();
        return callSpreadRisk + putSpreadRisk; // Somma dei rischi
    }
};
