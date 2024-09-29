#include <iostream>
#include <iterator>  // Per std::begin() e std::end()
#include <vector>
#include <algorithm> // Per std::for_each
#include <ranges>    // Per std::ranges::for_each (C++20)

void for_tradizionale() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    std::cout << "Ciclo for tradizionale con indici:" << std::endl;
    for (int i = 0; i < 6; ++i) {
        std::cout << arr[i] << std::endl;
    }
}

void while_tradizionale() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    std::cout << "Ciclo while tradizionale con indici:" << std::endl;
    int i = 0;
    while (i < 6) {
        std::cout << arr[i] << std::endl;
        ++i;
    }
}

void for_intervalli() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    std::cout << "Ciclo for basato su intervalli:" << std::endl;
    for (const auto& elem : arr) {
        std::cout << elem << std::endl;
    }
}

void for_puntatori() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    std::cout << "Ciclo con puntatori:" << std::endl;
    int* ptr = arr;
    for (int i = 0; i < 6; ++i) {
        std::cout << *(ptr + i) << std::endl;
    }
}

void for_std_begin_end() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    std::cout << "Ciclo con std::begin() e std::end():" << std::endl;
    for (auto it = std::begin(arr); it != std::end(arr); ++it) {
        std::cout << *it << std::endl;
    }
}

void for_vector_iterator() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    std::cout << "Ciclo con iteratori std::vector:" << std::endl;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

void for_each_lambda() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    std::cout << "Ciclo con std::for_each e lambda:" << std::endl;
    std::for_each(std::begin(arr), std::end(arr), [](int elem) {
        std::cout << elem << std::endl;
    });
}

void ranges_for_each() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    std::cout << "Ciclo con std::ranges::for_each (C++20):" << std::endl;
    std::ranges::for_each(arr, [](int elem) {
        std::cout << elem << std::endl;
    });
}

int main() {
    // Chiamate di tutte le funzioni che mostrano i vari metodi di iterazione
    for_tradizionale();
    std::cout << std::endl;

    while_tradizionale();
    std::cout << std::endl;

    for_intervalli();
    std::cout << std::endl;

    for_puntatori();
    std::cout << std::endl;

    for_std_begin_end();
    std::cout << std::endl;

    for_vector_iterator();
    std::cout << std::endl;

    for_each_lambda();
    std::cout << std::endl;

    ranges_for_each();
    std::cout << std::endl;

    return 0;
}
