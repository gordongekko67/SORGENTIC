#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void scambia (int a, int b){

    int tmp = a;
    a = b;
    b= tmp;



}

void scambia1 (int& a, int& b){

    int tmp = a;
    a = b;
    b= tmp;



}

void scambia2 (int* a, int* b){

    int tmp = *a;
    *a = *b;
    *b= tmp;



}


int main(){

    int a=1; 
    int b=2;

    scambia (a,b);

    cout <<  " il valore di a " << a <<  endl;
    cout <<  " il valore di b " << b <<  endl;
    

    scambia1 (a,b);

    cout <<  " il valore di a " << a <<  endl;
    cout <<  " il valore di b " << b <<  endl;
    
    scambia2 (&a,&b);

    cout <<  " il valore di a " << a <<  endl;
    cout <<  " il valore di b " << b <<  endl;


    return 0;
}