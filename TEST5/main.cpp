#include <iostream>

// Oblicza wywolanie z kodu podczas kompilacji, zeby potem nie bylo trzeba
constexpr int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

int main() {
    std::cout << factorial(5) << std::endl;


    // Normalnie bysmy nie mogli zainicjalizowac tablicy w ten sposob
    constexpr int max_size = 100;
    int tab[max_size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < max_size; i++) {
        std::cout << tab[i] << " ";
    }

    return 0;
}