#include <iostream>
#include <vector>

using std::endl;
using std::cout;

template<typename T>
struct vector {
	std::vector<T> vec;

	void push_back(T val) {
		vec.push_back(val);
	}

	template<typename T2>
	vector<T> &operator=(const vector<T2> &other) {
		return *this;
	}

	friend std::ostream &operator<<(std::ostream &os, const vector<T> &vec) {
		for (auto p = vec.vec.begin(); p != vec.vec.end(); ++p) {
			os << *p << " ";
		}
		return os;
	}
};

int main()
{
	vector<int> veci;
	vector<double> vecd;
	for(int i = 0;i<10;++i){

		veci.push_back(i);
		vecd.push_back(i);
	}
	vecd = veci;
	cout << veci << endl << vecd << endl;
}