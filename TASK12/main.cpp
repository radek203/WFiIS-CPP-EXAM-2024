#include <iostream>

using namespace std;

struct A {
	int a;
	int b;

	explicit A() : A(0, 0) {
		std::cout << __PRETTY_FUNCTION__ << ": " << "_a=" << a << ",_b=" << b << std::endl;
	}

	explicit A(int _a) : A(_a, 0) {
		std::cout << __PRETTY_FUNCTION__ << ": " << "_a=" << a << ",_b=" << b << std::endl;
	}

	explicit A(int _a, int _b) : a(_a), b(_b) {
		std::cout << __PRETTY_FUNCTION__ << ": " << "_a=" << a << ",_b=" << b << std::endl;
	}

	//A(const A &_a) = delete;

	A(A &&_a) : A(_a.a, _a.b) {

	}
};

int main()
{
	cout << "a->"; A a;
	cout << "b->"; A b(1);
	cout << "c->"; A c(1,2);

	cout << "d->"; A d = std::move(c);

	//A e = c;
	//A f = 1;
}
/*
a-> A::A(int,int): _a=0,_b=0
A::A(): _a=0,_b=0
b-> A::A(int,int): _a=1,_b=0
A::A(int): _a=1,_b=0
c-> A::A(int,int): _a=1,_b=2
d-> A::[...]: _a=1,_b=2
*/