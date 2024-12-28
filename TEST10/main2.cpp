#include <iostream>

//tylko std::cout mozemy uzywac jako cout, inne z std trzeba z std::
using std::cout;
//using namespace std;

class Test {
	double d;
public:
	Test(double _d) : d(_d) {

	}

	operator double() const {
		return d;
	}

	explicit operator int() const {
		return d;
	}
};

double fun(double d) {
	return d * d;
}

double fun(int d1, int d2) {
	return d1 * d2;
}

double fun(int i, double d) {
	return i * d;
}

class A {

};

class B : public A {

};

class C : A {

};

class D {
public:
	//Jezeli mamy klase bazowa zawsze powinna miec virtualny destruktor!!!

	//Jezeli mamy funkcje czysto wirtualna to mozna jej definicje zrobic ale tylko po za
	virtual void Rysuj() = 0;

	//Nie mozna jej overridowac, (tak samo przy class D final - nie mozna po niej dziedziczyc)
	virtual void Test() final {
		std::cout << "TEST D" << std::endl;
	}
};

void D::Rysuj() {
	std::cout << "TEST Rysuj D" << std::endl;
}

class E : public D {
public:
	void Rysuj() override {
		D::Rysuj();
		std::cout << "TEST Rysuj E" << std::endl;
	}
	/*
	void Test() {

	}
	 */
};

int main() {

	Test test(10.2);

	cout << "TEST1 " << fun(test) << std::endl;
	cout << "TEST2 " << fun(static_cast<int>(test), static_cast<int>(test)) << std::endl;

	const int i = 20;
	fun(*const_cast<int*>(&i), 10);

	B b;

	//mozna zrobic referencje (i wsk) tylko wtedy kiedy dziedziczy publicznie
	A &a = b;

	C c;
	//A *aa = &c;

	E e;
	e.Rysuj();
	e.Test();

	std::cout << "TYPEID TEST " << typeid(e).name() << " " << typeid(dynamic_cast<D&>(e)).name() << " " << typeid(a).name()<< " " << typeid(b).name() << std::endl;

	return 0;
}