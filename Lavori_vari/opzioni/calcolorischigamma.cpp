#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>

struct Option {
    std::string instrument;
    double delta;
    double gamma;
    double vega;
    double theta;
    double portfolioGamma;
    int daysToExpiry;
};

class PortfolioAnalyzer {
private:
    std::vector<Option> portfolio;
    double gammaRiskThreshold;

public:
    PortfolioAnalyzer(double threshold) : gammaRiskThreshold(threshold) {}

    void loadPortfolioFromCSV(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Errore: Impossibile aprire il file " << filename << std::endl;
            return;
        }

        std::string line;
        // Salta la prima riga (intestazioni)
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string token;
            std::vector<std::string> tokens;

            while (std::getline(iss, token, ',')) {
                tokens.push_back(token);
            }

            if (tokens.size() >= 20) {
                Option option;
                option.instrument = tokens[0];
                option.delta = std::stod(tokens[2]);
                option.gamma = std::stod(tokens[12]);
                option.vega = std::stod(tokens[13]);
                option.theta = std::stod(tokens[14]);
                option.portfolioGamma = std::stod(tokens[16]);
                option.daysToExpiry = std::stoi(tokens[19]);

                portfolio.push_back(option);
            }
        }
    }

    double calculateTotalGammaRisk() const {
        double totalGamma = 0.0;
        for (const auto& option : portfolio) {
            totalGamma += option.portfolioGamma;
        }
        return totalGamma;
    }

    bool isGammaRiskHigh(double totalGamma) const {
        return std::abs(totalGamma) > gammaRiskThreshold;
    }

    void monitorGammaRisk() const {
        double totalGamma = calculateTotalGammaRisk();
        bool riskHigh = isGammaRiskHigh(totalGamma);

        std::cout << "Rischio Gamma Totale del Portafoglio: " << std::fixed << std::setprecision(4) << totalGamma << std::endl;
        if (riskHigh) {
            std::cout << "ATTENZIONE: Il rischio gamma supera la soglia di " << gammaRiskThreshold << std::endl;
        } else {
            std::cout << "Il rischio gamma è entro la soglia accettabile" << std::endl;
        }

        std::cout << "\nAnalisi dettagliata del portafoglio:" << std::endl;
        for (const auto& option : portfolio) {
            std::cout << option.instrument << ":" << std::endl;
            std::cout << "  Gamma: " << std::fixed << std::setprecision(4) << option.gamma << std::endl;
            std::cout << "  Gamma portafoglio: " << option.portfolioGamma << std::endl;
            std::cout << "  Giorni alla scadenza: " << option.daysToExpiry << std::endl;
            std::cout << std::endl;
        }

        if (riskHigh) {
            std::cout << "Suggerimenti per ridurre il rischio gamma:" << std::endl;
            for (const auto& option : portfolio) {
                if (std::abs(option.portfolioGamma) > 1.0) {
                    std::cout << "Considera di aggiustare la posizione su " << option.instrument 
                              << " (Gamma portafoglio: " << std::fixed << std::setprecision(4) 
                              << option.portfolioGamma << ")" << std::endl;
                }
            }
        }
    }
};

int main() {
    PortfolioAnalyzer analyzer(5.0);  // Imposta la soglia di rischio gamma a 5.0

    analyzer.loadPortfolioFromCSV("/Users/enricosaccheggiani/Henry/Sorgenti_Python/UtilitiesIB/mysite/portfoliook.csv");
    analyzer.monitorGammaRisk();

    return 0;
}





