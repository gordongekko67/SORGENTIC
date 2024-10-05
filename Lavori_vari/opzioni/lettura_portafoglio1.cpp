#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>  // Necessario per lavorare con file
#include <memory>
#include <map>
#include <sstream>
#include <iomanip>

struct OptionPosition {
    std::string underlying;
    std::string expiry;
    double strike;
    std::string optionType;
    int quantity;
    double delta;
    double gamma;
    double vega;
    double theta;
    int daysToExpiry;
    double marketValue;
    double unrealizedPL;

    // Constructor from CSV row
    static OptionPosition fromCSV(const std::string& row) {
        OptionPosition pos;
        std::istringstream iss(row);
        std::string token;
        std::vector<std::string> tokens;
        
        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        // Parse the instrument string to get underlying, expiry, strike, and type
        std::string instrument = tokens[0];
        pos.parseInstrument(instrument);
        
        pos.delta = std::stod(tokens[2]);
        pos.gamma = std::stod(tokens[12]);
        pos.vega = std::stod(tokens[13]);
        pos.theta = std::stod(tokens[14]);
        pos.quantity = std::stoi(tokens[4]);
        pos.marketValue = std::stod(tokens[6].substr(1));  // Remove the '-' prefix
        pos.unrealizedPL = std::stod(tokens[8]);
        pos.daysToExpiry = std::stoi(tokens[19]);

        return pos;
    }

private:
    void parseInstrument(const std::string& instrument) {
        // Example: AAPL Mar21'25 210 PUT
        std::istringstream iss(instrument);
        iss >> underlying >> expiry >> strike >> optionType;
    }
};

class PortfolioAnalyzer {
private:
    std::vector<OptionPosition> positions;
    std::map<std::string, std::vector<OptionPosition> > strategiesByExpiry;

public:
    void addPosition(const OptionPosition& pos) {
        positions.push_back(pos);
        strategiesByExpiry[pos.expiry].push_back(pos);
    }

    void analyzePortfolio() const {
        std::cout << "=== Portfolio Analysis ===" << std::endl;
        
        // Overall portfolio metrics
        double totalDelta = 0, totalGamma = 0, totalVega = 0, totalTheta = 0;
        double totalValue = 0, totalPL = 0;
        
        for (const auto& pos : positions) {
            totalDelta += pos.delta * pos.quantity;
            totalGamma += pos.gamma * pos.quantity;
            totalVega += pos.vega * pos.quantity;
            totalTheta += pos.theta * pos.quantity;
            totalValue += pos.marketValue;
            totalPL += pos.unrealizedPL;
        }

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Total Portfolio Value: $" << totalValue << std::endl;
        std::cout << "Unrealized P&L: $" << totalPL << std::endl;
        std::cout << "Portfolio Greeks:" << std::endl;
        std::cout << "  Delta: " << totalDelta << std::endl;
        std::cout << "  Gamma: " << totalGamma << std::endl;
        std::cout << "  Vega: " << totalVega << std::endl;
        std::cout << "  Theta: " << totalTheta << std::endl;

        // Analyze by expiration
        std::cout << "\n=== Analysis by Expiration ===" << std::endl;
        for (const auto& [expiry, expiryPositions] : strategiesByExpiry) {
            analyzeExpiryGroup(expiry, expiryPositions);
        }
    }

    void suggestAdjustments() const {
        std::cout << "\n=== Adjustment Suggestions ===" << std::endl;
        
        // Check for near-term expiries that need attention
        for (const auto& [expiry, expiryPositions] : strategiesByExpiry) {
            if (expiryPositions[0].daysToExpiry <= 14) {
                std::cout << "Positions expiring in " << expiryPositions[0].daysToExpiry 
                          << " days (" << expiry << "):" << std::endl;
                
                double expiryDelta = 0;
                for (const auto& pos : expiryPositions) {
                    expiryDelta += pos.delta * pos.quantity;
                }
                
                suggestRollStrategy(expiryPositions, expiryDelta);
            }
        }
    }

private:
    void analyzeExpiryGroup(const std::string& expiry, const std::vector<OptionPosition>& positions) const {
        std::cout << "\nExpiry: " << expiry << " (Days remaining: " << positions[0].daysToExpiry << ")" << std::endl;
        
        double groupDelta = 0, groupGamma = 0, groupTheta = 0;
        for (const auto& pos : positions) {
            groupDelta += pos.delta * pos.quantity;
            groupGamma += pos.gamma * pos.quantity;
            groupTheta += pos.theta * pos.quantity;
        }
        
        std::cout << "  Group Delta: " << groupDelta << std::endl;
        std::cout << "  Group Gamma: " << groupGamma << std::endl;
        std::cout << "  Group Theta: " << groupTheta << std::endl;
    }

    void suggestRollStrategy(const std::vector<OptionPosition>& positions, double expiryDelta) const {
        std::cout << "  Current delta exposure: " << expiryDelta << std::endl;
        
        if (abs(expiryDelta) > 0.5) {
            std::cout << "  Suggestion: Consider rolling to manage delta exposure" << std::endl;
            if (expiryDelta > 0) {
                std::cout << "    - Roll calls up and out for credit" << std::endl;
                std::cout << "    - Roll puts down and out for credit" << std::endl;
            } else {
                std::cout << "    - Roll calls down and out for credit" << std::endl;
                std::cout << "    - Roll puts up and out for credit" << std::endl;
            }
        } else {
            std::cout << "  Delta exposure is relatively neutral" << std::endl;
        }
        
        // Check for potential iron condors or butterflies
        bool hasShortCall = false, hasLongCall = false, hasShortPut = false, hasLongPut = false;
        for (const auto& pos : positions) {
            if (pos.optionType == "CALL") {
                if (pos.quantity < 0) hasShortCall = true;
                if (pos.quantity > 0) hasLongCall = true;
            } else {
                if (pos.quantity < 0) hasShortPut = true;
                if (pos.quantity > 0) hasLongPut = true;
            }
        }
        
        if (hasShortCall && hasLongCall && hasShortPut && hasLongPut) {
            std::cout << "  Strategy appears to be an Iron Condor or Iron Butterfly" << std::endl;
            std::cout << "  Suggestion: Consider rolling entire structure to next month" << std::endl;
            std::cout << "    - Aim for at least 30-45 days until expiration" << std::endl;
            std::cout << "    - Try to roll for a credit to reduce risk" << std::endl;
        }
    }
};

// Main function to demonstrate usage
void analyzePortfolioFromCSV(const std::string& csvContent) {
    PortfolioAnalyzer analyzer;
    std::istringstream iss(csvContent);
    std::string line;
    
    // Skip header
    std::getline(iss, line);
    
    // Process each position
    while (std::getline(iss, line)) {
        if (!line.empty()) {
            try {
                OptionPosition pos = OptionPosition::fromCSV(line);
                analyzer.addPosition(pos);
            } catch (const std::exception& e) {
                std::cerr << "Error processing line: " << line << std::endl;
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    
    analyzer.analyzePortfolio();
    analyzer.suggestAdjustments();
}


int main() {
    std::string filePath = "/Users/enricosaccheggiani/Henry/Sorgenti_Python/UtilitiesIB/mysite/portfoliook.csv";
    
    // Apertura del file
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Errore: Impossibile aprire il file: " << filePath << std::endl;
        return 1;  // Ritorna 1 in caso di errore
    }

    // Lettura del contenuto del file
    std::string csvContent;
    std::string line;
    while (std::getline(file, line)) {
        csvContent += line + "\n";  // Accumula le righe del file nella stringa csvContent
    }

    // Chiude il file
    file.close();

    // Chiamata alla funzione per analizzare il portafoglio
    analyzePortfolioFromCSV(csvContent);

    return 0;
}

