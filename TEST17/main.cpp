#include <iostream>

// Przykładowa struktura T, która będzie używana jako argument szablonu dla Bar
struct ExampleStruct {
    using A = double;  // Zagnieżdżony typ A
    static const int B = 5;  // Statyczna zmienna B

    template <typename U>
    struct C {
        void gobble(U value) {
            std::cout << "Gobbling value: " << value << std::endl;
        }
    };
};

// Definicja struktury Bar dla struktury ExampleStruct
template <typename T>
struct Bar {
    typename T::A x = {};

    void foo()
    {
        int a = T::B;   // Użycie statycznej zmiennej B z T

        typename T::template C<int> z;  // Użycie szablonu C<int> z T
        z.gobble(a * x);  // Wywołanie metody gobble na obiekcie z
    }
};

int main()
{
    Bar<ExampleStruct> bar;
    bar.x = 3.14;  // Przypisanie wartości do x (typu double, zagnieżdżonego typu A w ExampleStruct)
    bar.foo();  // Wywołanie metody foo dla obiektu bar

    return 0;
}