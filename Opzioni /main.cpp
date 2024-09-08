#include "CallOption.h"
#include "PutOption.h"
#include "Position.h"
#include "IronCondor.h"
#include <iostream>

int main() {
    CallOption longCall(100, 2.5, 30);
    CallOption shortCall(110, 1.5, 30);
    PutOption longPut(90, 2.0, 30);
    PutOption shortPut(80, 1.0, 30);

    Position lc(&longCall, 1);
    Position sc(&shortCall, -1);
    Position lp(&longPut, 1);
    Position sp(&shortPut, -1);

    IronCondor ironCondor(lc, sc, lp, sp);

    double underlyingPrice = 105;
    std::cout << "Payout totale dell'Iron Condor: " 
              << ironCondor.getTotalPayout(underlyingPrice) << std::endl;
    
    std::cout << "Rischio massimo dell'Iron Condor: " 
              << ironCondor.getRisk() << std::endl;

    return 0;
}
