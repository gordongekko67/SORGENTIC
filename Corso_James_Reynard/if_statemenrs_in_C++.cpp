#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    std::cout << "Hello world" << endl;

    int arr[10] = {
        1,
        2,
        3,
        4,
        5,
    };

    for (auto iter = begin(arr); iter != end(arr); iter++)
    {

        std::cout << *iter << "\n";
    }

    vector<string> v;
    v.push_back("AAAAAA");
    v.push_back("BBBBBB");

    for (auto iter = begin(v); iter != end(v); iter++)
    {

        std::cout << *iter << "\n";
    }

    for (int i = 0; i < 10; i++)
    {

        switch (const int day = i)
        {

        case 1:
            cout << "se va bene siamo rovimati 1\n";
            break;
        case 2:
            cout << "se va bene siamo rovimati 2 \n";
            break;
            

        case 3:
            cout << "se va bene siamo rovimati 3 \n";
            break;
            



        default:

            cout << "ce l'abbiamo nel c \n";
            break;
        }
    }

    return 0;
}