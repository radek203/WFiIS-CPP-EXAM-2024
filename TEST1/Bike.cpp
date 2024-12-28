//
// Created by Radek on 05.12.2023.
//

#include "Bike.h"
#include <iostream>
#include <utility>
#include <initializer_list>
using namespace std;

/*
Bike::Bike(): name("EMPTY"), riding(false) {

}
*/
Bike::Bike(const Bike &fBike) {
    name = fBike.name + "Copy";
    riding = fBike.riding;
    vec = fBike.vec;
}

Bike::Bike(string _name, initializer_list<int> values) {
    name = move(_name);
    riding = false;
    vec = values;
}

string Bike::getName() {
    int sum = 0;
    for (auto i = vec.begin(); i < vec.end(); i++) {
        sum += *i;
    }

    return name + to_string(sum);
}

Bike::operator std::string() const {
    return name;
}