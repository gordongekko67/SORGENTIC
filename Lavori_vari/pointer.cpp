#include <iostream>
#include <string>
#include <vector>


using namespace std;


int main(){


   int a=20;
   //declare variable a
   int *p= &a;
   //assign pointer to a
   cout<<"Address of variable a: "<<p<<endl;
   cout<<"Value of variable a: "<<*p<<endl;

   p= p+1;
   cout<<"Address of variable a: "<<p<<endl;
   cout<<"valore variabile p+1 "<<*p<<endl;

   p= p-1;
   cout<<"Address of variable a: "<<p<<endl;
   cout<<"valore variabile p+1 "<<*p<<endl;



   int b = 1;
   int *ptrb = &b;

   cout << ptrb<<  " indirizzop valore del puntatore " <<  endl;
   cout << *ptrb<<  " valore del puntatore " <<  endl;



   return 0;
}





