#include <iostream>

struct A {
    virtual void foo() const
    {}
    void bar()
    {}
};

struct B : A {
    void foo() const override
    {
        std::cout << "TEST1" << std::endl;
    }

    void foo() {
        std::cout << "TEST2" << std::endl;
    }
};

int main(int argc, char *argv[]) {
    A a;
    B b;

    b.foo();
    const B b2;
    b2.foo();
}
