#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct MyStructure
{                    // Structure declaration
    int myNum;       // Member (int variable)
    string myString; // Member (string variable)
};

struct MyStructure2
{
    int valore;
    std::string descrizione;
    bool veroFalso;
    float numeroDimensione;
};

std::vector<MyStructure2> v2;
std::vector<MyStructure> v;

double elevamento_potenza(double &valore, int &potenza)
{
    double valore_ritorno = 1.0;
    int i;
    for (i = 0; i < potenza; i++)
    {
        valore_ritorno *= valore;
    }

    return (valore_ritorno);
}

double elevamento_potenza2(double *valore, int *potenza)
{
    double valore_ritorno = 1.0;
    int i;
    for (i = 0; i < *potenza; i++)
    {
        valore_ritorno *= *valore;
    }

    *valore = 5.3;

    return (valore_ritorno);
}

double getAverage(int *arr, int size)
{
    int i, sum = 0;
    double avg;

    for (i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    avg = double(sum) / size;

    return avg;
}


void passavec(const vector<int> &v7){

    // Print vector elements
    for (auto lab : v7)
    {
        cout << lab << "\n";
    }



}



void passavettore(const vector<int> &v7){

    // Print vector elements
    for (auto lab : v7)
    {
        cout << lab << "\n";
    }



}










int main()
{

    // this is a comment
    // this is a C++ tutorial

    cout << "Hello World! prova  "; // this is a comment
    cout << "Hello World!";
    cout << "I am learning C++";

    //  questo e' il sizeof
    int arr[] = {1, 2, 3, 4, 5};

    cout << sizeof(char) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(arr) << endl;
    cout << sizeof(arr[0]) << endl;

    int arr1[5] = {1, 2, 3, 2, 1};
    // define an integer array of size 5

    for (auto it : arr1)
        cout << it << "funziona il loop  " << endl;
    // print the elements of array

    int count = 10;

    for (size_t i = 0; i < count; i++)
    {
        /* code */
        cout << "prova" << " del cazzo";
    }

    int myNum = 5;            // Integer (whole number without decimals)
    double myFloatNum = 5.99; // Floating point number (with decimals)
    char myLetter = 'D';      // Character
    string myText = "Hello";  // String (text)
    bool myBoolean = true;    // Boolean (true or false)

    int myAge = 57;
    cout << "my age =" << myAge; // stampo age

    int x = 5;
    int y = 10;
    int somma = x + y;
    cout << " la somma è " << somma;

    int myNum2 = 15;
    int x1 = 5, y1 = 10, z1 = 20;

    int betaa1 = x1 + y1 + z1;
    cout << " La somma di tutti e tre è " << betaa1;

    int x2, y2, z2;
    x2 = y2 = z2 = 10;

    const int costanteRaggio = 10;

    int num = 5;
    char letter = 'A';
    float nummer = 5.89;
    string myString = "abcdefgh";

    // append stringa
    string firstName = "John ";
    string lastName = "Doe";
    string fullName = firstName.append(lastName);
    cout << fullName << endl;

    // lunghezza di una stringa
    string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "The length of the txt string is: " << txt.length();

    string txt1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "The length of the txt string is: " << txt1.size();

    string strumentoFinanziario = " Stringa1  Stringa2";
    string delta = "0.93";
    string posizione = "1";

    // Utilizza std::istringstream per suddividere la stringa
    std::istringstream iss(strumentoFinanziario);
    std::string part1, part2;

    // Estrai i primi due campi
    iss >> part1 >> part2;

    // Combina i due campi
    std::string simbolo_scadenza = part1 + " " + part2;

    // calcolo i valori della riga
    float valore_Delta = stof(delta);
    int int_Posizione = stoi(posizione);
    float valore_Delta_riga = int_Posizione * 100 * valore_Delta;

    // presa di un elemento di una stringa
    string myString1 = "Hello";
    cout << myString1[1];

    // prende l'ultimo elemento
    string myString2 = "Hello";
    cout << myString2[myString2.length() - 1];
    // Outputs o

    string myString3 = "Hello";
    cout << myString3; // Outputs Hello

    cout << myString3.at(0);                      // First character
    cout << myString3.at(1);                      // Second character
    cout << myString3.at(myString3.length() - 1); // Last character

    myString3.at(0) = 'J';
    cout << myString3; // Outputs Jello

    double valore = 3;
    int potenza = 2;
    double *ptrvalore = &valore;
    int *ptrpotenza = &potenza;
    double risultato = elevamento_potenza(valore, potenza);
    double risultato2 = elevamento_potenza2(&valore, &potenza);

    cout << " il risultato dell elevamento a potenza e " << risultato << endl;
    cout << " il risultato dell elevamento a potenza e " << risultato2 << endl;
    cout << " il valore di ritorno alla funzione e stato modificato in  " << valore << endl;

    // passando array to una funzione
    // an int array with 5 elements.
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;

    // pass pointer to the array as an argument.
    avg = getAverage(balance, 5);

    // output the returned value
    cout << "Average value is: " << avg << endl;

    int a = 0;
    int b = 1;

    if (a > b)
    {
        /* code */
    }

    for (int i = 0; i < 10; i++)
    {

        MyStructure a1;

        a1.myNum = 10;
        a1.myString = "prova";
        v.push_back(a1);
    }

    for (int i = 0; i < v.size(); i++)
    {
        MyStructure a1;
        a1 = v[i];

        cout << a1.myNum << a1.myString << endl;
    }

    // col vector non si può assegnare direttamente
    vector<int> v;
    //  bensi usare la parola chiave assign

    v.assign(5, 2);

    vector<int> c1;
    vector<int>::iterator c1_Iter;
    vector<int>::const_iterator c1_cIter;

    c1.push_back(1);
    c1.push_back(2);

    cout << "The vector c1 contains elements:";
    c1_Iter = c1.begin();
    for (; c1_Iter != c1.end(); c1_Iter++)
    {
        cout << " " << *c1_Iter;
    }
    cout << endl;

    cout << "The vector c1 now contains elements:";
    c1_Iter = c1.begin();
    *c1_Iter = 20;
    for (; c1_Iter != c1.end(); c1_Iter++)
    {
        cout << " " << *c1_Iter;
    }
    cout << endl;

    MyStructure2 a3;

    for (int i = 0; i < 10; i++)

    {
        a3.valore = i;
        a3.descrizione = "Le lasagne della nonna";
        v2.push_back(a3);
    }

    for (auto it = begin(v2); it != end(v2); ++it)
    {

        cout << it->valore << endl;
        cout << it->descrizione << endl;
    }

    // Create a vector called cars that will store strings
    vector<string> cars ;
    // Change the value of the first element

    std::string arr4[10]= {"Tesla.", "Fiat", "opel"};


    for (int i = 0; i < 10 ; i++)
    {
        if (arr4[i]!=" "){
            cars.push_back(arr4[i]);
        }
        
    }
    

    
    

    // Print vector elements
    for (string car : cars)
    {
        cout << car << "\n";
    }


    std::vector<int> v7 ;
    v7.push_back(1);
    v7.push_back(2);
    v7.push_back(3);

    passavec(v7);

    int arr2[10];

    for (size_t i = 0; i < 10; i++)
    {
        arr2[i] = i; /* code */
        std::cout << arr2[i] << std::endl;
    }

    for (int i : arr2)
    {
        cout << i << "\n";
    }



    std::vector <int>v6;

    v6.push_back(1);
    v6.push_back(2);


    passavettore(v6);










    return 0;
}
