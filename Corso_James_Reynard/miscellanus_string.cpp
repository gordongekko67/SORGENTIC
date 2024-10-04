#include <iostream>
#include <string>


void printarr(int *arr, size_t size){
     for (int i=0; i < size; i++){
        std::cout << arr[i] << std::endl;
    }
}


int main(){

    std:: vector <int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    printarr(numbers.data(), numbers.size()); 


    int sk[10]={1,2,3,4,5,6,7,8,88};
    int n = sizeof(sk)/sizeof(sk[0]);
    std::cout << n << "\n";
    printarr(sk, n);



    std:: string s1 = "Hello";
    std::string  s2 ="World";
    swap(s1,s2);
    std::cout << s1 << "\n";
    std::cout << s2 << "\n";

    return 0;
}