#include <iostream>
#include <vector>

namespace OOP {

	template<typename T>
	class Array {
		std::vector<T> values = {};
	public:
		typedef T value_type;

		Array(int i = 0) {

		}

		Array &insert(T val) {
			values.push_back(val);

			return *this;
		}

		Array &operator%(T val) {
			values.push_back(val);
			return *this;
		}

		T &operator[](int index) {
			return values[index];
		}

		unsigned int operator~() {
			return values.size();
		}

	};
}

int main()
{
	typedef ::OOP::Array<int> type;
	type a(rand() % 100 + 10); // nie trzeba seedować żeby program się wykonał

	a.insert('#' - 1).insert('P') % type::value_type('O') % ('-') % ('E') % ('G') % ('Z') % ('1');

	++a[0];
	for (unsigned i = 0; i != ~a; i++){
		std::cout << static_cast<char>(a[i]) << (i + 1 != ~a ? '_' : '\n');
	}
}
//#_P_O_-_E_G_Z_1