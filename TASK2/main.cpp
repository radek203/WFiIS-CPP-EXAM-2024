#include <iostream>
#include <vector>

class Base {
public:
	virtual std::ostream &print(std::ostream &os) const = 0;

	friend std::ostream &operator<<(std::ostream &os, const Base &base) {
		base.print(os);
		return os;
	}
};

std::ostream &Base::print(std::ostream &os) const {
	return os;
}

class Derived1 : public Base {
public:
	virtual std::ostream &print(std::ostream &os) const override {
		os << __PRETTY_FUNCTION__ << std::endl;
		return os;
	}
};

class Derived2 : public Base {
	virtual std::ostream &print(std::ostream &os) const override {
		os << __PRETTY_FUNCTION__ << std::endl;
		return os;
	}
};

class Derived3 : public Derived2 {
	virtual std::ostream &print(std::ostream &os) const override {
		os << __PRETTY_FUNCTION__ << std::endl;
		return os;
	}
};

std::ostream &operator<<(std::ostream &os, const std::vector<Base*> &vec) {
	os << "[" << std::endl;
	for (auto &p : vec) {
		(*p).print(os);
	}
	os << std::endl << "]" << std::endl;
	return os;
}

int main(){
	Derived1 d1;
	Derived3 d3;
	Derived2 d2 = d3; //d3 "bardziej rozbudowana" mozna przypisac -> tracimy informacje, w druga strone nie mozna
	// Derived1 d1_make_err = d2;

	// std::vector<Base> v_make_err = {d1, d2, d3};
	std::vector<Base*> v = {&d1, &d2, &d3};

	std::cout << *v.front()<<std::endl;
	std::cout << v;
}

/*
virtual std::ostream& Derived1::print(std::ostream&) const
[
virtual std::ostream& Derived1::print(std::ostream&) const,
virtual std::ostream& Derived2::print(std::ostream&) const,
virtual std::ostream& Derived3::print(std::ostream&) const
]
*/