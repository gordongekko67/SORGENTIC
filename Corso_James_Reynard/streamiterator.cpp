#include <iostream>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;


int main(){

    ostream_iterator<int> oi(cout, "\n");

    for (int i=0; i<10; i++){

        *oi=i;
        oi++;

    }




    cout << "Pleasse eter a number" << endl;

    istream_iterator<int> ii(cin);

    int x= *ii;
    cout << "You entered" << x << endl;



    istream_iterator<string> iis(cin);
12    istream_iterator<string> eof;

    vector<string> vs;

    while (iis!=eof){

        vs.push_back(*iis);
        ++iis;


    }

    for (auto v:vs){

        std::cout << v << endl;

    }






    return 0;
}