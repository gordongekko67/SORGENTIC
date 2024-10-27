#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Definizione di una lambda expression che somma 10 ad ogni elemento
    auto addTen = [](int n) { return n + 10; };

    // Applicazione della lambda expression a ciascun elemento del vettore
    std::for_each(numbers.begin(), numbers.end(), [](int &n) { n += 10; });

    // Stampa dei risultati
    std::cout << "Vettore modificato: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }

    std::cout << std::endl;

    return 0;
}
