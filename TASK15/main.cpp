#include <iostream>
#include <string>

struct is_printable {
	virtual ~is_printable() = default;

	virtual void print(std::ostream &os) const {

	}

	friend std::ostream &operator<<(std::ostream &os, const is_printable &p) {
		p.print(os);
		return os;
	}
};

struct A : is_printable {
	std::string str;

	virtual ~A() = default;

	A(const std::string &_str) : str(_str) {

	}

	void print(std::ostream &os) const override {
		os << str;
	}
};

struct B : is_printable {
	int val;

	virtual ~B() = default;

	B(int i) : val(i) {

	}

	void print(std::ostream &os) const override {
		os << val;
	}
};

int main()
{
	A a ("Tekst"); B b {123};
	std::cout<< "a:\t"<<a<<"; b:\t"<<b<<"\n";
	const is_printable & a_r = a; const is_printable & b_r = b;
	std::cout<< "a_r:\t"<<a_r<<"; b_r:\t"<<b_r<<"\n";
}

/*
a:      Tekst; b:       123
a_r:    Tekst; b_r:     123
*/