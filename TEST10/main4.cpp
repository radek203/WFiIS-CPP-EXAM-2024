#include <iostream>
#include <cassert>

//Obliczana w czasie kompilacji
constexpr int a = 5*4*3*2;

typedef const int my_def;
using my_type = const int;
my_type bb = 20;
my_def cc = 30;

struct MyStruct {
	char a;
	int b;
	std::string c;
};

struct alignas(16) MyAlignedStruct {
	char a;
	int b;
	std::string c;
};

//noexcept - ze funkcja nie rzuca wyjatkow
void print() noexcept {

}

//Nie obiecuje ze nie bedzie nic rzucac
void print2() noexcept(false) {

}

/*
void print3() throw(int, double) {

}
 */

enum class Enum1 {
	HIGH,
	LOW
};

/*
template<typename T1, typename T2>
auto test(T1 t1, T2 t2) -> decltype(t1 + t2) {
	std::cout << "TEST test" << std::endl;
	return (t1 + t2);
}
 */

//Teraz nie trzeba juz decltype
template<typename T1, typename T2>
auto test(T1 t1, T2 t2) {
	std::cout << "TEST test" << std::endl;
	return (t1 + t2);
}

struct s_default {
	s_default() = default;
};

struct s_no_default {
	s_no_default() = delete;
};

int main() {

	int i = 20;
	double d = 21.37;
	decltype(i + d) x = 9.5;

	auto a = 1 + 2.1;

	std::cout << alignof(char) << " " << alignof(int) << " " << alignof(std::string) << " " << alignof(MyStruct) << std::endl;

	std::cout << alignof(char) << " " << alignof(int) << " " << alignof(std::string) << " " << alignof(MyAlignedStruct) << std::endl;

	void *dd = &i;

	//  static_assert - podczas kompilacji programu
	//static_assert(sizeof(dd) == 4, "Bledny rozmiar");

	static_assert(std::is_default_constructible<s_default>::value, "Data Structure requires default-constructible elements");

	constexpr int xd = 7;
	static_assert(xd == 7, "Test");

	//static_assert(std::is_default_constructible<s_no_default>::value, "Data Structure requires default-constructible elements");

	// assert - dynamiczna - podczas wykonywania programu
	assert(i == 20);

	std::cout << "Funkcja print rzuca bledy ? : " << (noexcept(print()) ? "Nie" : "Tak") << std::endl;

	std::cout << " " << bb << " " << cc << " " << static_cast<int>(Enum1::HIGH) << std::endl;

	int (*fun)(int,int) = test<int>;
	std::cout << " TEST " << fun(10, 20) << std::endl;

	return 0;
}