#include <iostream>
#include <vector>
#include <algorithm>

template<typename Fun>
auto liftToVector(const Fun &f) {
	return [&] (std::vector<int> &vec) {
		for (auto &p : vec) {
			f(p);
		}

		return vec;
	};
}

void add2(int &v) {
	v += 2;
}

int main(){

	auto vadd2 = liftToVector(add2);
	std::vector<int> x = {0,9,4};
	auto v = vadd2(x);

	std::for_each(v.begin(), v.end(), [](const int n) {std::cout<< n << ' ';});

	return 0;
}
// 2 11 6