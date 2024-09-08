// Spread.h
#include "Position.h"
#include <vector>

class Spread {
    std::vector<Position> positions;

public:
    Spread(const std::vector<Position>& pos) : positions(pos) {}

    double getTotalPayout(double underlyingPrice) const {
        double totalPayout = 0;
        for (const auto& pos : positions) {
            totalPayout += pos.getNetPayout(underlyingPrice);
        }
        return totalPayout;
    }

    // Calcolo del rischio massimo (perdita potenziale massima dello spread)
    double getRisk() const {
        double totalRisk = 0;
        for (const auto& pos : positions) {
            totalRisk += pos.getRisk();
        }
        return totalRisk;
    }
};
