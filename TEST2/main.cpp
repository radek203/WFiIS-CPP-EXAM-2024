#include <iostream>
#include <functional>
#include <utility>

int factorial(int n) {
	int last = 1;
	for (int i = 1; i <= n; i++) {
		last *= i;
	}
	return last;
}

class Car {
public:
	std::string name;
	Car(std::string);
	void drive(float) const;
};

Car::Car(std::string _name) : name(std::move(_name)) {

}

void Car::drive(float f) const {
	std::cout << "Car " << name << " starts drive fuel: " << f << "l" << std::endl;
}



int main() {

	std::cout << factorial(6) << std::endl;

	std::function f_f = factorial;

	std::cout << f_f(10) << std::endl;

	std::function G([](int hexa) -> int& {
		static int i{hexa};
		return i;
	});

	std::cout << G(0x3A) << std::endl;


	std::function f_display_10 = [] { return factorial(10); };

	std::function f_display_11 = [] -> int { return factorial(11); };

	std::cout << f_display_10() << std::endl;
	std::cout << f_display_11() << std::endl;

	Car car("Audi");
	std::function<std::string(Car const&)> car_d = &Car::name;

	std::function<void(Car const&, float f)> car_dri = &Car::drive;

	std::function<void()> car_driv = std::bind(car_dri, car, 21.37);
	std::function<void()> car_dr = std::bind(&Car::drive, car, 21.37);

	std::cout << car_d(car) << std::endl;
	car_dr();


	return 0;
}