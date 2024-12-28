template <typename T, typename U>
struct Pair
{
    T first{};
    U second{};
};

// Here's a deduction guide for our Pair (needed in C++17 only)
// Pair objects initialized with arguments of type T and U should deduce to Pair<T, U>
template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;


template <typename T>
struct Pair2
{
    T first{};
    T second{};

    /*
    Pair2(T _first, T _second) : first(_first), second(_second)
    {

    }
    */
};

// Jak nie ma konstruktora musimy robic user defined (w C++17!!!!)

// Here's a deduction guide for our Pair (needed in C++17 only)
// Pair objects initialized with arguments of type T and T should deduce to Pair<T>
template <typename T>
Pair2(T, T) -> Pair2<T>;

int main()
{
    Pair<int, int> p11{ 1, 2 }; // explicitly specify class template Pair<int, int> (C++11 onward)
    Pair p12{ 1, 2 };           // CTAD used to deduce Pair<int, int> from the initializers (C++17)


    Pair2<int> p21{ 1, 2 }; // explicitly specify class template Pair<int> (C++11 onward)
    Pair2 p22{ 1, 2 };      // CTAD used to deduce Pair<int> from the initializers (C++17)

    return 0;
}