#include <iostream>
#include <cmath>
#include <vector>
#include <matplotlibcpp.h> // Assicurati di avere la libreria correttamente configurata

namespace plt = matplotlibcpp;

using namespace std;

// Funzione per calcolare i giorni lavorativi
int giorniLavorativi(int gg) {
    // ... [La tua funzione rimane invariata]
}

double gaussian(double x, double mu, double sigma) {
    return (1.0 / (sigma * sqrt(2 * M_PI))) * exp(-0.5 * pow((x - mu) / sigma, 2));
}

int main() {
    // ... [Il resto del tuo codice rimane invariato]

    // Calcolo della deviazione standard
    double sigma = valoreOscillazione;

    // Creazione dei dati per la curva gaussiana
    vector<double> x, y;
    double mu = prezzoAttuale;

    for (double i = mu - 4 * sigma; i <= mu + 4 * sigma; i += 0.1) {
        x.push_back(i);
        y.push_back(gaussian(i, mu, sigma));
    }

    // Creazione del grafico
    plt::figure();
    plt::plot(x, y);
    plt::title("Curva Gaussiana");
    plt::xlabel("Prezzo");
    plt::ylabel("Densità di probabilità");
    
    // Aggiunta delle linee per 1 deviazione standard
    plt::axvline(mu - sigma, 0, "r--"); // Linea a sinistra
    plt::axvline(mu + sigma, 0, "r--"); // Linea a destra
    plt::text(mu - sigma, 0.02, "1 SD", {{"color", "red"}});
    plt::text(mu + sigma, 0.02, "1 SD", {{"color", "red"}});

    plt::show(); // Mostra il grafico

    return 0;
}
