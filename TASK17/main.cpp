#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

struct A {
	static int m_val;

	void operator()(int &i) {
		i = m_val;
		m_val--;
	}
};

int A::m_val = -1;

using namespace std;

/*
template<typename T>
void for_each(T begin, T end, const A &a) {
	for (auto p = begin; p != end; ++p) {
		(*p) = a.m_val;

		a.m_val--;
	}
}
 */

int main() {
	list<int> coll(11);
	for_each( std::begin(coll), std::end(coll), A());
	copy( coll.begin(), coll.end(), std::ostream_iterator<int>(std::cout,"; "));
	return 0;
}
// -1; -2; -3; -4; -5; -6; -7; -8; -9; -10; -11;