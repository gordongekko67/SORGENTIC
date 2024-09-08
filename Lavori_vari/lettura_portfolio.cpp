//-------------------------------------------------------------------------------------------------
//
//     LETTURA PORTFOLIO.CSV  E ESECUZIONE  VARIE  ANALISI 
//
//-------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // Per std::find

using namespace std;


std::vector<std::string> etichette;
std::vector<double> valori;  // Assume che i valori siano numerici


int main() {
    std::string filePath = "../../Sorgenti_Python/UtilitiesIB/mysite/portfolio.csv";

    std::ifstream file(filePath);

    // Controlla se il file è stato aperto correttamente
    if (!file) {
        std::cerr << "Errore nell'apertura del file: " << filePath << std::endl;
        return 1;
    }

    std::string header;
    // Leggi l'intestazione del file CSV
    std::getline(file, header);

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        std::vector<std::string> fields;

        // Estrai i campi separati da virgola
        while (std::getline(ss, value, ',')) {
            fields.push_back(value);
        }

        // Assumendo che i campi siano ordinati come nell'intestazione:
        std::string strumentoFinanziario = fields[0];
        std::string operazioneTicker = fields[1];
        std::string delta = fields[2];
        std::string valoreTemporale = fields[3];
        std::string posizione = fields[4];
        std::string prMedio = fields[5];
        std::string valMkt = fields[6];
        std::string pLgiorn = fields[7];
        std::string pLnonRealizzato = fields[8];
        std::string ultimo = fields[9];
        std::string modifica = fields[10];
        std::string variazionePerc = fields[11];
        std::string gamma = fields[12];
        std::string vega = fields[13];
        std::string theta = fields[14];
        std::string deltaPortafoglio = fields[15];
        std::string gammaPortafoglio = fields[16];
        std::string vegaPortafoglio = fields[17];
        std::string thetaPortafoglio = fields[18];
        std::string giorniRestantiAllUGT = fields[19];

        // Stampa i valori (puoi sostituire questa parte con qualsiasi logica di elaborazione necessaria)
        /*
        std::cout << "Strumento finanziario: " << strumentoFinanziario << std::endl;
        std::cout << "Operazione ticker: " << operazioneTicker << std::endl;
        std::cout << "Delta: " << delta << std::endl;
        std::cout << "Valore temporale (%): " << valoreTemporale << std::endl;
        std::cout << "Posizione: " << posizione << std::endl;
        std::cout << "Pr. medio: " << prMedio << std::endl;
        std::cout << "Val mkt: " << valMkt << std::endl;
        std::cout << "P&L giorn.: " << pLgiorn << std::endl;
        std::cout << "P&L non realizzato: " << pLnonRealizzato << std::endl;
        std::cout << "Ultimo: " << ultimo << std::endl;
        std::cout << "Modifica: " << modifica << std::endl;
        std::cout << "Variazione %: " << variazionePerc << std::endl;
        std::cout << "Gamma: " << gamma << std::endl;
        std::cout << "Vega: " << vega << std::endl;
        std::cout << "Theta: " << theta << std::endl;
        std::cout << "Delta portafoglio: " << deltaPortafoglio << std::endl;
        std::cout << "Gamma portafoglio: " << gammaPortafoglio << std::endl;
        std::cout << "Vega portafoglio: " << vegaPortafoglio << std::endl;
        std::cout << "Theta portafoglio: " << thetaPortafoglio << std::endl;
        std::cout << "Giorni restanti all'UGT: " << giorniRestantiAllUGT << std::endl;
        */
       
        

// Utilizza std::istringstream per suddividere la stringa
    std::istringstream iss(strumentoFinanziario);
    std::string part1, part2;

    // Estrai i primi due campi
    iss >> part1 >> part2;

    // Combina i due campi
    std::string simbolo_scadenza = part1 + " " + part2;

    // calcolo i valori della riga 
    float valore_Delta = stof(delta);
    int int_Posizione = stoi(posizione);
    float valore_Delta_riga = int_Posizione*100*valore_Delta;

    // Stampa il risultato
    
    //cout << "simbolo_scadenza " << simbolo_scadenza << endl;
    //cout <<  "delta "   <<  valore_Delta_riga  <<  endl;


     // Cerca se l'etichetta esiste già nel vettore etichette
        auto it = std::find(etichette.begin(), etichette.end(), simbolo_scadenza);

        if (it != etichette.end()) {
            // Se l'etichetta esiste già, somma il valore corrispondente
            int index = std::distance(etichette.begin(), it);
            valori[index] += valore_Delta_riga;
        } else {
            // Se l'etichetta non esiste, aggiungi l'etichetta e il valore
            etichette.push_back(simbolo_scadenza);
            valori.push_back(valore_Delta_riga);
        }
    

    // Separatore per le righe (opzionale)
    //std::cout << "-------------------------" << std::endl;


    // alla fine della elaborazione della riga stampa 
    if (valore_Delta > 0.45 and int_Posizione <0){

        std::cout << " attenzione il titolo si avvicina a ITM se non lo è già  " << simbolo_scadenza <<  " "<< int_Posizione << valore_Delta<< endl;
    }


    }

    // Alla fine stampa etichette e valori 
    // Visualizza il contenuto dei vettori
    std::cout << "Etichette e valori combinati:" << std::endl;
    for (size_t i = 0; i < etichette.size(); ++i) {
        std::cout << etichette[i] << ": " << valori[i] << std::endl;
    }


    // Creare un vettore di coppie (etichetta, valore assoluto)
    std::vector<std::pair<std::string, double > > etichettaValore;
      

    for (size_t i = 0; i < etichette.size(); ++i) {
        etichettaValore.push_back(std::make_pair(etichette[i], std::abs(valori[i])));
    }

    // Stampare le etichette e i valori ordinati
    std::cout << "Elementi con relativo delta " << std::endl;
    for (const auto& ev : etichettaValore) {
        
        //std::cout << ev.first << ": " << ev.second << std::endl;

        if(ev.second > 20){

            cout << "Attenzione ! la posizione di  "  << ev.first << " è squilibrata " <<  endl;

        }
    }


    // Chiudi il file
    file.close();

    return 0;
}