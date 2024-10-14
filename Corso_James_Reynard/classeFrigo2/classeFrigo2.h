#include <iostream>
#include <string>

class classeFrigo2{

private:

    int temperatura_frigo;
    bool porta_aperta;
    bool luce_accesa;
    std::string marca;

public:
    // costruttore di default 
    classeFrigo2(){

        temperatura_frigo =4;
        porta_aperta=false;
        luce_accesa= true;
        marca="Marca Trony economico";
    }

    // costruttore standard 
    classeFrigo2( int vtemperatura_frigo, bool vporta_aperta, bool vluce_accesa, std::string vmarca){

        temperatura_frigo =vtemperatura_frigo;
        porta_aperta=vporta_aperta;
        luce_accesa= vluce_accesa;
        marca=vmarca;
    }
    
    // metodo di lavoro
    void stampaFrigo(){

        std::cout << "----------------------" << std::endl;
        std::cout << marca << std::endl;
        

    }
    // metodo getter
    std::string getmarca(){

        return marca;

    }
    // metodo setter
    void  setmarca( std::string & vmarca){

        marca=vmarca;

    }




};





