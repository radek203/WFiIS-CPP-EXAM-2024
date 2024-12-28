#include <functional>
#include <iostream>
#include <memory>

#include "Car.h"
#include "Bike.h"
#include "Square.h"

void test_function(int i) {
    std::cout << std::endl << "Number: " << i << std::endl;
}

//Nasza funkcja jest friend, możemy to tak wykonać
void PrintResults(Square square) {
    std::cout << "Area: " << square.area << std::endl;
    std::cout << "Circumference: " << square.circumference << std::endl;
}

class Day {
    char *dayName;
    int dayId;

    ~Day() {
        dayName = nullptr;
    }

    Day(const Day &day) {
        dayName = day.dayName;
        dayId = day.dayId;
    }

    Day& operator=(const Day &day) noexcept {
        if (this != &day) {
            delete []dayName;

            dayName = day.dayName;
            dayId = day.dayId;
        }

        return *this;
    }

    Day(Day &&day) noexcept {
        dayName = day.dayName;
        dayId = day.dayId;

        day.dayName = nullptr;
        day.dayId = 0;
    }

    Day& operator=(Day &&day) noexcept {
        if (this != &day) {
            delete []dayName;
            dayName = day.dayName;
            dayId = day.dayId;

            day.dayName = nullptr;
            day.dayId = 0;
        }

        return *this;
    }
};

class Calculator {
    int x;
    int y;
public:
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int operator[](int i, int j) const {
        return i + j;
    }
    int operator()(int suma) {
        return suma + 1;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Calculator &calculator) {
        stream << 2137;
        return stream;
    }

    friend std::istream& operator>>(std::istream& is, Calculator &calculator) {
        is >> calculator.x >> calculator.y;
        return is;
    }

    Calculator() {

    }

    Calculator(int x, int y) : x(x), y(y) {

    }
};

class CustomArr {
    int *arr;
public:
    CustomArr(int x1, int x2, int x3) {
        arr = new int[3];
        arr[0] = x1;
        arr[1] = x2;
        arr[2] = x3;
    }

    std::string Print() {
        return "X1: " + std::to_string(arr[0]) + " X2: " + std::to_string(arr[1]) + " X3: " + std::to_string(arr[2]);
    }
};

int mainTEST1()
{
    Calculator calc;
    int suma = calc[10, 4];
    std::cout << "Suma: " << suma << std::endl;
    int suma2 = calc(suma);
    std::cout << "Suma2: " << suma2 << " X: " << calc << std::endl;

    std::cout << "Podaj liczbe: " << std::endl;
    int number;
    std::cin >> number;

    std::cout << "Liczba: " << number << std::endl;

    std::cout << "Podaj liczbe x i y: " << std::endl;
    Calculator calc2;
    std::cin >> calc2;
    std::cout << "Liczba x: " << calc2.getX() << " Liczba y: " << calc2.getY() << std::endl;

    std::unique_ptr<CustomArr> uniquePtr(new CustomArr(8, 4, 1));
    std::cout << uniquePtr->Print() << std::endl;

    std::unique_ptr<CustomArr> uniquePtr2(new CustomArr(8, 66, 12));
    std::cout << uniquePtr2->Print() << std::endl;

    uniquePtr2 = std::move(uniquePtr);
    //std::cout << uniquePtr->Print() << std::endl;
    std::cout << uniquePtr2->Print() << std::endl;

    std::string name{"BMW"};

    Car car1{name};
    Car *car2 = new Car{"Audi"};

    std::cout << "Hello, " << car1.getName() << " and " << car2->getName() << "!" << std::endl;

    //Bike bike //jak jest zdefiniowany inny konstruktor, lub defaultowy jest usuniety to nie zadziala
    Bike bike("BMX", {3, 8, 21, 2});
    //bike.ride(); //deleted
    Bike bike2 = bike;
    std::cout << "Bike name: " << bike.getName() << std::endl;
    std::cout << "Bike name: " << bike2.getName();

    std::invoke(test_function, 20);
    std::cout << std::endl << "Invoked result: " << std::invoke(Bike::getName, bike);

    const std::string bikeName = static_cast<std::string>(bike); //przez explicit nie możemy zrobić nie jawnej konwersji
    //bikeName = "XD"; //const - nie możemy przypisać
    std::cout << std::endl << "Bike name: " << bikeName << std::endl;

    const int simpleConstInt = 20;
    //simpleConstInt = 21;
    int nonConstSimpleInt = const_cast<int&>(simpleConstInt);
    nonConstSimpleInt = 30;
    std::cout << "Const int: " << simpleConstInt << " NonConst int: " << nonConstSimpleInt << std::endl;

    int i = 5;
    const int& rci = i;
    const_cast<int&>(rci) = 50; //rzutujemy na referencje do inta, pozbywamy sie const
    std::cout << "Const int: " << rci << " int: " << i << std::endl;


    int liczba = 43;
    int *wsk = &liczba;

    char *charWsk = reinterpret_cast<char*>(wsk); //rzutujemy na wskaznik innego typu
    std::cout << "Int: " << liczba << " Char: " << *charWsk << std::endl;

    Square square{};
    square.setA(5);
    square.getName();

    PrintResults(square);
    return 0;
}
