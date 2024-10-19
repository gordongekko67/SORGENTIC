#include <iostream>
#include <string>



int main(){


int arr[5]={1,2,3,4,5};

int *p=arr;

for(int i=0; i<4; i++){


    std::cout <<  *p << std::endl;
    p++;

}








}