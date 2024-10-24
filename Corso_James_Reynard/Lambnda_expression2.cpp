#include <iostream>
#include <vector>
#include <algorithm> // per std::sort

int main() {
    std::vector<int> v ;
    v.push_back(5);
    v.push_back(3);
    v.push_back(9);


    // Ordinamento in ordine decrescente usando una lambda expression
    std::sort(v.begin(), v.end(), [](int a, int b) {
        return a > b; // Condizione per l'ordinamento decrescente
    });

    // Stampa del vettore ordinato
    for (int n : v) {
        std::cout << n << " ";
    }

    return 0;
}
