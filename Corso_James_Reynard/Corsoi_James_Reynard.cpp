#include <iostream>
#include <string>
#include <vector>

using namespace std;

using vec_new =vector <int>;





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

void print_vector(const vector<int> &vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << " stampa del vettore  " <<endl;
    }
    
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

    //  tutto si inizializza con {}
    int in = {5};
    int arr[5] = {1, 2, 3, 4, 5};

    vector<int> vect;
    vect.push_back(10);
    vect.push_back(20);

    // iterazione basata su indici per un container std::vector non funziona 

    /*
    
    
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << ' ';
    }

    */

    print_vector(vect);


    vector<int> vect1;
    vect1.push_back(30);
    vect1.push_back(40);

    print_vector(vect1);



    //  tramite la direttiva using si puo' riscrivere un vettore dii vettori in maniera piu pulita 

    vector <vector <int> > vec_of_vec;

    vector <vec_new> vec_1;

    // allocazione di memoria sullo Heap


    int c =1;

    int *p1 = new int[42];
    

    std::cout  << *p1 << std::endl;
    delete []p1;


    int *p2 = new int[20];


    for (int i =0; i <20; i++){

        std::cout << p2[i] << std::endl;
    }

    delete []p2;




    int ii  = 5;
    int *ptrii = &ii;

    int *ptri4 = new int;
    *ptri4=(10);
    

    std::cout <<  *ptri4 << std:: endl;

    delete ptri4;


    int *pa = new int[10];

    for (int i = 0; i < 10; i++)
        {
         pa[i]=i;
         std::cout << pa[i] << "  "  << endl;
    }
    
    delete [] pa;



    int var[5]={1,2,3,4,5};

    for (int i = 0; i < 5; i++)
    {
        var[i]=9;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout <<  var[i]<< endl;
    }


    return 0;
}