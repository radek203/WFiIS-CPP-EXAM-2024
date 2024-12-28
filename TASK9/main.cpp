#include <iostream>

class S {
public:
	S(int i = 0) { std::cout << "S " << i << " "; }
	virtual ~S() { std::cout << "~S "; }
};

class A : public S {
public:
	A(int i = 0) : S(i) { std::cout << "A " << i << " "; }
	virtual ~A() { std::cout << "~A "; }
};

class B : public A {
public:
	B(int i = 0) : A(i) { std::cout << "B " << i << " "; }
	virtual ~B() { std::cout << "~B "; }
};

class C : virtual public A {
public:
	C(int i = 0) : A(i) { std::cout << "C " << i << " "; }
	virtual ~C() { std::cout << "~C "; }
};

class D : public C, virtual public B {
public:
	D(): C(40), B(20) { std::cout << "D\n"; }
	virtual ~D() { std::cout << "~D "; }
protected:
	C c = C(60);
};

int main(){
	D d;
}