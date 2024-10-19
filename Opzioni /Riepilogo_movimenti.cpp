#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

// Struttura per memorizzare ogni riga del CSV
struct Trade {
    std::string simbolo;
    double realizzato_totale;
    double non_realizzato_totale;
    double totale;
};

// Funzione per leggere il file CSV
std::vector<Trade> leggiCSV(const std::string& filePath) {
    std::vector<Trade> trades;
    std::ifstream file(filePath);
    std::string line;
    
    // Ignora l'intestazione
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Trade trade;
        std::string field;
        
        // Simbolo
        std::getline(ss, trade.simbolo, ',');
        
        // Realizzato Totale
        std::getline(ss, field, ',');
        trade.realizzato_totale = std::stod(field);
        
        // Non Realizzato Totale
        std::getline(ss, field, ',');
        trade.non_realizzato_totale = std::stod(field);
        
        // Totale
        std::getline(ss, field, ',');
        trade.totale = std::stod(field);
        
        trades.push_back(trade);
    }
    
    return trades;
}

// Funzione per estrarre la data di scadenza e il simbolo
std::pair<std::string, std::string> estraiDataESimbolo(const std::string& simbolo_completo) {
    std::stringstream ss(simbolo_completo);
    std::string simbolo, data_scadenza;
    
    ss >> simbolo >> data_scadenza;
    
    return {data_scadenza, simbolo};
}

// Funzione principale
int main() {
    std::vector<Trade> trades = leggiCSV("/Users/enricosaccheggiani/Henry/Sorgenti_Python/UtilitiesIB/mysite/Movimenti_anno.csv");
    
    // Mappa per raggruppare per data_scadenza_solo e sommare i valori
    std::map<std::string, Trade> trade_raggruppati;
    
    for (const auto& trade : trades) {
        // Estrai data_scadenza e simbolo_solo
        auto [data_scadenza, simbolo_solo] = estraiDataESimbolo(trade.simbolo);
        
        // Crea la chiave "data_scadenza_solo"
        std::string data_scadenza_solo = data_scadenza + " " + simbolo_solo;
        
        // Somma i valori nella mappa
        if (trade_raggruppati.find(data_scadenza_solo) == trade_raggruppati.end()) {
            trade_raggruppati[data_scadenza_solo] = trade;
        } else {
            trade_raggruppati[data_scadenza_solo].realizzato_totale += trade.realizzato_totale;
            trade_raggruppati[data_scadenza_solo].non_realizzato_totale += trade.non_realizzato_totale;
            trade_raggruppati[data_scadenza_solo].totale += trade.totale;
        }
    }
    
    // Emissione delle operazioni raggruppate
    std::cout << "Data_scadenza_solo, Realizzato Totale, Non realizzato Totale, Totale\n";
    double totale_realizzato = 0, totale_non_realizzato = 0, totale_generale = 0;
    
    for (const auto& [key, trade] : trade_raggruppati) {
        if (trade.non_realizzato_totale != 0) {
            std::cout << key << ", " 
                      << trade.realizzato_totale << ", " 
                      << trade.non_realizzato_totale << ", " 
                      << trade.totale << "\n";
                      
            totale_realizzato += trade.realizzato_totale;
            totale_non_realizzato += trade.non_realizzato_totale;
            totale_generale += trade.totale;
        }
    }
    
    // Somma finale
    std::cout << "Totale, " << totale_realizzato << ", " << totale_non_realizzato << ", " << totale_generale << "\n";

    return 0;
}
