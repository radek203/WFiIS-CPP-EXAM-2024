//
// Created by Radek on 17.04.2024.
//
#include <stdio.h>
#include <iostream>

struct F {
    virtual void test() {
        printf_s("in A\n");
    }
};

struct G : F {
    virtual void test() {
        printf_s("in B\n");
    }

    void test2() {
        printf_s("test2 in B\n");
    }
};

struct H : G {
    virtual void test() {
        printf_s("in C\n");
    }

    void test2() {
        printf_s("test2 in C\n");
    }
};

void Globaltest(F& a) {
    try {
        H &c = dynamic_cast<H&>(a);
        printf_s("in GlobalTest\n");
    }
    catch(std::bad_cast) {
        printf_s("Can't cast to C\n");
    }
}

void Globaltest2(F* a) {
    H *c = dynamic_cast<H*>(a);
    if (c)
        printf_s("in GlobalTest2\n");
    else
        printf_s("Can't cast to C\n");
}

int main() {
    F *pa = new H;
    F *pa2 = new G;

    std::cout << "TEST 1" << std::endl;
    pa->test();
    pa2->test();

    std::cout << "TEST 2" << std::endl;
    G * pb = dynamic_cast<G *>(pa);
    if (pb)
        pb->test2();

    H * pc = dynamic_cast<H *>(pa2);
    if (pc)
        pc->test2();

    std::cout << "TEST 3" << std::endl;
    H ConStack;
    Globaltest(ConStack);

    // fails because B knows nothing about C
    G BonStack;
    Globaltest(BonStack);

    std::cout << "TEST 4" << std::endl;
    F* pa3 = &BonStack;
    Globaltest2(pa3);

    F* pa4 = &ConStack;
    Globaltest2(pa4);

    return 0;
}