// PutOption.h
#include "Option.h"
#include <algorithm> // Include necessario per std::max

class PutOption : public Option {
public:
    PutOption(double strike, double premium, double expiration)
        : Option(strike, premium, expiration, false) {}

    double getPayout(double underlyingPrice) const override {
        // Assicurati che entrambi gli argomenti di std::max siano di tipo double
        return std::max(0.0, strikePrice - underlyingPrice) - premium;
    }
};
