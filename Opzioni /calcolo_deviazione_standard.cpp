#include <iostream>
#include <cmath>
#include <ctime>

// Numero di giorni lavorativi in un anno (ipotizziamo 252)
const int GIORNI_LAVORATIVI_ANNO = 252;

// Funzione per calcolare i giorni lavorativi da oggi fino alla scadenza
int calcolaGiorniLavorativi(int giorniTotali) {
    int giorniLavorativi = 0;
    std::time_t oggi = std::time(nullptr);
    std::tm dataScadenza = *std::localtime(&oggi);

    for (int i = 0; i < giorniTotali; ++i) {
        dataScadenza.tm_mday++;
        mktime(&dataScadenza); // Aggiorna dataScadenza correttamente

        // Se è un giorno lavorativo (non sabato o domenica), incrementa giorniLavorativi
        if (dataScadenza.tm_wday != 0 && dataScadenza.tm_wday != 6) {
            giorniLavorativi++;
        }
    }
    return giorniLavorativi;
}

int main() {
    double volatilitaImplicita; // Volatilità in percentuale
    double prezzoCorrente;      // Prezzo corrente del titolo
    int giorniTotali;           // Giorni totali a scadenza (includendo weekend)

    // Input dati
    std::cout << "Inserisci la volatilità implicita (%) : ";
    std::cin >> volatilitaImplicita;
    std::cout << "Inserisci il prezzo corrente del titolo: ";
    std::cin >> prezzoCorrente;
    std::cout << "Inserisci i giorni totali a scadenza (includendo weekend): ";
    std::cin >> giorniTotali;

    // Calcola i giorni lavorativi
    int giorniLavorativi = calcolaGiorniLavorativi(giorniTotali);

    // Conversione volatilità in decimale
    double volatilitaDecimale = volatilitaImplicita / 100.0;

    // Calcolo della volatilità annuale corretta per la scadenza
    double volatilitaCorretta = volatilitaDecimale * std::sqrt(static_cast<double>(giorniLavorativi) / GIORNI_LAVORATIVI_ANNO);

    // Calcolo dell'oscillazione attesa per una deviazione standard
    double oscillazioneAttesa = prezzoCorrente * volatilitaCorretta;

    // Output risultato
    std::cout << "Giorni lavorativi alla scadenza: " << giorniLavorativi << std::endl;
    std::cout << "Oscillazione attesa per 1 deviazione standard: " << oscillazioneAttesa << " (in valore assoluto)" << std::endl;
    std::cout << "Range atteso del prezzo: [" 
              << prezzoCorrente - oscillazioneAttesa << " , " 
              << prezzoCorrente + oscillazioneAttesa << "]" << std::endl;

    return 0;
}
