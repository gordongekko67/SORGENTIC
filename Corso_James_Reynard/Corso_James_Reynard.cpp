#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using vec_new = vector<int>;

int calcola(int x, int y) {
    int somma = x + y;
    return somma;
}

int passavalue(int x, int y) {
    int somma = x + y;
    std::cout << " address di x: " << &x << endl;
    std::cout << " address di y: " << &y << endl;
    std::cout << " address di somma: " << &somma << endl;
    x = 10;
    return somma;
}

int passareference(int &x, int &y) {
    int somma = x + y;
    std::cout << " address di x: " << &x << endl;
    std::cout << " address di y: " << &y << endl;
    std::cout << " address di somma: " << &somma << endl;
    x = 10;
    return somma;
}

int passaaddress(int *x, int *y) {
    int somma = *x + *y;
    std::cout << " address di x: " << x << endl;
    std::cout << " address di y: " << y << endl;
    std::cout << " address di somma: " << &somma << endl;
    std::cout << " valore di somma: " << somma << endl;
    *x = 10;
    return somma;
}

void print_vector(const vector<int> &vect) {
    for (int i = 0; i < vect.size(); i++) {
        std::cout << vect[i] << " stampa del vettore" << endl;
    }
}

int main() {

    //  esercizio numero 1
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // la memoria e' allocata per le variabili normali nello stack e non nello heap

    int i = 1;

    std::cout << " the value of i is " << i << std::endl;

    std::cout << " the reference of i is " << &i << std::endl;

    int a = 2, b = 4;

    calcola(a, b);

    int somma_calcolata = calcola(a, b);

    std::cout << " La somma calcolata e' " << somma_calcolata << std::endl;

    // scrittura programmi per passaggio parametri by value

    std::cout << "PASSA VALUE   " << std::endl;

    int x = 5;
    int y = 6;
    int sommavalue = passavalue(x, y);
    std::cout << "address of x: " << &x << std::endl;
    std::cout << "address of y: " << &y << std::endl;
    std::cout << "valore di x dopo passaggio by value: " << x << std::endl;

    // scrittura programmi per passaggio parametri by reference

    std::cout << "PASSA REFERENCE   " << std::endl;

    int sommareference = passareference(x, y);
    std::cout << "address of x by reference: " << &x << std::endl;
    std::cout << "address of y by reference: " << &y << std::endl;
    std::cout << "valore di x dopo passaggio by reference: " << x << std::endl;

    // scrittura programmi per passaggio parametri by address

    std::cout << "PASSA ADDRESS   " << std::endl;

    int sommaaddress = passaaddress(&x, &y);
    std::cout << "address of x by address: " << &x << std::endl;
    std::cout << "address of y by address: " << &y << std::endl;
    std::cout << "valore di x dopo passaggio by address: " << x << std::endl;

    //  tutto si inizializza con {}
    int in = {5};
    int arr[5] = {1, 2, 3, 4, 5};

    vector<int> vect;
    vect.push_back(10);
    vect.push_back(20);

    print_vector(vect);

    vector<int> vect1;
    vect1.push_back(30);
    vect1.push_back(40);

    print_vector(vect1);

    //  tramite la direttiva using si puo' riscrivere un vettore di vettori in maniera piu pulita

    vector<vector<int> >vec_of_vec;

    vector<vec_new> vec_1;

    // allocazione di memoria sullo Heap

    int *p1 = new int[42];

    std::cout << *p1 << std::endl;
    delete[] p1;

    int *p2 = new int[20];

    for (int i = 0; i < 20; i++) {
        std::cout << p2[i] << std::endl;
    }

    delete[] p2;

    int *ptri4 = new int;
    *ptri4 = 10;

    std::cout << *ptri4 << std::endl;

    delete ptri4;

    int *pa = new int[10];

    for (int i = 0; i < 10; i++) {
        pa[i] = i;
        std::cout << pa[i] << std::endl;
    }

    delete[] pa;

    int var[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        var[i] = 9;
    }

    for (int i = 0; i < 5; i++) {
        std::cout << var[i] << std::endl;
    }

    //  array a 2 dimensioni

    int arr2d[2][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };

    int row = 2;
    int col = 4;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << arr2d[i][j] << std::endl;
            std::cout << "questa é la stamapd el vettore a 2 dimensioni " <<  std::endl;
        }
    }




    #include <stdio.h>


    int array1D[6] = {1, 2, 3, 4, 5, 6};  // Array monodimensionale
    int array2D[2][3];                    // Array bidimensionale

    // Trasformare l'array monodimensionale in bidimensionale
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            array2D[i][j] = array1D[i * 3 + j];
        }
    }

    // Stampa dell'array bidimensionale
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", array2D[i][j]);
        }
        printf("\n");
    }

    
     int arr2D[12]={1,2,3,4,5,6,7,8,9,10,11,12};
    
    // stampo l'array in 3 righe di 4
    
    for (int rig= 0; rig < 3; rig++){
        
        for (int col=0; col< 4; col++){
            
            std::cout <<  "  " << arr2D[rig*4 + col]<<  "  ";
        }
        
        std::cout <<  std::endl;
    }



    int integralei   =1;
    std::cout << sizeof(integralei)<< endl;

    uint8_t uint8var;
    uint16_t uint16var;
    uint32_t uint32var;
    uint64_t uint64var;
    std::cout << sizeof(uint8var) << endl;
    std::cout << sizeof(uint16var) << endl;
    std::cout << sizeof(uint32var) << endl;
    std::cout << sizeof(uint64var) << endl;


    int hexadecimal = 0x2a;
    cout << hexadecimal << endl;


    //  caratteri di escape 
    string txt1 = "We are the so-called\\\"Vikings\" from the north.\n";
    string txt2 = "We are the so-called \\ Vikings \\ from the north.\n";
    string txt3 = "The character \\ is called backslash.\n";

    std::cout << "prova   \n";
    std::cout  << txt1 <<  txt2 << txt3 <<"   \n";



    // bubble sort 
    int arr1[10]={9,2,6,7,5,6,3,1,0,2};

    std::sort(std::begin(arr1), std::end(arr1));  

      
   for(auto it:arr1)
      cout<<it<<"primo loop  \n";
   //print the elements of array



    for (auto it = begin (arr1); it != end (arr1); ++it) {

        cout << *it << "secondo loop \n" <<endl;
        
        
}


    //  static cast 
    float f = 3.5;
    
 
    // Implicit type case
    // float to int
    int acast = f;
    std::cout << "The Value of a: " << acast;
 
    // using static_cast for float to int
    int bcast = static_cast<int>(f);
    std::cout << "\nThe Value of b: " << bcast;

    // using static_cast for float to int
    int ccast = static_cast<char>(f);
    std::cout << "\nThe Value of c: " << ccast;

    
    std::string shello ="Hello World";
    auto numEle= shello.size();
    

    for (int i=0; i <numEle; i++)
    {

        std::cout << shello[i] << endl;

    }






    return 0;
}
