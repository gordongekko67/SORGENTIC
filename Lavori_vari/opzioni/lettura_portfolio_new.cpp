#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <unordered_map>

using namespace std;

// Definiamo una struttura per contenere i valori aggregati
struct GreekValues {
    double delta = 0.0;
    double gamma = 0.0;
    double vega = 0.0;
    double theta = 0.0;
};

std::unordered_map<std::string, GreekValues> portafoglio; // Mappa simbolo_scadenza -> valori greche
std::set<std::string> titoli_da_tenere_d_occhio;

void memorset(std::string s) {
    titoli_da_tenere_d_occhio.insert(s);
    std::cout << "Inserito il valore " << s << endl;
}

int main() {
    std::string filePath="/Users/enricosaccheggiani/Henry/Sorgenti_Python/UtilitiesIB/mysite/portfoliook.csv";
    std::ifstream file(filePath);

    if (!file) {
        std::cerr << "Errore nell'apertura del file: " << filePath << std::endl;
        return 1;
    }

    std::string header;
    std::getline(file, header);  // Leggi intestazione

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> fields;
        std::string value;

        // Estrai i campi separati da virgola
        while (std::getline(ss, value, ',')) {
            fields.push_back(value);
        }

        std::string strumentoFinanziario = fields[0];  // Simbolo
        std::string scadenza = fields[1];  // Scadenza
        std::string delta = fields[2], gamma = fields[12], vega = fields[13], theta = fields[14];
        std::string posizione = fields[4];

        // Calcolo dei valori di delta, gamma, vega, theta
        float valore_Delta = stof(delta), valore_Gamma = stof(gamma), valore_Vega = stof(vega), valore_Theta = stof(theta);
        int int_Posizione = stoi(posizione);

        float valore_Delta_riga = int_Posizione * 100 * valore_Delta;
        float valore_Gamma_riga = int_Posizione * 100 * valore_Gamma;
        float valore_Vega_riga = int_Posizione * 100 * valore_Vega;
        float valore_Theta_riga = int_Posizione * 100 * valore_Theta;

        // Chiave di raggruppamento: simbolo + scadenza
        std::string simbolo_scadenza = strumentoFinanziario + " " + scadenza;

        // Aggiorna i valori aggregati nella mappa
        portafoglio[simbolo_scadenza].delta += valore_Delta_riga;
        portafoglio[simbolo_scadenza].gamma += valore_Gamma_riga;
        portafoglio[simbolo_scadenza].vega += valore_Vega_riga;
        portafoglio[simbolo_scadenza].theta += valore_Theta_riga;

        // Controlli per ITM
        if (abs(valore_Delta) > 0.5 && int_Posizione < 0) {
            std::cout << "Attenzione: Il titolo è ITM " << simbolo_scadenza << endl;
            memorset(simbolo_scadenza);
        }

        if (abs(valore_Delta) > 0.4 && int_Posizione < 0) {
            std::cout << "Il titolo si avvicina a ITM: " << simbolo_scadenza << endl;
            memorset(simbolo_scadenza);
        }
    }

    // Stampa delle posizioni aggregate
    std::cout << "\nPosizioni aggregate per simbolo e scadenza:\n";
    for (const auto& entry : portafoglio) {
        const std::string& simbolo_scadenza = entry.first;
        const GreekValues& valori = entry.second;
        std::cout << simbolo_scadenza << " - Delta: " << valori.delta
                  << ", Gamma: " << valori.gamma
                  << ", Vega: " << valori.vega
                  << ", Theta: " << valori.theta << std::endl;
    }

    // Controllo per posizioni squilibrate (Delta > 20 in valore assoluto)
    std::cout << "\nPosizioni squilibrate (Delta > 20):\n";
    for (const auto& entry : portafoglio) {
        if (abs(entry.second.delta) > 20) {
            std::cout << "Attenzione! La posizione di " << entry.first << " è squilibrata (Delta: " << entry.second.delta << ")\n";
            memorset(entry.first);
        }
    }

    // Stampa dei titoli da tenere d'occhio
    std::cout << "\nTitoli da tenere d'occhio:\n";
    for (const auto& simbolo : titoli_da_tenere_d_occhio) {
        std::cout << simbolo << std::endl;
    }

    file.close();
    return 0;
}
