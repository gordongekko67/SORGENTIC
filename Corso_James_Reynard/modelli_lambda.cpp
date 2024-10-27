#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    // Dati di esempio per i vari casi
    std::vector<int> numbers1 = {5, 3, 8, 1, 2};       // per ordinamento
    std::vector<int> numbers2 = {4, 7, 8, 11, 13, 17}; // per trovare numeri primi
    std::vector<int> numbers3 = {3, 4, 5, 6, 8, 10};   // per somma numeri pari
    std::vector<int> numbers4 = {1, 2, 2, 3, 4, 4, 5}; // per rimuovere duplicati

    // 1. Ordinamento di un vettore in ordine decrescente
    std::sort(numbers1.begin(), numbers1.end(), [](int a, int b) {
        return a > b; // Ordinamento decrescente
    });
    std::cout << "Ordinamento decrescente: ";
    for (int n : numbers1) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    // 2. Trovare numeri primi in un vettore
    std::vector<int> primes;
    std::copy_if(numbers2.begin(), numbers2.end(), std::back_inserter(primes), [](int n) {
        return isPrime(n);
    });
    std::cout << "Numeri primi: ";
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << "\n";

    // 3. Somma di tutti i numeri pari in un vettore
    int sum = 0;
    std::for_each(numbers3.begin(), numbers3.end(), [&sum](int n) {
        if (n % 2 == 0) {
            sum += n;
        }
    });
    std::cout << "Somma dei numeri pari: " << sum << "\n";

    // 4. Rimuovere elementi duplicati in un vettore
    auto end = std::unique(numbers4.begin(), numbers4.end(), [](int a, int b) {
        return a == b;
    });
    numbers4.erase(end, numbers4.end());
    std::cout << "Vettore senza duplicati consecutivi: ";
    for (int n : numbers4) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    return 0;
}
