#include <iostream>
#include <string>
#include <fstream>


using namespace std;


int main(){

    ofstream ofile;
    ofile.open("important.txt", fstream::app);

    if (!ofile){

        cout << " could not open the file"<< "\n";
        return -1;


    }

    ofile << "\n some more data";
    ofile.close();



    return 0;
}