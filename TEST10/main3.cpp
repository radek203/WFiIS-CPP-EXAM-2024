#include <iostream>

class A {
protected:
	int i = 0;
public:
	A() {
		std::cout << "Kons A" << std::endl;
	}

	virtual void print(bool check = true) {
		std::cout << "Print A" << std::endl;
	}
};

class B {
protected:
	int i = 1;
public:
	B() {
		std::cout << "Kons B" << std::endl;
	}

	virtual void print(bool check = false) {
		std::cout << "Print B" << std::endl;
	}
};

class X {
public:
	X() {
		std::cout << "Kons X" << std::endl;
	}
};

//Wywolywanie konstruktorow zalezy od tego jak tu sa ulozone (przy dziedziczeniu), i najpierw sa virtualne
class C : public B, public A, public virtual X {
public:
	C() : A(), B() {
		std::cout << "Kons C" << std::endl;
	}

	//Musi zawierac te same paremetry, jak nie damy wartosci domyslnej to jest ona pobierana z rodzica
	void print(bool check) override {
		A::print();
		B::print();
		std::cout << " A.i " << A::i << " B.i " << B::i << " " << check << std::endl;
	}
};

int main() {
	C c;
	c.print(false);

	A *a = &c;
	a->print();

	return 0;
}