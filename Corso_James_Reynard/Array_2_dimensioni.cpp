#include <iostream>
#include <string>

using namespace std;


int main(){

    string  names [2][5] ={"Gino", "Brian", "Mick", "Keith", "Charlie", "Ron", "Matilde", "Anita", "Vera", "Annalura"};

    for (int row=0; row <2; row++){
        for(int col=0; col<5; col++){
            std::cout << names[row][col] <<  endl;
        }
        std::cout << "      "  << endl;
    }

    string names2[10] = {"uno", "due", "tre", "quattro", "cinque", "sei", "sette", "otto", "nove", "dieci"};
    {
        int col = 0;
        for (int row = 0; row < 2; row++)
        {
            for (int col = 0; col < 4; col++)
            {

                std::cout << names2[row * 4 + col] << endl;
            }
            std::cout << "      " << endl;
        }
        std::cout << "      " << endl;
    }
    






    return 0;
}