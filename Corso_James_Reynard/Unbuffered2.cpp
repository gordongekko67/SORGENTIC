#include <iostream>
#include <string>
#include <fstream>

int main()
{

    const int filesize = {10};
    char filebuf[filesize];
    std::string filename("input.txt");

    std::ifstream ifile(filename);

    if (!ifile)
    {

        std::cout << " Could not open" << filename << std::endl;
        return -1;
    }

    ifile.read(filebuf, filesize);
    ifile.close();

    std::cout << "File data";
    std::cout.write(filebuf, filesize);
    std::cout << "\n";

    auto nread = ifile.gcount();
    std::cout << nread <<  "\n";

    return 0;
}