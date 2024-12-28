#include <iostream>

struct Obj {
	virtual ~Obj() = default;
	virtual void Draw() const = 0;
};

template<typename T>
struct Box : Obj {
	T val;

	virtual ~Box() = default;

	explicit Box(const T &_val) : val(_val) {

	}

	void Draw() const override {
		std::cout << __PRETTY_FUNCTION__ << " --> " << val << std::endl;
	}

	operator T() {
		return val;
	}
};

template<typename T>
struct Box<Box<T>> : Obj {
	Box<T> val;

	virtual ~Box() = default;

	Box(const T &_val) : val(Box<T>(_val)) {

	}

	operator Box<T>() {
		return val;
	}

	void Draw() const override {
		std::cout << __PRETTY_FUNCTION__ << " --> " << val.val << std::endl;
	}

	operator T() {
		return val;
	}
};

int main()
{
	Box<int> b_i {3};
	Obj& r_1 = b_i;
	r_1.Draw();
	int i = b_i;
	Box<double> b_d {3.4} ;
	Obj& r_2 = b_d;
	r_2.Draw();
	double d = b_d;
	Box<Box<int>> bb_i {3} ;
	const Obj& r_3 = bb_i;
	r_3.Draw();
	Box<int> br_i = bb_i;
	Box<Box<double>> bb_d {3.4} ;
	const Obj& r_4 = bb_d;
	r_4.Draw();
	Box<double> b_a = bb_d;

// Box<int> _ = 3; Odkomentowanie powoduje blad kompilacji

}
// struct Box<int>::Draw() --> 3
// struct Box<double>::Draw() --> 3.4
// struct Box<Box<int>>::Draw() --> 3
// struct Box<Box<double>>::Draw() --> 3.4