#include <iostream>
#include <string>

template <class T>

T Max(const T &t1, const T &t2)
{

    if (t1 > t2)
        return t1;

    return t2;
}
template <class T>
std::string Scorri(const T &arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << std::endl;

        if (arr[i] == 5) {
            return "trovato"; // Found
        }
    }
    return "not found"; // If not found
}


using namespace std;

int main()
{

    cout << Max(7.0, 7.8) << endl;
    cout << Max(1, 2) << endl;

    int arr[5]={1,2,3,4,5};
    std::string result = Scorri(arr, sizeof(arr)/sizeof(arr[0]));

    std::cout << result << std::endl; // Output the result from Scorri

    

    return 0;
}
