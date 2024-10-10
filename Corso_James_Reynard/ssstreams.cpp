#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct language
{

    std::string lang;
    std::string designer;
    int date;
};

template <typename T>

std::string To_String(const T &t)
{

    std::ostringstream os;
    os << t;
    return os.str();
}

int main()
{
    std::string hello("Hello");
    std::string pi(To_String(3.1456789));
    hello += pi;
    std::cout << hello << "\n";

    std::ifstream infile("input1.txt");

    if (!infile)
    {

        std::cout << "File not found" << "\n";
        return -1;
    }

    std::string line;
    std::vector<int> numbers;

    while (getline(infile, line))
    {

        std::istringstream is(line);
        int num;

        while (is >> num)
        {

            numbers.push_back(num);
        }

        std::cout << "Lettura valori " << "\n";
        double sum = (0.0);
        int numero = 0;

        for (auto a : numbers)
        {
            sum += a;
            numero++;
            std::cout << a << "\n";
        }

        std::cout << "la media è" << static_cast<double>(sum / numero) << "\n";
    }

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