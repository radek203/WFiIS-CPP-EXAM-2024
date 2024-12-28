#include <iostream>

struct B {
	virtual std::ostream &printOn(std::ostream &os) const = 0;

	friend std::ostream &operator<<(std::ostream &os, const B &b) {
		b.printOn(os);
		return os;
	}
};

std::ostream &B::printOn(std::ostream &os) const {
	os << __PRETTY_FUNCTION__ << std::endl;
	return os;
}

struct D1 : B {
	virtual std::ostream &printOn(std::ostream &os) const {
		os << __PRETTY_FUNCTION__ << std::endl;
		return os;
	}
};

struct D2 : D1 {

};

struct D3 : D1 {
	virtual std::ostream &printOn(std::ostream &os) const {
		os << __PRETTY_FUNCTION__ << std::endl;
		return os;
	}
};

struct D4 : D3 {
	virtual std::ostream &printOn(std::ostream &os) const {
		B::printOn(os);
		D1::printOn(os);
		D3::printOn(os);

		os << __PRETTY_FUNCTION__ << std::endl;
		return os;
	}
};


int main(int argc, char *argv[]) {
	// B b; odkomentowanie powoduje błąd kompilacji
	D1 d1; D2 d2; D3 d3; const D4 d4;
	std::cout << "d1: " << d1 << "d2: " << d2 << "d3: " << d3 << "d4: " << d4;
}

/*
d1: virtual std::ostream& D1::printOn(std::ostream&) const
d2: virtual std::ostream& D1::printOn(std::ostream&) const
d3: virtual std::ostream& D3::printOn(std::ostream&) const
d4: virtual std::ostream& B::printOn(std::ostream&) const
virtual std::ostream& D1::printOn(std::ostream&) const
virtual std::ostream& D3::printOn(std::ostream&) const
virtual std::ostream& D4::printOn(std::ostream&) const
*/