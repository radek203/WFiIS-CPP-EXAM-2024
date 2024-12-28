#include <iostream>
#include <future>
#include <vector>

int fun(int n) {
	int result = 0;
	for (int i = 0; i < n*n; i++) {
		for (int j = 0; j < n*n; j++) {
			for (int k = 0; k < n*n; k++) {

			}
		}
	}
	return result;
}

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
	return a + b;
}

template<typename T, typename U>
auto addd(T a, U b) {
	return a + b;
}

auto funn() -> int {
	return 10;
}

int main() {

	std::future<int> result1 = std::async(std::launch::async, [] { return fun(20); });
	std::future<int> result2 = std::async(std::launch::async, [] { return fun(30); });
	std::future<int> result3 = std::async(std::launch::async, fun, 10);
	std::future<int> result4 = std::async(std::launch::async, add<int, int>, 10, 20);

	std::cout << "Result: " << result1.get() << " Result: " << result2.get() << std::endl;

	auto f = [] (auto a, auto b) { return a + b; };
	std::cout << "Result: " << f(10, 2) << std::endl;
	std::cout << "Result: " << f(21, 0.37) << std::endl;

	std::cout << "Result: " << add(10, 2) << std::endl;
	std::cout << "Result: " << add(10, 19.20) << std::endl;
	std::cout << "Result: " << addd(10, 2) << std::endl;
	std::cout << "Result: " << addd(10, 19.20) << std::endl;

	std::cout << "Result: " << funn() << std::endl;

	using vec_int = std::vector<int>;
	vec_int vec = {1, 2, 3};

	for (auto it = vec.begin(); it != vec.end(); ++it) {
		*it += 2;
		std::cout << *it << std::endl;
	}



	return 0;
}