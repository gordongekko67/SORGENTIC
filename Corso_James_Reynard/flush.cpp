#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main()
{
    std::ofstream ofile("log.txt");

    if (!ofile)
    {
        std::cout << "could not open file \n";
        return -1;
    }

    for (int i = 0; i < 1000000; i++)
    {
        std::cout << i << std::fflush <<  "\n";
        ofile << i <<  std::fflush     <<  "\n";

        if (i == 6666)
        {

            std::terminate();
        }

        /* code */
    }

    ofile.close();

    return 0;
}