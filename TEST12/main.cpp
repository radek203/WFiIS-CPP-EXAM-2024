#include <iostream>

struct A {
	static int i;
	int *arr;

	~A() {
		delete arr;
	}

	A() {
		std::cout << "CONS" << std::endl;
		arr = new int[10];
		for (int i = 0; i < 10; i++) {
			arr[i] = 0;
		}
	}

	void check() const {
		i++;
		arr[5] = 20;

		//arr = new int[20];
	}

	void print() const {
		for (int i = 0; i < 10; i++) {
			std::cout << arr[i];
		}
		std::cout << i << std::endl;
	}
};

int A::i = 0;

int main() {

	A a;
	a.check();
	a.print();


	int c = 10;
	try {
		c++;
		throw std::bad_exception();
	} catch (const std::exception &e) {
		c++;
		std::cout << " c: " << c << " " << e.what() << std::endl;
	}
	std::cout << " c: " << c << std::endl;


	auto f = [=](int &i) mutable {
		i++;
		i++;

		//tu jeszcze nie widzi zmian wynikajacych z i
		c++;

		std::cout << " c: " << c << std::endl;
	};

	f(c);
	std::cout << " c: " << c << std::endl;



	return 0;
}