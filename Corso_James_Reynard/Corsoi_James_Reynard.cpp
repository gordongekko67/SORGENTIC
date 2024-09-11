#include <iostream>
#include <string>

using namespace std;


int calcola (int x , int y){

    int somma = x +y;
    return somma;

}



int passavalue (int x , int y){

    int somma = x +y;
    std::cout << " address di x" << "  " <<  &x << endl;
    std::cout << " address di y" << "  " <<  &y << endl;
    std::cout << " address di somma" << "  " <<  &somma << endl;
    x =10;
    return somma;

}


int passareference (int& x , int& y){

    int somma = x +y;
    std::cout << " address di x" << "  " <<  &x << endl;
    std::cout << " address di y" << "  " <<  &y << endl;
    std::cout << " address di somma" << "  " <<  &somma << endl;
    x =10;
    return somma;

}

int passaaddress (int* x , int* y){

    
    int somma = *x + *y;
    std::cout << " address di x" << "  " <<  &x << endl;
    std::cout << " address di y" << "  " <<  &y << endl;
    std::cout << " address di somma" << "  " <<  &somma << endl;
    std::cout << " valore di somma " << "  " <<  &somma << endl;
    *x=10;
    return somma;

}




int main (){


    //  esercizio numero 1
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // la memoria e' allocata per le variabili normali nello stack e non nello heap 

    int i = 1;

    std::cout << " the value of i is " <<  i << std::endl;

    std::cout << " the reference of i is " <<  &i << std::endl;

    int a=2,b=4;

    calcola(a,b);

    int somma_calcolata=calcola(a,b);

    std::cout << " La somma calcolata e' " <<  somma_calcolata << std::endl;


    // scrittura programmi per passaggio parametri by value

    std::cout << "PASSA VALUE   "  <<   std::endl;

    int x = 5;
    int y = 6;
    int sommavalue = passavalue( x,y);
    std::cout << "adrress of x  "  <<  &x << std::endl;
    std::cout << "adrress of y  "  <<  &y << std::endl;
    std::cout << "valore di x dopo value  by value  "  <<  x << std::endl;

    // scrittura programmi per passaggio parametri by reference

    std::cout << "PASSA REFERENCE   "  <<   std::endl;
    
    int sommareference = passareference(x, y);
    std::cout << "address of x by reference  "  <<  &x << std::endl;
    std::cout << "address of y by reference  "  <<  &y << std::endl;
    std::cout << "valore di x dopo reference x by reference  "  <<  x << std::endl;


    // scrittura programmi per passaggio parametri by address

    std::cout << "PASSA ADDRESS   "  <<   std::endl;

    int sommaaddress = passaaddress(&x ,  &y);
    std::cout << "address of x by address  "  <<  &x << std::endl;
    std::cout << "address of y by address  "  <<  &y << std::endl;
    std::cout << "valore di x dopo address x by address  "  <<  x << std::endl;



    return 0;
}