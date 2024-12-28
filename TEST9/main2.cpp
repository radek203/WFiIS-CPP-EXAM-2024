#include <iostream>
#include <memory>

//Tutaj sterujemy tez parametrem domyslnym dla Trait<Container<T, size>>
template<typename T, int size = 10>
struct Container {
	T val[size];
};

template<typename T>
struct Trait {
	static inline int num = 1;
};

template<typename T, int size>
struct Trait<Container<T, size>> {
	static inline int num = 2;
};

template<>
struct Trait<int> {
	static inline int num = 3;
};

int main() {
	Trait<float> t1;
	//t1.num++;
	Trait<float>::num++;
	std::cout << Trait<float>::num << std::endl;
	std::cout << Trait<int>::num << std::endl;

	Trait<Container<int>>::num = 100;
	std::cout << Trait<Container<int>>::num << std::endl;
	std::cout << Trait<Container<int, 10>>::num << std::endl;
	std::cout << Trait<Container<int, 20>>::num << std::endl;

	std::unique_ptr<Trait<float>> p1 = std::make_unique<Trait<float>>();
	//std::shared_ptr<Base> p = std::make_shared<Derived>();

	// (*p1) - normalnie wartosc
	std::cout << " TEST UP " << (*p1).num << std::endl;
	// p1-> lub p1.get()->     - to to samo
	std::cout << " TEST UP " << p1->num << std::endl;

	return 0;
}