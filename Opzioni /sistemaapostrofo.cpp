#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Funzione per sostituire gli apostrofi davanti ai segni meno
std::string removeApostropheBeforeDash(const std::string& line) {
    std::string modifiedLine = line;
    // Cerca "'-" e lo sostituisce con "-"
    size_t pos = 0;
    while ((pos = modifiedLine.find("'-", pos)) != std::string::npos) {
        modifiedLine.replace(pos, 2, "-");
        pos++;  // Continua la ricerca dopo la sostituzione
    }
    return modifiedLine;
}

int main() {
    std::ifstream inputFile("/Users/enricosaccheggiani/Henry/Sorgenti_Python/UtilitiesIB/mysite/portfolio.csv");
    std::ofstream outputFile("/Users/enricosaccheggiani/Henry/Sorgenti_Python/UtilitiesIB/mysite/portfoliook.csv");
    
    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Errore nell'apertura del file!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        // Rimuove l'apostrofo prima del trattino e scrive la riga modificata nel nuovo file
        std::string modifiedLine = removeApostropheBeforeDash(line);
        outputFile << modifiedLine << "\n";
    }

    inputFile.close();
    outputFile.close();

    std::cout << "File modificato e salvato con successo come portfolioOk.csv!" << std::endl;
    return 0;
}
