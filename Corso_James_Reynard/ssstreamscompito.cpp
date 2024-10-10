#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main()
{
  
    

    std::ifstream infile2("languages.txt");

    if (!infile2)
    {

        std::cout << "File not found" << "\n";
        return -1;
    }

    std::string line2;
    std::vector<std::string> lan;

    while (getline(infile2, line2))
    {

        std::istringstream is(line2);
        int num;

        while (is >> num)
        {
            lan.push_back(line2);
        }

        //std::cout << line2 << "\n";
        std::string riga1=line2;
        

        //  qui comincia il bello
        std::istringstream iss(line2); // creiamo un istringstream a partire da 'input'

        std::string lang;
        std::string persona;
        std::string  anno;

        // Estraiamo i valori dalla stringa
        iss >> lang >> persona >> anno;

        // Stampiamo i risultati
        std::cout << lang << "," << persona << "," << anno << std::endl;
        
    }

    return 0;
}