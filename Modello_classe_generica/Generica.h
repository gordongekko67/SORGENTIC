#include <string>
#include <iostream>


class Generica
{
private:
    int numero;
    std::string descrizione;



public:
    Generica();
    Generica(int& num1, std::string descrizione);
    ~Generica();

    int getter (){ 

        std::cout << "il valore di " << numero <<   std::endl;
        return numero;
    }

    void setter (int& num1){ 

        std::cout << "il valore di " << numero <<   std::endl;
        numero = num1;
    }

    void stampa (){ 

        std::cout << "il valore di " << numero <<   std::endl;
        
    }


};


