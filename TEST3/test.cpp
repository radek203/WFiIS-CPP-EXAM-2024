#include <iostream>
using namespace std;

void f(int* p) {
    cout << *p << endl;
}

int main() {
    const int a = 10;
    const int* b = &a;

    // Function f() expects int*, not const int*
    //   f(b);
    int* c = const_cast<int*>(b);
    f(c);

    // Lvalue is const
    //  *b = 20;

    // Undefined behavior
    //  *c = 30;

    int a1 = 40;
    const int* b1 = &a1;
    int* c1 = const_cast<int*>(b1);

    // Integer a1, the object referred to by c1, has
    // not been declared const
    *c1 = 50;

    return 0;
}