#include <cstddef>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    int x = 0;

    cin  >> x;
    bool succes = false;
  
    while (!succes)
    {
        if (cin.good())
        {

            cout << "hai immesso il corretto numero \n";
            succes=true;
        }
        else 
        {
            cout << "hai immesso un mumero sbagliato prova ancora \n";
            cin.clear();
            cin.ignore(20, '\n');
            cin >> x;
        }
    }

    return 0;
}