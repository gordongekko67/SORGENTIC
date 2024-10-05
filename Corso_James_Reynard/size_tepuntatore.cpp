#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    
    // Ottieni un puntatore ai dati del vettore
    int* ptr = vec.data();

    // Stampa i dati usando il puntatore
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << *(ptr + i) << " ";  // Accesso tramite puntatore
    }

    return 0;
}
