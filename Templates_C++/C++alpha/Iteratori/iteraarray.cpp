#include <iostream>
using namespace std;

int main(){
   int arr[5]={1,2,3,2,1};
   //define an integer array of size 5

   for(auto it:arr)
      cout<<it<<" ";
   //print the elements of array

   return 0;
}