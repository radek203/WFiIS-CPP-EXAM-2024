//
// Created by Radek on 05.12.2023.
//

#include "Car.h"
#include <iostream>
#include <utility>
using namespace std;

Car::Car(): name("EMPTY"), riding(false) {

}

Car::Car(string _name) : Car() {
    name = move(_name);
}

string Car::getName() {
    return name;
}