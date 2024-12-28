#include <iostream>
#include <vector>
#include <functional>

struct FunVector
{
	std::vector<std::function<bool(int)>> functors;

	void add(const std::function<bool(int)> &fun) {
		functors.push_back(fun);
	}

	void remove(unsigned i) {
		if (i < functors.size()) {
			functors.erase(functors.begin() + i);
		}
	}

	void remove_all() {
		functors.clear();
	}

	void apply_all(int arg) {
		for (auto x: functors) {
			x(arg);
		}
	}
};

struct GreaterThan
{
	int x;

	GreaterThan(int X=0): x(X) {}

	bool operator() (int arg) {
		if (arg > x) {
			std::cout << arg << " is greater than " << x << std::endl;
			return true;
		}
		else {
			std::cout << arg << " is not greater than " << x << std::endl;
			return false;
		}
	}
};

struct Prime {
	bool operator() (int arg) {
		if (arg > 1) {
			for (int i=2; i < arg/2 + 1; i++) {
				if (arg%i == 0) {
					std::cout << arg << " is not prime" << std::endl;
					return false;
				}
			}

			std::cout << arg << " is prime" << std::endl;
			return true;
		}
		else {
			std::cout << arg << " is not prime" << std::endl;
			return false;
		}
	}
};

int main()
{
	FunVector fun_vector;

	GreaterThan test_1(20);
	GreaterThan test_2(10);
	Prime test_3;

	fun_vector.add(test_1);
	fun_vector.add(test_2);
	fun_vector.add(test_3);

	fun_vector.apply_all(11);
	fun_vector.remove(1);

	std::cout << std::endl;
	fun_vector.apply_all(11);

	return 0;
}

/*
11 is not greater than 20
11 is greater than 10
11 is prime

11 is not greater than 20
11 is prime
*/