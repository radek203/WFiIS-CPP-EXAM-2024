#include <iostream>

template <typename T>
struct OK {
    virtual void print(T a)
    {
        std::cout << a << "\n";
    }
};

template<typename T = int>
struct Test : OK<T> {

};

struct Bad {
    template <typename T>
    // virtual
    void print(T a) // nie mozna zrobic virtual z template
    {
        std::cout << a << "\n";
    }
};

int main()
{
    OK<int> a;
    a.print(1);

    Bad b;
    b.print(1);
    b.print(1.2);

    Test t;
    t.print(5);
}
