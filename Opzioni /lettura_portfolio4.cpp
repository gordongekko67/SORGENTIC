#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // Per std::find
#include <set>
#include <cmath>
#include <unordered_map>
#include <chrono>

using namespace std;

std::vector<std::string> etichette;
std::vector<double> valori;  // Assume che i valori siano numerici
std::vector<double> theta_totale;  // Aggiungi un vettore per memorizzare il theta
std::set<std::string> titoli_da_tenere_d_occhio;
std::set<std::string> titoli_da_spostare;
std::set<std::string> titoli_rischio_gamma;

void memorset(std::string s) {
    titoli_da_tenere_d_occhio.insert(s);
}

void memorspo(std::string s) {
    titoli_da_spostare.insert(s);
}

void memorgamma(std::string s) {
    titoli_rischio_gamma.insert(s);
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
    std::getline(file, header);

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        std::vector<std::string> fields;

        while (std::getline(ss, value, ',')) {
            fields.push_back(value);
        }

        std::string strumentoFinanziario = fields[0];
        std::string delta = fields[2];
        std::string posizione = fields[4];
        std::string gamma = fields[12]; // Colonna Gamma (12)
        std::string theta = fields[14]; // Colonna Theta (14)

        std::istringstream iss(strumentoFinanziario);
        std::string part1, part2;
        iss >> part1 >> part2;
        std::string simbolo_scadenza = part1 + " " + part2;

        float valore_Delta = stof(delta);
        float valore_Deltaabs = abs(valore_Delta);
        int int_Posizione = stoi(posizione);
        float valore_Delta_riga = int_Posizione * 100 * valore_Delta;

        float valore_Gamma = stof(gamma); // Conversione del valore gamma
        float valore_Theta = stof(theta); // Conversione del valore theta
        float valore_Theta_riga = int_Posizione * 100 * valore_Theta; // Calcolo del theta giornaliero

        auto it = std::find(etichette.begin(), etichette.end(), simbolo_scadenza);
        if (it != etichette.end()) {
            int index = std::distance(etichette.begin(), it);
            valori[index] += valore_Delta_riga;
            theta_totale[index] += valore_Theta_riga; // Aggiunge il theta al simbolo esistente
        } else {
            etichette.push_back(simbolo_scadenza);
            valori.push_back(valore_Delta_riga);
            theta_totale.push_back(valore_Theta_riga); // Inizializza il theta per il nuovo simbolo
        }

        if (valore_Deltaabs > 0.5 && int_Posizione < 0) {
            std::cout << "Attenzione: il titolo è ITM! " << simbolo_scadenza << " pos. " << int_Posizione << " Delta " << valore_Delta << endl;
            memorset(simbolo_scadenza);
        }

        if (valore_Deltaabs < 0.1 && int_Posizione < 0) {
            std::cout << "Attenzione: il titolo è OTM! " << simbolo_scadenza << " pos. " << int_Posizione << " Delta " << valore_Delta << endl;
            memorspo(simbolo_scadenza);
        }

        if (valore_Deltaabs > 0.4 && int_Posizione < 0) {
            std::cout << "Attenzione: il titolo si avvicina a ITM se non lo è già " << simbolo_scadenza << " pos. " << int_Posizione << " Delta " << valore_Delta << endl;
            memorset(simbolo_scadenza);
        }

        // Verifica se la gamma supera una soglia di rischio
        if (valore_Gamma > 0.05) {  // Soglia di esempio: 0.05
            std::cout << "Attenzione: rischio gamma elevato per " << simbolo_scadenza << " con Gamma " << valore_Gamma << endl;
            memorgamma(simbolo_scadenza);
        }
    }

    std::cout << "\nEtichette e valori combinati:" << std::endl;
    for (size_t i = 0; i < etichette.size(); ++i) {
        std::cout << etichette[i] << ": Delta = " << valori[i] << ", Theta = " << theta_totale[i] << std::endl;
    }

    std::vector<std::pair<std::string, double> > etichettaValore;
    for (size_t i = 0; i < etichette.size(); ++i) {
        etichettaValore.push_back(std::make_pair(etichette[i], std::abs(valori[i])));
    }

    std::cout << "\nElementi con relativo delta squilibrato" << std::endl;
    for (const auto& ev : etichettaValore) {
        if (ev.second > 20) {
            cout << "Attenzione! La posizione di " << ev.first << " è squilibrata." << endl;
            memorset(ev.first);
        }
    }

    std::cout << "\nTitoli da tenere d'occhio (ITM):\n";
    for (const auto& simbolo : titoli_da_tenere_d_occhio) {
        std::cout << simbolo << std::endl;
    }

    std::cout << "\nTitoli da spostare (OTM):\n";
    for (const auto& simbolo : titoli_da_spostare) {
        std::cout << simbolo << std::endl;
    }

    // Stampa i titoli a rischio gamma elevato
    std::cout << "\nTitoli con rischio Gamma elevato:\n";
    for (const auto& simbolo : titoli_rischio_gamma) {
        std::cout << simbolo << std::endl;
    }

    file.close();

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
    std::cout << "elapsed time in millisecondi: " << (elapsed_seconds.count()) * 1000 << "ms\n";

    return 0;
}
