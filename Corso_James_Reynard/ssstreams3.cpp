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

        // std::cout << line << "\n";

        // different member versions of find in the same order as above:
        std::size_t found1 = line.find(" ");
        if (found1 != std::string::npos)
        {

            // std::cout << "first 'needle' found at: " << found1 << '\n';
            std::string campo1 = line.substr(0, (found1)); // "think"
            std::cout << std::setw(8) << campo1 << "  ";
        }
        else
        {

            return -1;
        }

        for (int i = 0; i < line.size(); i++)
        {

            // std::cout << line[i] << ' ';
            if (isdigit(line[i]))
            {

                std::string campo2 = line.substr(found1 + 1, i - found1 - 1); // "think"
                std::string campo3 = line.substr(i, 4);
                std::cout << std::setw(20) <<  campo2 ;
                std::cout << std::setw(4)  <<  campo3 << "\n";
                break;
            }
        }
    }

    return 0;
}
