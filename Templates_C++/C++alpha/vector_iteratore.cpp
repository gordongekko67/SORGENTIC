#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


struct MyStructure2{
    int valore;
    std::string descrizione;
    bool veroFalso;
    float numeroDimensione;

};

std::vector<MyStructure2> v4;




int main()
{

        
    vector<int> c1;
    vector<int>::iterator c1_Iter;
    vector<int>::const_iterator c1_cIter;

    c1.push_back(1);
    c1.push_back(2);

    cout << "The vector c1 contains elements:";
    c1_Iter = c1.begin();
    for (; c1_Iter != c1.end(); c1_Iter++)
    {
        cout << " " << *c1_Iter;
    }
    cout << endl;

    cout << "The vector c1 now contains elements:";
    c1_Iter = c1.begin();
    *c1_Iter = 20;
    for (; c1_Iter != c1.end(); c1_Iter++)
    {
        cout << " " << *c1_Iter;
    }
    cout << endl;

    
    cout << endl;


    std::vector<int> v(5); // Create a vector of size 5 
    v[0] = 10; // Assign value 10 to the first element 
    v[2] = 20; // Assign value 20 to the third element

    std::vector<int> v2(5); 
    v2.assign(5,100); // Assign the given values to the vector 



    // altro iteratore molto bello 


    MyStructure2 a3;
    for (int i = 0; i < 10; i++)

    {
        a3.valore=i;
        a3.descrizione="Le lasagne della nonna";
        v4.push_back(a3);
    }
    
    for (auto it = begin (v4); it != end (v4); ++it) {

        cout << it->valore << endl;
        cout << it->descrizione << endl;
        
}




    return 0;
}