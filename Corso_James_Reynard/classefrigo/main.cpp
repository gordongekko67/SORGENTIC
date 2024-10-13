#include <iostream>
#include <string>
#include <vector>
#include "refrigerator.h"
#include "frigosuper.h"


int main(){

    refrigerator Frigo1;
    refrigerator Frigo2(4,true, true, "Ariston");
    refrigerator Frigo3("Zanussi");

    Frigo1.stampa_frigo();
    Frigo2.stampa_frigo();
    Frigo3.stampa_frigo();


    frigosuper Frigo4(4,true,true, "Candy", 90);
    Frigo4.stampafrigosuper();

    frigosuper Frigo5( 89);
    Frigo5.stampafrigosuper();


    
















    return 0;
}
