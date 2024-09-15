#include <iostream>
#include <string>


using namespace std;


int main(){

    // iteratore su stringhe  costanti 
   
   std::string str="ABCD";
   string::const_iterator cit;
   string::reverse_iterator cit2;

   for(cit= str.begin(); cit != str.end(); cit++)
        cout <<*cit << "|";

// iteratore su stringhe  costanti all'indietro


    for(cit2= str.rbegin(); cit2 != str.rend(); cit2++)
        cout <<*cit2 << "|";
    
    



    return 0;
}