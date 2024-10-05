#include <iostream>
#include <cmath> // Per sqrt()

using namespace std;

// Funzione per calcolare i giorni lavorativi
int giorniLavorativi(int gg) {
    // Numero di settimane complete
    int settimaneComplete = gg / 7;
    // Numero di giorni restanti (che non formano una settimana completa)
    int giorniRestanti = gg % 7;

    // Numero di giorni di weekend nelle settimane complete
    int giorniWeekend = settimaneComplete * 2;

    // Se i giorni restanti includono il sabato o la domenica, aggiungili come weekend
    if (giorniRestanti >= 6) {
        giorniWeekend += 1;  // Se restano 6 giorni, aggiungiamo il sabato
    }

    // Stampa per vedere i giorni del weekend
    std::cout << "Giorni weekend: " << giorniWeekend << endl;

    // Restituisce il numero di giorni lavorativi (totale giorni - giorni del weekend)
    return gg - giorniWeekend;
}

int main() {
    // Messaggio iniziale
    std::cout << "Calcolo della deviazione standard di un titolo" << endl;

    // Variabili per il prezzo attuale, la volatilità implicita e i giorni alla scadenza
    double prezzoAttuale;
    double volatilitaImplicita;
    int giorniScadenza;

    // Input dell'utente per il prezzo attuale
    std::cout << "Immetti il prezzo attuale: " << endl;
    std::cin >> prezzoAttuale;

    // Input dell'utente per la volatilità implicita (in percentuale)
    std::cout << "Immetti la volatilità implicita in percentuale: " << endl;
    std::cin >> volatilitaImplicita;

    // Input dell'utente per i giorni alla scadenza
    std::cout << "Immetti i giorni alla scadenza (DTE): " << endl;
    std::cin >> giorniScadenza;

    // Stampa i giorni alla scadenza inseriti
    std::cout << "Giorni scadenza: " << giorniScadenza << endl;

    // Calcolo dei giorni lavorativi approssimativi
    int giorniLavorativiResult = giorniLavorativi(giorniScadenza);
    std::cout << "Giorni lavorativi: " << giorniLavorativiResult << endl;

    // Calcolo del terzo fattore (giorni lavorativi / 252)
    double terzoFattore = static_cast<double>(giorniLavorativiResult) / 252;
    std::cout << "Terzo fattore: " << terzoFattore << endl;

    // Calcolo del secondo fattore (radice quadrata del terzo fattore)
    double secondoFattore = sqrt(terzoFattore);
    std::cout << "Secondo fattore: " << secondoFattore << endl;

    // Calcolo del valore di oscillazione
    double valoreOscillazione = prezzoAttuale * volatilitaImplicita / 100 * secondoFattore;
    std::cout << "Il valore di oscillazione è: " << valoreOscillazione << endl;

    // Stima del range di oscillazione (valore inferiore e superiore)
    std::cout << "Quindi il valore inferiore è: " << prezzoAttuale - valoreOscillazione << endl;
    std::cout << "Quindi il valore superiore è: " << prezzoAttuale + valoreOscillazione << endl;

    return 0;
}
