#include <iostream>
#include <string>
#include "classFrigoSuper.h"



int main(){

    classeFrigo2 Frigo1;
    Frigo1.stampaFrigo();


    classeFrigo2 Frigo2(3,true, true, "Zanussi");
    Frigo2.stampaFrigo();


    FrigoSuper s1(4,true, true, "Candy", 9);
    s1.stampaFrigosuper();

    FrigoSuper s2=s1;
    s2.stampaFrigosuper();


    return 0;
}