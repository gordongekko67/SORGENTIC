#include "Individuo.h"
#include <iostream>
#include <string>

using namespace std;

int main(){

    Individuo i1("Mario", "Rossi");
    i1.stampaIndividuo();


    string i3 ="Gino";

    i1.setName(i3);
    i1.stampaIndividuo();





}




Individuo::Individuo()
{

}

Individuo::~Individuo()
{

}