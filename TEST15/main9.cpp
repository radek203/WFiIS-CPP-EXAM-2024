// C++ program to demonstrate working of
// Variadic function Template
#include <iostream>
#include <vector>
using namespace std;

// To handle base case of below recursive
// Variadic function Template
void print() {
    cout << "I am empty function and I am called at last.\n";
}

// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template <typename T, typename... Types>
void print(T var1, Types... var2) {
    cout << var1 << endl;

    print(var2...);
}



template<class T>
struct Alloc {};

template<class T>
using Vec = vector<T, Alloc<T>>; // type-id is vector<T, Alloc<T>>

Vec<int> v; // Vec<int> is the same as vector<int, Alloc<int>>




// Driver code
int main()
{
    print(1, 2, 3.14,
          "Pass me any "
          "number of arguments",
          "I will print\n");

    return 0;
}
