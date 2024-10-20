#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){


    std::string str="Hello";
    string::const_iterator it;
    

    for (it= str.cbegin(); it< str.cend(); it++){

        std::cout << *it<< endl;

    }


    string::const_iterator cit;
    

    for (cit= str.cbegin(); cit< str.cend(); cit++){

        std::cout << *cit<< endl;

    }

    string::reverse_iterator rit;
    
    for (rit= str.rbegin(); rit< str.rend(); rit++){

        std::cout << *rit<< endl;


    }

    string::const_reverse_iterator crit;
    
    for (crit= str.crbegin(); crit< str.crend(); crit++){

        std::cout << *crit<< endl;


    }


    for (auto it=str.begin(); it < str.end(); it++){

        std::cout << *it<< endl;


    }






    std::cout << "-----"<< endl;

    for (auto it=str.rbegin(); it != str.rend();++it){

        std::cout << *it<< "reverse iterator" << endl;


    }



    std ::string str1="Prova stringa";
    int arr[6]={1,2,3,4,5,6};
    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    for (auto it= str1.begin();it < str1.end(); it++){

        std::cout << *it << endl;
        
    }

    for (auto it:arr){

        std::cout << arr[it] << endl;
        
    }

    for (auto it: v){

        std::cout << v[it] << endl;
        
    }


    std::cout << "------------------------------------"<<  endl;

    std::string st= "stringa ulteriore";

    std::string::iterator s;
    for (auto it = st.begin(); it < st.end(); it++){
        std:: cout << *it << endl;
    }

    std::cout << "------------------------------------"<<  endl;
    std::string::const_iterator cs;
    for (cs =st.cbegin(); cs != st.cend(); cs++){
        std:: cout << *cs << endl;
    }
    std::cout << "------------------------------------"<<  endl;
    std::string::iterator rs;
    for (auto rs = st.rbegin(); rs < st.rend(); rs++){
        std:: cout << *rs << endl;
    }


   
    int arri[3]={1,2,3};
    
   for (auto i= std::begin(arri) ; i != std::end(arri); i++){

    std::cout << *i << endl;

   }
 

    

    std::string arr2[3] = {"AAA", "BBB", "CCC"};

    // Uso di std::begin() e std::end()
    for (auto cit2 = std::begin(arr2); cit2 != std::end(arr2); ++cit2) {
        std::cout << *cit2 << std::endl;
    }


    vector <string> vstr;
    vstr.push_back("AAAA");
    vstr.push_back("BBBBB");

    for (auto it = vstr.begin(); it!=vstr.end(); it++){

        std::cout << *it<<  endl;
    }

    for (auto i= begin(vstr) = vstr.begin(); i!=vstr.end(); i++){

        std::cout << *i<<  endl;
    }

    for (auto it = vstr.begin(); it!=vstr.end(); it++){

        std::cout << *it<<  endl;
    }



    std::string::const_iterator coit;

    for (coit= st.begin(); coit != st.end(); coit++){

        std::cout << " questo e' un iteratore" << *coit <<  endl;

    }

    std::string::reverse_iterator rcoit;

    for (rcoit= st.rbegin(); rcoit != st.rend(); rcoit++){

        std::cout << " questo e' un iteratore inverso " << *rcoit <<  endl;

    }

    int ar[10] ={1,2,34,4,5,5, 6, 7, 7 , 8};

    for (auto it = begin(ar); it !=end(arr); it++)    {

            std::cout << *it <<  endl;
    }

    for (auto i : arr){

        std::cout << " questa e' la forma concisa "<< arr[i] << endl;
    }
    
    vector <int>v1;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    for (auto& i : v1){

        std::cout << " questa e' la forma concisa con modifica sul vettore "<<  "  " << i << endl;
        i +=2;
    }
    for (auto& i : v1){

        std::cout << " questa e' la forma concisa dopo la modifica  sul vettore "<<  "  " << i << endl;
        
    }





    
    for (auto it = begin(v1); it !=end(v1); it++)    {

            std::cout << *it <<  endl;
            auto a = (end(v1)-begin(v1));
            std::cout << "num elementi " << a << endl;

    }

    
    std::string stringa="prova di stampa";
    for (auto it = begin(stringa); it !=end(stringa); it++) 
       {

            auto secondo = next(begin(stringa));
            std::cout  << " questo e secondo " <<   *secondo <<  endl;

            auto ultimo  = prev(end(stringa));
            std::cout  << " questo e ultimo " <<   *ultimo  <<  endl;

            auto mid = begin(stringa);
            auto medio = distance( mid, (begin(stringa), end(stringa)));
            std::cout  << " questo e medio " <<   medio  <<  endl;


       }


    std::string stringa1="abcdefghilmnopqrstuvz";
    for (auto it = begin(stringa1); it !=end(stringa1); it++)
       {

            auto secondo = next(begin(stringa1));
            std::cout  << " questo e secondo " <<   *secondo <<  endl;

            auto ultimo  = prev(end(stringa1));
            std::cout  << " questo e ultimo " <<   *ultimo  <<  endl;

            auto mid = begin(stringa1);
            auto medio = (distance(begin(stringa1), end(stringa1)));
            
            std::cout  << " questo e tutto " <<   medio  <<  endl;
            auto medio1= medio/2;
            std::cout  << " questo e medio " <<  char(it[medio])  <<  endl;
                          
       }



    std::string str2="Hello";
    bool trovato=false;
    
    for(std::string::iterator it = str2.begin(); it != str2.end(); ++it) {

        if (*it == 'l'){
            std::cout << "trovato a posizione "  <<  *it << it -str2.begin() << ::endl;
            trovato=true;

        }
    
    }
    
    if (trovato==false){

        std::cout << "Non trovato";
    }
  
    





    

    return 0;
}