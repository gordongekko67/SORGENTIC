#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::ifstream ifile("text.txt");
    if (ifile)
    {
        std::string text = "";
        while (getline(ifile, text))
        {
            std::cout << text << " ";
        }
        std::cout << std::endl;
    }
    ifile.close();

    std::ofstream ofile("text_out.txt");

    if (ofile)
    {
        std::string s = "la volpe bianca sopra la panca";

        for (int i = 0; i < s.size(); i++)
        {

            ofile << s << std::endl;
        }
    }

    ofile.close();

    return 0;
}