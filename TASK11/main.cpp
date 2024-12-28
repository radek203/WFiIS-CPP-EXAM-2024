#include <iostream>

template<typename T>
struct ptr {
	T *p = nullptr;

	typedef T value_type;

	~ptr() {
		delete p;
	}

	explicit ptr(T *_p) : p(_p) {

	}

	ptr(const ptr &_p) = delete;
	ptr &operator=(const ptr &_p) = delete;
	ptr &operator=(ptr &&_p) = delete;

	ptr(ptr &&_p) {

	}

	T &operator*() const {
		return *p;
	}

	T *operator->() const {
		return p;
	}
};

template<typename T = float>
struct Value_t {
	typedef T value_type;

	explicit Value_t(T _val = T()) : _v(_val) {

	}

	T _v;

	friend std::ostream &operator<<(std::ostream &os, const Value_t &t) {
		os << t._v;
		return os;
	}
};

using Float_t = Value_t<>;


int main()
{
	using Type_t = ptr<std::pair<Float_t, Float_t>>;

	Type_t t1{new Type_t::value_type{}};
	// Type_t t2 = t1;
	// Type_t t2; t2 = t1;
	// Type_t t2 = new Type_t::value_type();
	// Powyższe się mają nie kompilować
	(*t1).first = Type_t::value_type::first_type{1.};
	t1->second = Type_t::value_type::second_type{2.5};

	Type_t t2 = std::move(t1);

	const Type_t t3{new Type_t::value_type{}};
	// t3=std::move(t2);
	// (*t3).first= 13;
	// t3->second = 13;
	// Powyższe się mają nie kompilować
	(*t3).first = Type_t::value_type::first_type{1};
	t3->second = Type_t::value_type::second_type{2.5};


	std::cout << (*t3).first._v << ", " << t3->second << std::endl;
}
// 1, 2.5