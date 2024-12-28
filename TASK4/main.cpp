#include <iostream>
#include <array>
#include <memory>

template<typename T>
void my_print_el(const T &p) {
	std::cout << p;
}

template<typename T>
void my_print(const T &a, const std::string &_sep = ";", const std::string &_arr = "") {
	my_print_el("[");
	for (auto &p : a) {
		my_print_el(*p);
		my_print_el(_sep);
	}
	my_print_el("]");
	my_print_el(_arr);
}

template<typename T>
void my_swap(T &ptr1, T &ptr2) {
	T copy = std::move(ptr1);
	ptr1 = std::move(ptr2);
	ptr2 = std::move(copy);
}

int main()
{
	std::array<std::unique_ptr<int>,2> a = {
			std::unique_ptr<int>(new int {1}),
			std::unique_ptr<int>(new int {2})
	};

	my_print_el("----------------\n");
	my_print(a,";"," -> ");
	my_swap(a[0],a[1]);
	my_print(a,";"," -> ");
	my_swap(*a[0],*a[1]);
	my_print(a);
	my_print_el("\n----------------");
}
//[1;2;] -> [2;1;] -> [1;2;]