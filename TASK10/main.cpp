#include <iostream>
#include <list>
#include <functional>

bool f1(int value) {
	return true;
}

bool f2(int value) {
	return value % 2 == 0;
}

struct f3 {
	int val;

	void edit(int &i) const {
		i += val;
	}
};

template<typename T>
void change(T begin, T end, f3 f) {
	for (auto p = begin; p != end; ++p) {
		f.edit(*p);
	}
}

template<typename T1>
void print_to_if(std::ostream &os, T1 begin, T1 end, const std::function<bool(int)> &f) {
	for (auto &p = begin; p != end; ++p) {
		if (f(*p)) {
			os << *p << " ";
		}
	}
	os << std::endl;
}


int main(){
	const auto cl = {1,2,3,4,5,6,7};

	print_to_if(std::cout<<"All: ", begin(cl), end(cl), f1);
	print_to_if(std::cout<<"All: ", begin(cl), end(cl), f2);

	int add_value{-1};
	std::list<int> cl2 = {7,6,5,4,3,2,1};
	change(begin(cl2), end(cl2), f3{add_value});
	print_to_if(std::cout << "All  ", begin(cl2), end(cl2), f1);
}
/*
All: 1 2 3 4 5 6 7
All: 2 4 6
All  6 5 4 3 2 1 0
*/