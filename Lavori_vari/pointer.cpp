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



   return 0;
}





