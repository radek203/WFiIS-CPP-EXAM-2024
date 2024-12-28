#include <iostream>
#include <cmath>

// Szablon klasy pomocniczej
template<typename T>
struct Helper {
	static void process() {
		std::cout << "Generic process\n";
	}
};

// Specjalizacja pełna dla typu int
template<>
struct Helper<int> {
	static void process() {
		std::cout << "Int process\n";
	}
};

// Klasa z funkcją szablonową
class MyClass {
public:
	template<typename T>
	void myFunction() {
		Helper<T>::process();
	}
};

template<typename T>
class MyClass2 {
public:
	void myFunction() {
		Helper<T>::process();
	}
};

class MyClass3 {
public:

	template<typename T>
	void fun1(T a) {
		std::cout << " " << a << std::endl;
	}

	template<typename T>
	void fun1(T *a) {
		std::cout << " " << *a << std::endl;
	}
};

//Nie mozna zrobic szesciowej specjalizacji funkcji!!!!
/*
template<typename T>
void MyClass3::fun1<T*>(T *a) {
	std::cout << " " << *a << std::endl;
}
 */

template<>
void MyClass3::fun1<int>(int a) {
	std::cout << " INT " << a << std::endl;
}

template<>
void MyClass3::fun1<const int>(const int a) {
	std::cout << " INT C " << a << std::endl;
}

template<>
void MyClass3::fun1<int*>(int *a) {
	std::cout << " INT W " << *a << std::endl;
}

template<>
void MyClass3::fun1<const int*>(const int *a) {
	std::cout << " INT C W " << *a << std::endl;
}

template<>
void MyClass3::fun1<int&>(int &a) {
	std::cout << " INT R " << a << std::endl;
}

template<>
void MyClass3::fun1<const int&>(const int &a) {
	std::cout << " INT C R " << a << std::endl;
}

template<typename T>
class Test {
public:
	void print(T val) {
		std::cout << "TEST1 " << val << std::endl;
	}
};

//Specjalizacja pelna
template<>
class Test<double*> {
public:
	void print(double* val) {
		std::cout << "TEST3 " << *val << std::endl;
	}
};

//Specjalizacja czesciowa
template<typename T>
class Test<T*> {
public:
	void print(T *val) {
		std::cout << "TEST2 " << *val << std::endl;
	}
};

template<typename T = int, int size = 10>
class Array {

};

template<typename T>
T my_sum(T el1, T el2) {
	return el1 + el2;
}

//Nie ma czegos takiego jak czesciowa specjalizacja dla funkcji, mozna jedynie przeladowac nazwe
template<typename T>
T my_sum(T* el1, T* el2) {
	return *el1 + *el2;
}

template<>
double my_sum<double>(double el1, double el2) {
	return round(el1 + el2);
}

template<>
float my_sum<float>(float el1, float el2) {
	return roundf(el1 + el2) + 1;
}

template<typename T>
class Printer {
	T val;
public:
	Printer(T _val) : val(_val) {

	}

	void print() const {
		std::cout << " VAL: " << val << std::endl;
	}
};

template<>
void Printer<int*>::print() const {
	std::cout << " VAL: " << *val << " PTR: " << val << std::endl;
}

int main() {

	MyClass myClass;
	myClass.myFunction<double>(); // Generic process
	myClass.myFunction<int>();    // Int process

	MyClass2 <double> myClass2;
	myClass2.myFunction();
	MyClass2 <int> myClass3;
	myClass3.myFunction();

	MyClass3 obj1;
	int a = 5;
	obj1.fun1(a);
	obj1.fun1(&a);
	obj1.fun1<const int>(a);
	obj1.fun1<const int&>(a);
	const int *b = &a;
	obj1.fun1(b);

	Test <int> test1;
	Test <int*> test2;
	Test <double*> test3;

	int c = 5;
	double d = 10;
	test1.print(c); // TEST1
	test2.print(&c); // TEST2
	test3.print(&d); // TEST3

	Array<int, 10> arr1;

	//Nie mozna bo to jest podczas komilacji!!!
	//Array<int, c> arr2;

	//Nie musimy podawac w <> jaki template
	std::cout << " SUM INT " << my_sum(10, 20) << " SUM DOUBLE " << my_sum(21.3, 30.1) << std::endl;

	Printer p1(c);
	p1.print();

	Printer p2(&c);
	p2.print();

	return 0;
}
