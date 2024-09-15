#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
   int arr[5]={1,2,3,2,1};
   //define an integer array of size 5

   for(auto it:arr)
      cout<<it<<" ";
   //print the elements of array

   // iteratore su stringhe
   
   string::const_iterator cit;




   return 0;
}