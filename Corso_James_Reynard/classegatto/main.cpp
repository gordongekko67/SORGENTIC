#include <iostream>

#include "gattorazza.h"


int main (){


    Gatto gatto1;
    gatto1.stampaGatto();
    
    Gatto gatto2(4,"Grigio", "Ernesto");
    gatto2.stampaGatto();




    return 0;
}