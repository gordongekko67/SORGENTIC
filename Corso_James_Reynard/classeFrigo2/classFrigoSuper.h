#include <iostream>
#include <string>
#include "classeFrigo2.h"



class FrigoSuper : public classeFrigo2{

private:

    int temperatura_freezer;


public:

    FrigoSuper(){
        classeFrigo2(), temperatura_freezer= 0;
    }

    FrigoSuper(int t, bool p, bool l, std::string m, int t2) : classeFrigo2(t,p,l, m) , temperatura_freezer(t2){

       classeFrigo2(t,p,l,m);
       temperatura_freezer=t2;
    }


    
    // Costruttore di copia
    FrigoSuper(const FrigoSuper& other) 
        : classeFrigo2(other), temperatura_freezer(other.temperatura_freezer) {}




    ~FrigoSuper(){
        std::cout << "fine distruttore" <<  std::endl;

    };


    void stampaFrigosuper(){

        stampaFrigo();
        std::cout <<  " la temperatura del freezer è di gradi  " <<  temperatura_freezer << std::endl;

    }



};