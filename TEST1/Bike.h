//
// Created by Radek on 05.12.2023.
//

#ifndef BIKE_H
#define BIKE_H
#include <iostream>
#include <vector>

class Bike {
    std::string name;
    bool riding;
    std::vector<int> vec;

public:
    Bike(const Bike &fBike);
    Bike() = delete;
    explicit Bike(std::string _name, std::initializer_list<int> values);
    std::string getName();

    void ride() = delete;
    explicit operator std::string() const;
};



#endif //BIKE_H
