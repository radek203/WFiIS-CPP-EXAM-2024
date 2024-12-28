#include <iostream>
#include <deque>
#include <vector>
#include <array>

struct A_ {
	virtual ~A_() = default;
	int a;
};

struct A {
	int a;
};

template<typename T1, typename T2>
void my_copy(T1 begin, T1 end, T2 start) {
	/*
	try {
		A &a1 = dynamic_cast<A&>(*begin);
		std::cout << "Copying POD objects" << std::endl;
	} catch (...) {
		std::cout << "Copying non-POD objects" << std::endl;
	}

	std::copy(begin, end, start);
	*/

	// Musimy dac typename, zeby kompilatow mogl rozpoznac to poprawnie jako typ, tak samo np.
	// typeid(typename T1::value_type).name()
	if (std::is_trivial<typename T1::value_type>::value) {
		std::cout << "Copying POD objects" << std::endl;
		std::copy(begin, end, start);
	} else {
		std::cout << "Copying non-POD objects" << std::endl;
	}
}

template<typename T>
void test() {
	T src[10] = {};
	T dst[10] = {};

	std::cout << typeid(T).name() << " is_pod = " << std::is_pod<T>::value << ", ";
}

int main()  {

	//prosze wykorzystac te informacje
	std::integral_constant<bool,true> tA = std::is_trivial<A>::type();
	std::integral_constant<bool,false> tA_ = std::is_trivial<A_>::type();

	//Iterator dla każdego kontenera ma zdefiniowany
	//typ value_type określający typ obiektu na który wskazuje
	std::deque<A> vA1;
	std::vector<A> vA2;
	my_copy(vA1.begin(), vA1.end(), vA2.begin() ) ;

	std::vector <A_> vA_1;
	std::deque<A_> vA_2;
	my_copy(vA_1.begin(), vA_1.end(), vA_2.begin() ) ;

	test<A>();
	test<A_>();
	test<std::array<A, 10>>();
	test<std::vector<A>>();
}

/*
Copying POD objects
Copying non-POD objects
*/