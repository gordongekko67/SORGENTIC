/*
 * ----------------------------------------------------------------------------
 * Nome del programma: Analisi Portafoglio Opzioni
 * Descrizione: Questo programma esegue l'analisi dei dati di un portafoglio di
 *              opzioni finanziarie, calcolando parametri come Delta, valore
 *              temporale e posizione (ITM, OTM, Take Profit). Viene utilizzato
 *              per monitorare il comportamento delle opzioni in un portafoglio
 *              e identificare opportunità di trading.
 * Autore: Enrico Saccheggiani
 * Data di creazione: Febbraio 2025
 * Ultima modifica: Febbraio 2025
 * ----------------------------------------------------------------------------
 * Funzioni principali:
 * - analizza_dati: Analizza una riga del file CSV, estrae i dati e calcola
 *   valori significativi (Delta, valore temporale, posizione).
 * - calcola_valore_temporale: Estrae e converte il valore temporale in formato
 *   numerico.
 * - memorITM, memor_vicini_ITM, memorOTM, memor_Take_Profit: Memorizzano i
 *   titoli in base alla posizione (ITM, OTM, vicini ITM, Take Profit).
 * ----------------------------------------------------------------------------
 * Requisiti:
 * - Il programma legge un file CSV che contiene informazioni sul portafoglio
 *   delle opzioni (esempio: portfoliook.csv).
 * - Il file deve avere un'intestazione e le righe devono essere strutturate in
 *   modo che i dati siano separati da virgole.
 * ----------------------------------------------------------------------------
 * Uso:
 * - Caricare il file portfoliook.csv con i dati delle opzioni.
 * - Eseguire il programma per ottenere un'analisi delle posizioni ITM, OTM,
 *   vicine ITM e potenziali Take Profit.
 * ----------------------------------------------------------------------------
 */

#include <algorithm>  // Per std::find
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <stdexcept>  // Per la gestione delle eccezioni
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

std::unordered_map<std::string, double>
    etichette_valori;  // Uso unordered_map per migliorare le ricerche
std::set<std::string> titoli_ITM;
std::set<std::string> titoli_vicini_ITM;
std::set<std::string> titoli_OTM;
std::set<std::string> titoli_Take_Profit;

// Funzione per memorizzare i titoli ITM
void memorITM(std::string s) { titoli_ITM.insert(s); }

// Funzione per memorizzare i titoli vicini a ITM
void memor_vicini_ITM(std::string s) { titoli_vicini_ITM.insert(s); }

// Funzione per memorizzare i titoli OTM
void memorOTM(std::string s) { titoli_OTM.insert(s); }

// Funzione per memorizzare i titoli per Take Profit
void memor_Take_Profit(std::string s) { titoli_Take_Profit.insert(s); }

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

    // Estrai simbolo e scadenza
    std::istringstream iss(strumentoFinanziario);
    std::string part1, part2;
    iss >> part1 >> part2;
    std::string simbolo_scadenza = part1 + " " + part2;

    // Calcola i valori
    float valore_Delta = stof(delta);
    float valore_Deltaabs = abs(valore_Delta);
    int int_Posizione = stoi(posizione);
    int valore_Non_Realizzato = std::stoi(pLnonRealizzato);

    float valore_Delta_riga = int_Posizione * 100 * valore_Delta;

    float valore_temporale = calcola_valore_temporale(valoreTemporale);

    // Verifica se l'opzione è venduta (posizione < 0) e valore temporale
    // inferiore a 1
    if (int_Posizione < 0 && valore_temporale < 1.0) {
        std::cout
            << "ALLARME: Opzione venduta con valore temporale inferiore a 1$!"
            << "\nSimbolo: " << simbolo_scadenza
            << ", Valore temporale: " << valore_temporale << "$\n";
    }

    // Gestione delle etichette
    auto it = etichette_valori.find(simbolo_scadenza);
    if (it != etichette_valori.end()) {
        it->second += valore_Delta_riga;  // Somma al valore esistente
    } else {
        etichette_valori[simbolo_scadenza] =
            valore_Delta_riga;  // Aggiungi nuova etichetta
    }

    // Analisi delle posizioni ITM e OTM
    if (valore_Deltaabs > 0.5 && int_Posizione < 0) {
        std::cout << "Attenzione, il titolo è ITM! " << simbolo_scadenza
                  << " Posizione: " << int_Posizione
                  << " Delta: " << valore_Delta << "\n\n";
        memorITM(simbolo_scadenza);
    }

    if (valore_Deltaabs < 0.16 && int_Posizione < 0) {
        std::cout << "Attenzione, il titolo è OTM! Potrebbe essere utile "
                     "prendere profitto: "
                  << simbolo_scadenza << " Posizione: " << int_Posizione
                  << " Delta: " << valore_Delta << "\n\n";
        memorOTM(simbolo_scadenza);
    }

    if (valore_Deltaabs > 0.4 && valore_Deltaabs <= 0.5 && int_Posizione < 0) {
        std::cout << "Attenzione, il titolo si avvicina a ITM se non lo è già: "
                  << simbolo_scadenza << " Posizione: " << int_Posizione
                  << " Delta: " << valore_Delta << "\n\n";
        memor_vicini_ITM(simbolo_scadenza);
    }

    if (valore_Deltaabs > 0.5 && int_Posizione < 0 &&
        valore_Non_Realizzato > 0) {
        std::cout << "ATTENZIONE! Il titolo si può vendere - possibile presa "
                     "di profitto: "
                  << simbolo_scadenza << " Posizione: " << int_Posizione
                  << " Valore Non Realizzato: " << valore_Non_Realizzato
                  << " Delta: " << valore_Delta << "\n\n";
        memor_Take_Profit(simbolo_scadenza);
    }
}

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    std::string filePath =
        "/Users/enricosaccheggiani/Henry/Sorgenti_Python/UtilitiesIB/mysite/"
        "portfoliook.csv";
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
            std::cerr << "Errore nella riga: " << line << "\n"
                      << e.what() << std::endl;
        }
    }

    // Stampa tutti i set
    std::cout << "\nTitoli ITM:\n\n";
    for (const auto& titolo : titoli_ITM) {
        std::cout << titolo << std::endl;
    }

    std::cout << "\nTitoli vicini a ITM:\n\n";
    for (const auto& titolo : titoli_vicini_ITM) {
        std::cout << titolo << std::endl;
    }

    std::cout << "\nTitoli OTM:\n\n";
    for (const auto& titolo : titoli_OTM) {
        std::cout << titolo << std::endl;
    }

    std::cout << "\nTitoli per Take Profit:\n\n";
    for (const auto& titolo : titoli_Take_Profit) {
        std::cout << titolo << std::endl;
    }

    std::cout << "\nStampa delle varie posizioni con Delta:\n\n";
    // Loop per leggere e stampare i valori
    for (const auto& [etichetta, valore] : etichette_valori) {
        {
            std::cout << "Etichetta: " << etichetta << " - Valore: " << valore
                      << '\n';
        }
    }

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Elaborazione completata in " << elapsed_seconds.count()
              << " secondi." << std::endl;

    return 0;
}
