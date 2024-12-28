//
// Created by radek203 on 19.04.2024.
//
#include <iostream>
#include <vector>

class Vehicle {
public:
    virtual ~Vehicle() = 0;
};

Vehicle::~Vehicle() = default;

class Car : public Vehicle {
public:
    ~Car() override = default;
};

class Bike : public Vehicle {
public:
    ~Bike() override = default;
};

void someFunction(Vehicle &vehicle) {
    if (Car *veh1 = dynamic_cast<Car*>(&vehicle)) {
        std::cout << "Car" << std::endl;
    } else if (Bike *veh2 = dynamic_cast<Bike*>(&vehicle)) {
        std::cout << "Not a car" << std::endl;
    }
}

template<typename T>
auto getMax(T a, T b) -> T {
    return (a > b) ? a : b;
}

int main() {

    auto x = 5;
    auto y = 3.14;

    std::vector<int> vec = {1, 2, 3};
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        *it += 2;
        std::cout << *it << std::endl;
    }

    for (auto &elem : vec) {
        elem += 2;
    }

    for (const auto &elem : vec) {
        std::cout << elem << std::endl;
    }

    int z = 10;
    decltype(z) w;
    w = 20;

    decltype(z + y) v = 21.37;

    std::cout << w << " " << v << std::endl;

    //Vehicle veh;

    Car car;
    someFunction(car);

    Bike bike;
    someFunction(bike);

    auto add = [](int x, int y) -> double {
        return x + y;
    };

    auto getVectorElement = [](std::vector<int>& v, size_t idx) -> int& {
        return v[idx];
    };

    auto functionFactory = [](int arg)  {
        return [arg](double x) -> double { return x * arg; };
    };

    std::cout << add(2, 3) << std::endl;
    std::cout << functionFactory(5)(10) << std::endl;

    std::cout << getMax(10.0, 21.4) << std::endl;
    std::cout << getMax(10, 21) << std::endl;

	int m = 0;
	int n = 0;
	//wszystkie przez referencje, n przez wartosc i odrazu wywolujemy z argumentem 4
	[&, n] (int a) mutable { m = ++n + a; }(4);

	std::cout << m << " " << n << std::endl;

	//wszystkie przez wartosc
	[=] (int a) mutable { m = ++n + a; }(4);

	//jezeli sa przez wartosc to zeby moc je modyfikowac (tylko wewnatrz lambdy) musimy dodac mutable
	auto fun = [=] (int a) mutable {
		m = ++n + a;
	};
	fun(10);

	std::cout << m << " " << n << std::endl;

	/*
	std::for_each(vehicles.begin(), vehicles.end(), [&](auto *vehicle) {
		if (auto car = dynamic_cast<Car*>(vehicle)) {
			i += car->getMiejsc();
		}
	});


	auto fun = [&](auto *vehicle) {
		if (auto car = dynamic_cast<Car*>(vehicle)) {
			i += car->getMiejsc();
		}
	};
	for (auto vehicle : vehicles) {
		fun(vehicle);
	}

	 //Dodajemy z innego wektora na koniec pierwszego
	 found.insert(found.end(), f.begin(), f.end());


	void Company::sortEmployees(bool comparator(Employee &emp1, Employee &emp2)) {
		std::sort(employees.begin(), employees.end(), comparator);
	}

	void Company::removeEmployees(bool predicate(Employee &emp)) {
		//erase usuwa elementy z wektora od iteratora ktora podamy jako poczatkowy do koncowego
		//remove_if zwraca iterator na pierwszy element ktory zostal przesuniety na koniec (do usuniecia)
		employees.erase(std::remove_if(employees.begin(), employees.end(), predicate), employees.end());
	}
	 */

    return 0;
}
