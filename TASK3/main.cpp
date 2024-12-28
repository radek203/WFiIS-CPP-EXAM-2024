#include <iostream>

template<typename T>
class B {
	T value;
public:
	typedef T value_type;

	B(T val) : value(val) {

	}

	T get() {
		return value;
	}
};

template<typename T>
class B<T*> {
	T *value;
public:
	typedef T value_type;

	~B() {
		delete value;
	}

	B(T *val) : value(val) {

	}

	B(const B &otherB) = delete;
	B &operator=(const B &otherB) = delete;

	T get() {
		return *value;
	}
};


int main()
{
	typedef B<int> int_b;
	typedef B<int*> int_p_b;        //jednak typedef

	int_b a(1);
	int_b a_copy(a);
	int_p_b b(new int_p_b::value_type{2});
	// int_p_b e = b; //error
	// b=b //error

	std::cout << "a=" << a.get() << std::endl;
	std::cout << "a_copy=" << a_copy.get()+1 << std::endl;
	std::cout << "b=" << b.get()+1 << std::endl;
}

/*
a=1
a_copy=2
b=3
*/