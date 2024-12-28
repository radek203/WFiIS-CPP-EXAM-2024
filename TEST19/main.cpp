#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <iterator>
#include <cstring>

template<typename T>
void Fun(const T &vec) {
	std::cout << *vec.begin() << " <- First "; //initializer list nie ma operatora [], tak samo samo list
}

void Fun2(const std::vector<int> &vec) {
	std::cout << vec[0] << " <- First ";
}

struct Data {
	int id;
	double value;
};

int main() {

	std::vector<int> vec = {1, 2, 3, 4};

	std::array<int, 4> arr = {1, 2, 3, 4};
	Fun(vec);
	Fun2(vec);

	Fun(arr);
	//Fun2(arr); //samo sie nie przerobi na vector...

	std::list<int> lst = {1, 2, 3, 4};
	Fun(lst);
	//int ii = lst[0];
	//Fun2(lst);

	std::deque<int> deq = {1, 2, 3, 4};
	Fun(deq);
	//Fun2(deq);

	int i1 = 1;
	int i2 = 2;
	int i3 = 3;
	int i4 = 4;

	std::initializer_list<int> l = {i1, i2, i3, i4};
	Fun(l);
	Fun2(l);

	auto vec2 = {&i1, &i2, &i3, &i4};

	std::for_each(vec.begin(), vec.end(), [](auto &v) {
		std::cout << v << " ";
	});

	std::for_each(vec2.begin(), vec2.end(), [](auto &v) {
		std::cout << *v << " ";
	});

	std::copy( vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout,"; "));

	//std::sort(vec.begin(), vec.end(), comparator);
	//int num = std::count_if(vec.begin(), vec.end(), std::bind(std::greater<int>(), std::placeholders::_1, 8));
	//employees.erase(std::remove_if(vec.begin(), vec.end(), predicate), vec.end());
	//vec.erase(vec.begin() + 2);
	//auto b = std::find_if(vec.begin(), vec.end(), [&](const Book &b) { return b.title == _title; });
	//    if (b == vec.end()) {
	//        return nullptr;
	//    }
	//auto it = std::find(vec.begin(), vec.end(), 20);

	Data d1{1, 3};
	Data d2{};
	std::memcpy(&d2, &d1, sizeof d1);
	std::cout << std::endl << d2.value << " " << d2.id;

	return 0;
}