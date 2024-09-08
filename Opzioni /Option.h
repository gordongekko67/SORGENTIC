// Option.h
class Option {
protected:
    double strikePrice;
    double premium;
    double expiration;
    bool isCall;

public:
    Option(double strike, double premium, double expiration, bool isCall)
        : strikePrice(strike), premium(premium), expiration(expiration), isCall(isCall) {}

    virtual ~Option() = default;

    virtual double getPayout(double underlyingPrice) const = 0; // metodo astratto
    double getStrikePrice() const { return strikePrice; }
    double getPremium() const { return premium; }
    bool getIsCall() const { return isCall; }
};
