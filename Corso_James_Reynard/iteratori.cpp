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



    return 0;
}