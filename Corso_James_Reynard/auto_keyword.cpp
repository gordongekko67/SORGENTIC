#include <iostream>
#include <string>

using namespace std;


int main(){

    string a = "abc";

    int b ={1};

    int  arr[] ={1,2,3};

    int i={42};

    for (auto& it : a) {
    cout << it << endl;
    }




    return 0; 
}