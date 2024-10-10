#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <iomanip>

struct Language
{
    std::string lang;
    std::string designer;
    int date;
};

int main()
{
    std::ifstream infile("languages2.txt");

    if (!infile)
    {
        std::cout << "File not found\n";
        return -1;
    }

    std::string line;
    std::vector<Language> languages;

    while (getline(infile, line))
    {
        std::size_t found1 = line.find(" ");
        if (found1 != std::string::npos)
        {
            std::string campo1 = line.substr(0, (found1)); // Language name
            std::cout << std::setw(15) << std::left << campo1 << ",";
        }
        else
        {
            return -1;
        }

        for (int i = 0; i < line.size(); i++)
        {
            if (isdigit(line[i]))
            {
                std::string campo2 = line.substr(found1 + 1, i - found1 - 1); // Designer
                std::string campo3 = line.substr(i, 4); // Year
                std::cout << std::setw(20) << std::left << campo2 << ",";
                std::cout << std::setw(4)  << campo3 << "\n";
                break;
            }
        }
    }

    return 0;
}
