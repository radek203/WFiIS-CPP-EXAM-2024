#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void Fun1(T &val)
{
	std::cout << val << " ";
}

struct Test {
	template<typename T>
	void operator()(T d) {
		std::cout << d << " ";
	}
};

int main(){
	std::vector c = {1,2,3,4,5,6,7};                                // WERSJA 1
	// std::vector c = {1.6, 2.6, 3.6, 4.6, 5.6, 6.6, 7.6};        // WERSJA 2

	std::cout << "c: ";
	std::for_each(std::begin(c), std::end(c), []<typename T>(T &v) {
		std::cout << v << " ";
	});
	std::for_each(std::begin(c), std::end(c), Fun1<decltype(c[0])>);
	std::for_each(std::begin(c), std::end(c), Test());

	std::cout << "\nc wieksze od 3.5: ";
	std::for_each(std::begin(c), std::end(c), [](auto &v) {
		if (v > 3.5) {
			std::cout << v << " ";
		}
	});

	std::cout << "\nc posortowane: ";
	std::sort(std::begin(c), std::end(c), [](auto &v1, auto &v2) {
		return v2 < v1;
	});
	std::for_each(std::begin(c), std::end(c), [](auto &v) {
		std::cout << "[" << v << "] ";
	});

	std::cout << "\nc dodane 'x': ";
	decltype(*std::begin(c)) x = *std::begin(c);

	std::for_each(std::begin(c), std::end(c), [](auto v) {});
	std::for_each(std::begin(c), std::end(c), [x](auto v) { std::cout << v + x << ", "; });

	auto f = [&x](int a) {
		return x += a;
	};
	std::cout << "\nx: " << x << " ";
	std::cout << "f: " << f(6) << " ";
	std::cout << "x: " << x << std::endl;
}
/*    WERSJA 1
c: 1 2 3 4 5 6 7
c wieksze od 3.5: 4 5 6 7
c posortowane: [7] [6] [5] [4] [3] [2] [1]
c dodane 'x': 14, 13, 12, 11, 10, 9, 8
x: 7 f: 13 x: 13
*/

/*    WERSJA 2
c: 1.6 2.6 3.6 4.6 5.6 6.6 7.6
c wieksze od 3.5: 3.6 4.6 5.6 6.6 7.6
c posortowane: [7.6] [6.6] [5.6] [4.6] [3.6] [2.6] [1.6]
c dodane 'x': 15.2, 14.2, 13.2, 12.2, 11.2, 10.2, 9.2
x: 7.6 f: 13.6 x: 13.6
*/