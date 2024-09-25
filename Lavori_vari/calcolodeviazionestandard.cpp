#include <iostream>
#include <string>


using namespace std;


int main (){

    std::cout  <<  "  Calcolo della deviazione standard di un titolo" <<  endl;

    
    double prezzoAttuale;
    double volatilitaImplicita;
    int giorniScadenza;

    std::cout  <<  "  Immetti il prezzo attuale " <<  endl;
    std::cin  >> prezzoAttuale ;

    std::cout  <<  "  Immetti la volatilità implicita in percentuale " <<  endl;
    std::cin  >> volatilitaImplicita ;

    std::cout  <<  "  Immetti i giorni alla scadenza  " <<  endl;
    std::cin  >> giorniScadenza ;

    std::cout << "giorni scadenza " << giorniScadenza;    

    
    double terzoFattore = static_cast<double>(giorniScadenza) / 252;

    std::cout << "terzo fattore " << terzoFattore << endl;    

    double secondoFattore = sqrt(terzoFattore);
    std::cout << "secondo fattore " << secondoFattore <<endl;

    double valoreOscillazione = prezzoAttuale*volatilitaImplicita/100*secondoFattore;
    std::cout << " il valore di oscillazione è  " <<  valoreOscillazione <<  endl;


    std:: cout <<  "quindi il valore inferiore è "  << prezzoAttuale-valoreOscillazione <<  endl;
    std:: cout <<  "quindi il valore superiore è "  << prezzoAttuale+valoreOscillazione <<  endl;

    
     





    return 0;

}