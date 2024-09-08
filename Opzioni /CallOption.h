// CallOption.h
#include "Option.h"
#include <algorithm> // Include necessario per std::max

class CallOption : public Option {
public:
    CallOption(double strike, double premium, double expiration)
        : Option(strike, premium, expiration, true) {}

    double getPayout(double underlyingPrice) const override {
        // Assicurati che entrambi gli argomenti di std::max siano di tipo double
        return std::max(0.0, underlyingPrice - strikePrice) - premium;
    }
};
