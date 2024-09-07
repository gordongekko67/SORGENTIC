#include <iostream>
#include <string>
#include <vector>

using namespace std;

void  scambia( int a, int b)
{
    int valore_Scambio= 0;
    valore_Scambio=a;
    a=b;
    b=valore_Scambio;
    

}

void  scambia1( int &a, int &b)
{
    int valore_Scambio= 0;
    valore_Scambio=a;
    a=b;
    b=valore_Scambio;
 

}

void  scambia2( int *a, int *b)
{
    int valore_Scambio= 0;
    valore_Scambio=*a;
    *a=*b;
    *b=valore_Scambio;
 

}




int main()
{

    // partenza inizializzo i campi 
    int a = 1;
    int b= 2;

    // passo solo il valore , non suiccede nulla 
    scambia(a,b);
    cout << "valore di a è  " <<  a <<  endl;
    cout << "valore di b è  " <<  b <<  endl;

    // passo il valore , ma ricevo il riferimento 
    scambia1(a,b);
    cout << "valore di a è  " <<  a <<  endl;
    cout << "valore di b è  " <<  b <<  endl;

    a = 1;
    b= 2;
    // passo il riferimento e ricevo con operatore  di deferenza 
    scambia2(&a,&b);
    cout << "valore di a è  " <<  a <<  endl;
    cout << "valore di b è  " <<  b <<  endl;





    return 0;

}