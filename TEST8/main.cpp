#include <iostream>

class A {
	int a;
public:
	A(int a) : a(a) {}
	int getA() { return a; }

	A(const A& other) = delete;
	A &operator=(const A& other) = delete;

	A(A&& other) {
		a = other.a;
	}

	A &operator=(A&& other) {
		a = other.a;

		return *this;
	}
};

template <typename T>
class Box {
	T val;
public:
	Box(T val) : val(val) {}
	T getVal() { return val; }

	void print() { std::cout << *this << std::endl; }

	friend std::ostream &operator<<(std::ostream &os, const Box<T> &box) {
		os << __PRETTY_FUNCTION__ << std::endl << box.val;
		return os;
	}
};

class B {
protected:
	int b;
public:
	B(int b) : b(b) {}

	//nie moze byc wirtualnej
	template<typename T>
	void fun1(T t) {
		std::cout << t << " " << b << std::endl;
	}
};

class C : public B {
public:
	C(int c) : B(c) {

	}

	//mozemy przyslonic
	template<typename T>
	void fun1(T t) {
		std::cout << "Przyslonieta " << t << " " << b << std::endl;
	}
};

int main() {
	A a(5);

	A b(1);
	//b=a;

	//A c = a;

	A d = std::move(a);

	A e(1);
	e = std::move(a);

	//std::cout << a.getA() << std::endl;

	Box<int> box(5);
	std::cout << box.getVal() << std::endl;

	Box<Box<Box<int>>> boxTest = Box<Box<Box<int>>>(Box<Box<int>>(Box<int>(5)));
	boxTest.print();
	boxTest.getVal().getVal().getVal();

	B bb(1);
	bb.fun1(10);

	C cc(2);
	cc.fun1(10);

	B bc = cc;
	bc.fun1(11);

	return 0;
}