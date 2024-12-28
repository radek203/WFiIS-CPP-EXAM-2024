#include <iostream>
#include <functional>
#include <vector>
#include <list>
#include <memory>

template<typename T, typename Fun>
void myForEach(T start, T end, Fun f1) {
	for (auto p = start; p < end; ++p) {
		f1(*p);
	}
}

template<typename T, int size>
class MyContainer {
	T arr[size + 1] = {};
public:
	MyContainer(std::initializer_list<T> list) {
		std::copy(list.begin(), list.end(), arr);
	}

	T *begin() {
		return &arr[0];
	}

	T *end() {
		return &arr[size];
	}

	T &operator[](int index) {
		return arr[index];
	}
};

template<typename T1, typename T2>
class MyPair {
	T1 f;
	T2 s;
public:
	typedef T1 first_type;
	typedef T2 second_type;

	MyPair(T1 _first, T2 _second) : f(_first), s(_second) {

	}

	T1 first() {
		return f;
	}

	T2 second() {
		return s;
	}
};

template<typename T>
class MyUniquePtr {
	T *ptr;
public:
	~MyUniquePtr() {
		delete ptr;
	}

	MyUniquePtr() {
		ptr = new T;
	}

	T *get() {
		return ptr;
	}

	T &operator*() {
		return *ptr;
	}
};

int main() {

	std::vector<int> vec = {1, 2, 3, 4, 5};

	myForEach(vec.begin(), vec.end(), [](int &param) { param += 2; });

	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " " << std::endl;
	}

	MyContainer<int, 6> container = {4, 5, 7};
	for (auto p = container.begin(); p < container.end(); ++p) {
		std::cout << " My container " << *p << std::endl;
	}

	std::cout << "TEST" << std::endl;
	container[4] = 20;
	for (auto p = container.begin(); p < container.end(); ++p) {
		std::cout << " My container " << *p << std::endl;
	}

	std::list<int> l = {10, 4, 1};
	for (auto p : l) {
		std::cout << " List " << p << std::endl;
	}

	std::list<int> lst;
	std::list<int>::value_type val; // int
	std::list<int>::iterator it = lst.begin();

	std::pair<int, std::string> stdPair = {1, "XD"};
	std::pair<int, std::string>::first_type firstType1 = 30;
	std::pair<int, std::string> stdPair2 = std::make_pair(2, "XDD");

	int i = 111;
	std::pair<int&, std::string> stdPair3 = std::make_pair(std::ref(i), "XDD"); //auto stdPair3 =

	std::pair<int*,int*> stdPair4 = {&i, &i};

	MyPair<int, std::string> myPair = {1, "XD"};
	MyPair<int, std::string>::first_type firstType = 30; //Po prostu jak typedef tylko z srodka klasy
	std::cout << "Type test " << firstType << std::endl;

	MyUniquePtr<int> ptr1;
	*(ptr1.get()) = 20;
	std::cout << "MyUniquePtr test " << *ptr1 << std::endl;
	*ptr1 = 30;
	std::cout << "MyUniquePtr test " << *ptr1 << std::endl;

	std::unique_ptr<int> uniquePtr = std::make_unique<int>();
	*uniquePtr = 20;
	*(uniquePtr) = 30;

	return 0;
}