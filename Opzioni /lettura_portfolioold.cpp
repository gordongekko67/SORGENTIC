







#include <algorithm>  // Per std::find
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>  // Per la gestione delle eccezioni

using namespace std;

std::unordered_map<std::string, double> etichette_valori; // Uso unordered_map per migliorare le ricerche
std::set<std::string> titoli_ITM;
std::set<std::string> titoli_vicini_ITM;
std::set<std::string> titoli_OTM;
std::set<std::string> titoli_Take_Profit;

void memorITM(std::string s) {
    titoli_ITM.insert(s);
}

void memor_vicini_ITM(std::string s) {
    titoli_vicini_ITM.insert(s);
}


void memorOTM(std::string s) {
    titoli_OTM.insert(s);
}


void memor_Take_Profit(std::string s) {
    titoli_Take_Profit.insert(s);
}







// Funzione per calcolare il valore temporale da valoreTemporale
float calcola_valore_temporale(const std::string& valoreTemporale) {
    size_t pos_percentuale = valoreTemporale.find(' ');
    if (pos_percentuale != std::string::npos) {
        std::string estratto = valoreTemporale.substr(0, pos_percentuale);
        return std::stof(estratto);
    }
    return 0.0f;
}

// Funzione per gestire la lettura dei dati e l'analisi
void analizza_dati(const std::string& line) {
    std::stringstream ss(line);
    std::string value;
    std::vector<std::string> fields;

    // Estrai i campi separati da virgola
    while (std::getline(ss, value, ',')) {
        fields.push_back(value);
    }

    // Assumiamo che i campi siano ordinati come nell'intestazione
    std::string strumentoFinanziario = fields[0];
    std::string delta = fields[2];
    std::string valoreTemporale = fields[3];
    std::string posizione = fields[4];
    std::string pLnonRealizzato = fields[9];

    std::string campo4 = fields[4];
    std::string campo5 = fields[5];
    std::string campo6 = fields[6];
    std::string campo7 = fields[7];
    std::string campo8 = fields[8];
    std::string campo9 = fields[9];


    // Estrai simbolo e scadenza
    std::istringstream iss(strumentoFinanziario);
    std::string part1, part2;
    iss >> part1 >> part2;
    std::string simbolo_scadenza = part1 + " " + part2;

    // Calcola i valori
    float valore_Delta = stof(delta);
    float valore_Deltaabs = abs(valore_Delta);
    int int_Posizione = stoi(posizione);
    

    //
    int valore_Non_Realizzato = std::stoi(pLnonRealizzato);

    float valore_Delta_riga = int_Posizione * 100 * valore_Delta;

    float valore_temporale = calcola_valore_temporale(valoreTemporale);

    // Verifica se l'opzione è venduta (posizione < 0) e valore temporale inferiore a 1
    if (int_Posizione < 0 && valore_temporale < 1.0) {
        std::cout << "ALLARME: Opzione venduta con valore temporale inferiore a 1$!"
                  << "\nSimbolo: " << simbolo_scadenza
                  << ", Valore temporale: " << valore_temporale << "$\n";
    }

    // Gestione delle etichette
    auto it = etichette_valori.find(simbolo_scadenza);
    if (it != etichette_valori.end()) {
        it->second += valore_Delta_riga;  // Somma al valore esistente
    } else {
        etichette_valori[simbolo_scadenza] = valore_Delta_riga;  // Aggiungi nuova etichetta
    }

    // Analisi delle posizioni ITM e OTM
    if (valore_Deltaabs > 0.5 && int_Posizione < 0) {
        std::cout << "Attenzione, il titolo è ITM! " << simbolo_scadenza << " Posizione: " << int_Posizione << " Delta: " << valore_Delta << "\n\n";
        memorITM(simbolo_scadenza);
    }

    if (valore_Deltaabs < 0.1 && int_Posizione < 0) {
        std::cout << "Attenzione, il titolo è OTM! Potrebbe essere utile prendere profitto: " << simbolo_scadenza << " Posizione: " << int_Posizione << " Delta: " << valore_Delta << "\n\n";
        memorOTM(simbolo_scadenza);
    }

    if (valore_Deltaabs > 0.4 && valore_Deltaabs <= 0.5 && int_Posizione < 0) {
        std::cout << "Attenzione, il titolo si avvicina a ITM se non lo è già: " << simbolo_scadenza << " Posizione: " << int_Posizione << " Delta: " << valore_Delta << "\n\n";
        memor_vicini_ITM(simbolo_scadenza);
    }

    if (valore_Deltaabs > 0.5 && int_Posizione < 0 && valore_Non_Realizzato > 0) {
        std::cout << "ATTENZIONE! Il titolo si può vendere - possibile presa di profitto: " << simbolo_scadenza << " Posizione: " << int_Posizione << " Valore Non Realizzato: " << valore_Non_Realizzato << " Delta: " << valore_Delta << "\n\n";
        memor_Take_Profit(simbolo_scadenza);
    }
}

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    std::string filePath = "/Users/enricosaccheggiani/Henry/Sorgenti_Python/UtilitiesIB/mysite/portfoliook.csv";
    std::ifstream file(filePath);

    if (!file) {
        std::cerr << "Errore nell'apertura del file: " << filePath << std::endl;
        return 1;
    }

    std::string header;
    std::getline(file, header);  // Leggi l'intestazione

    std::string line;
    while (std::getline(file, line)) {
        try {
            analizza_dati(line);
        } catch (const std::exception& e) {
            std::cerr << "Errore nella riga: " << line << "\n" << e.what() << std::endl;
        }
    }

    // Visualizza i titoli ITM
    std::cout << "\nTitoli ITM:\n\n";
    for (const auto& titolo : titoli_ITM) {
        std::cout << titolo << std::endl;
    }

    // Visualizza i titoli da spostare
    std::cout << "\nTitoli sui quali valutare se prendere profitto:\n\n";
    for (const auto& titolo : titoli_OTM) {
        std::cout << titolo << std::endl;
    }

     // Visualizza i titoli da tenere d'occhio
     std::cout << "\nTitoli vicini ITM:\n";
     for (const auto& titolo : titoli_vicini_ITM) {
         std::cout << titolo << std::endl;
     }

      // Visualizza i titoli da prendere profitto
      std::cout << "\nTitoli sui quali valutare se prendere profitto:\n";
      for (const auto& titolo : titoli_Take_Profit) {
          std::cout << titolo << std::endl;
      }




    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Tempo di esecuzione: " << elapsed_seconds.count() << "s\n";

    return 0;
}
