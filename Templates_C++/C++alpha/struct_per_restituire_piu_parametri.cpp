#include <iostream>
#include <string>

using namespace std;


struct passa_valori{

        int valore;
        std::string stringa;
        bool veroFalso ;
        double valoredoub ;

};


struct  ritorno_valore( struct passa_valori *p1){

    std::cout << "questoo  e il valore passato " << p1->valore;
    p1->valore=3;

    return p1;

    
};


int main(){


    
    passa_valori p1;
    p1.valore =2;
    p1.stringa="aaaa";
    p1.veroFalso=false;
    p1.valoredoub=7.123;




    ritorno_valore(&p1);





    return 0;
}