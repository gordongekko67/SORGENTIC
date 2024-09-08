// Position.h
#include "Option.h"

class Position {
    Option* option;
    int quantity; // positivo per long, negativo per short

public:
    Position(Option* opt, int qty) : option(opt), quantity(qty) {}

    double getNetPayout(double underlyingPrice) const {
        return quantity * option->getPayout(underlyingPrice);
    }

    // Metodo per calcolare il rischio (massima perdita)
    double getRisk() const {
        if (option->getIsCall()) {
            // Per una call, la perdita massima in una posizione long è il premio pagato
            return quantity > 0 ? option->getPremium() * quantity : 
                                   (std::numeric_limits<double>::infinity());
        } else {
            // Per una put, la perdita massima in una posizione long è il premio pagato,
            // ma in una posizione short è il massimo prezzo sottostante - strike.
            if (quantity > 0) {
                return option->getPremium() * quantity;
            } else {
                return (option->getStrikePrice() - 0) * -quantity - option->getPremium();
            }
        }
    }
};
