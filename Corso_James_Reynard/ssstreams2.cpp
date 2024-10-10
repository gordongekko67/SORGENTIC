#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

struct Language {
    std::string lang;
    std::string designer;
    int date;
};

int main() {
    std::ifstream infile("languages2.txt");

    if (!infile) {
        std::cout << "File not found\n";
        return -1;
    }

    std::string line;
    std::vector<Language> languages;

    while (getline(infile, line)) {
        std::istringstream iss(line);
        Language tempLang;

        std::vector<std::string> tokens;
        std::string token;

        // Suddividiamo la linea in singole parole
        while (iss >> token) {
            tokens.push_back(token);
        }

        if (tokens.size() < 3) {
            std::cout << "Error parsing line: " << line << "\n";
            continue;
        }

        // L'ultimo token è l'anno
        tempLang.date = std::stoi(tokens.back());

        // La prima parola è il linguaggio
        tempLang.lang = tokens[0];

        // Tutto ciò che sta tra la prima parola e l'anno è il progettista
        tempLang.designer = tokens[1];
        for (size_t i = 2; i < tokens.size() - 1; ++i) {
            tempLang.designer += " " + tokens[i];
        }

        languages.push_back(tempLang);
    }

    // Stampiamo i risultati
    for (const auto& lang : languages) {
        std::cout << "Language: " << lang.lang 
                  << ", Designer: " << lang.designer 
                  << ", Year: " << lang.date << "\n";
    }

    return 0;
}
