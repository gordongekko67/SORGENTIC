#include <iostream>
#include <string>
#include <vector>


using namespace std;

int func(int x){

    int a = 20;
    return a;
}



// variabile globale 
int a=30;


int main(){

// variabile interno del main 
int a= 10;

int a1=func(5);
std::cout << a1 <<  endl;
std::cout << a <<  endl;
std::cout << ::a << endl;

    return 0;
}