#include <iostream>

struct A {
	int i = 1;
};

template<typename T>
struct ptr {
	T *p = nullptr;

	~ptr() {
		delete p;
	}

	explicit ptr(T *_p = new T()) : p(_p) {

	}

	ptr(const ptr<T> &other) = delete;
	ptr &operator=(const ptr<T> &other) = delete;

	T &operator*() const {
		return *p;
	}

	T *operator->() const {
		return p;
	}

	bool operator==(const ptr<T> &other) const {
		return p == other.p;
	}

	bool operator!=(const ptr<T> &other) const {
		return p != other.p;
	}
};

int main() {
	const ptr<A>  a(new A);
	const ptr<A> b;
	ptr<A> c(new A);

	//ptr<A>  _b_error = new A;      // Odkomentowanie powoduje błąd kompilacji
	//a = a;               // Odkomentowanie powoduje błąd kompilacji
	//const ptr<A> _c_error = a;     // Odkomentowanie powoduje błąd kompilacji

	std::cout << (((*a).i, a->i))        << " " << ++c->i << " ";
	std::cout << (a == ptr<A>() ) << " " << (a != b) << "\n";
}
// 1 2 0 1