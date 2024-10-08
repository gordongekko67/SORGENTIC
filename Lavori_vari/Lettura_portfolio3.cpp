#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

struct OptionPosition {
    std::string strumentoFinanziario;  // Contiene ticker, expiry, strike e type
    double delta;
    double valoreTemporale;
    double valoreTemporalePercentuale;
    int posizione;
    double prezzoMedio;
    double valoreMercato;
    double plGiornaliero;
    double plNonRealizzato;
    double ultimo;
    double modifica;
    double variazionePercentuale;
    double gamma;
    double vega;
    double theta;
    double deltaPortafoglio;
    double gammaPortafoglio;
    double vegaPortafoglio;
    double thetaPortafoglio;
    int giorniRestanti;
    
    // Funzione per estrarre informazioni dallo strumento finanziario
    void parseStrumentoFinanziario() {
        std::istringstream iss(strumentoFinanziario);
        std::string token;
        std::vector<std::string> parts;
        
        while (std::getline(iss, token, ' ')) {
            if (!token.empty()) {
                parts.push_back(token);
            }
        }
        
        if (parts.size() >= 4) {
            ticker = parts[0];
            expiry = parts[1];
            strike = std::stod(parts[2]);
            type = parts[3];
        }
    }
    
    std::string ticker;
    std::string expiry;
    double strike;
    std::string type;
};

class CSVReader {
public:
    static std::vector<OptionPosition> readCSV(const std::string& filename) {
        std::vector<OptionPosition> positions;
        std::ifstream file(filename);
        std::string line;
        
        if (!file.is_open()) {
            std::cerr << "Errore: Impossibile aprire il file " << filename << std::endl;
            return positions;
        }
        
        // Salta l'intestazione
        std::getline(file, line);
        
        while (std::getline(file, line)) {
            OptionPosition pos;
            std::istringstream iss(line);
            std::string token;
            
            std::vector<std::string> values;
            while (std::getline(iss, token, ',')) {
                values.push_back(token);
            }
            
            if (values.size() >= 20) {
                pos.strumentoFinanziario = values[0];
                pos.delta = std::stod(values[1]);
                pos.valoreTemporale = std::stod(values[2]);
                pos.valoreTemporalePercentuale = std::stod(values[3]);
                pos.posizione = std::stoi(values[4]);
                pos.prezzoMedio = std::stod(values[5]);
                pos.valoreMercato = std::stod(values[6]);
                pos.plGiornaliero = std::stod(values[7]);
                pos.plNonRealizzato = std::stod(values[8]);
                pos.ultimo = std::stod(values[9]);
                pos.modifica = std::stod(values[10]);
                pos.variazionePercentuale = std::stod(values[11]);
                pos.gamma = std::stod(values[12]);
                pos.vega = std::stod(values[13]);
                pos.theta = std::stod(values[14]);
                pos.deltaPortafoglio = std::stod(values[15]);
                pos.gammaPortafoglio = std::stod(values[16]);
                pos.vegaPortafoglio = std::stod(values[17]);
                pos.thetaPortafoglio = std::stod(values[18]);
                pos.giorniRestanti = std::stoi(values[19]);
                
                pos.parseStrumentoFinanziario();
                positions.push_back(pos);
            }
        }
        
        return positions;
    }
};

class RollAnalyzer {
private:
    OptionPosition position;
    
    bool checkTimeDecay() const {
        return position.valoreTemporalePercentuale < 10.0;
    }
    
    bool checkDeltaExposure() const {
        return std::abs(position.delta) > 0.25;
    }
    
    bool checkDaysToExpiration() const {
        return position.giorniRestanti < 45;
    }
    
    bool checkThetaDecay() const {
        double dailyThetaPercentage = std::abs(position.theta / position.valoreMercato * 100);
        return dailyThetaPercentage > 0.5;
    }

    bool checkGammaRisk() const {
        return std::abs(position.gamma) > 0.01;
    }

public:
    RollAnalyzer(const OptionPosition& pos) : position(pos) {}
    
    void analyzeRollOpportunity() const {
        std::cout << "\n=== Analisi Opportunità di Roll per " << position.ticker << " " 
                  << position.expiry << " " << position.strike << " " << position.type << " ===\n\n";
        
        std::cout << "Dati posizione corrente:\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Prezzo medio: $" << position.prezzoMedio << "\n";
        std::cout << "Valore di mercato: $" << position.valoreMercato << "\n";
        std::cout << "P&L non realizzato: $" << position.plNonRealizzato << "\n";
        std::cout << "Giorni alla scadenza: " << position.giorniRestanti << "\n\n";
        
        int rollFactors = 0;
        std::cout << "Analisi fattori di roll:\n\n";
        
        if (checkTimeDecay()) {
            std::cout << "1. ⚠️ Valore temporale: " << position.valoreTemporalePercentuale 
                      << "% - BASSO\n";
            rollFactors++;
        } else {
            std::cout << "1. ✅ Valore temporale: " << position.valoreTemporalePercentuale 
                      << "% - Accettabile\n";
        }
        
        // ... [Altri check come nel codice precedente]
        
        std::cout << "\nIMPATTO SUL PORTAFOGLIO:\n";
        std::cout << "Delta portafoglio: " << position.deltaPortafoglio << "\n";
        std::cout << "Gamma portafoglio: " << position.gammaPortafoglio << "\n";
        std::cout << "Vega portafoglio: " << position.vegaPortafoglio << "\n";
        std::cout << "Theta portafoglio: " << position.thetaPortafoglio << "\n\n";
        
        // ... [Resto dell'analisi come nel codice precedente]
    }
};

int main() {
    std::string filename = "portfolio.csv";
    std::vector<OptionPosition> positions = CSVReader::readCSV(filename);
    
    if (positions.empty()) {
        std::cerr << "Nessuna posizione trovata nel file CSV." << std::endl;
        return 1;
    }
    
    for (const auto& position : positions) {
        RollAnalyzer analyzer(position);
        analyzer.analyzeRollOpportunity();
        std::cout << "\n----------------------------------------\n";
    }
    
    return 0;
}