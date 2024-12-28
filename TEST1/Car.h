//
// Created by Radek on 05.12.2023.
//

#ifndef CAR_H
#define CAR_H
#include <iostream>

class Car {
    std::string name;
    bool riding;

public:
    explicit Car();
    explicit Car(std::string _name);
    std::string getName();
};



#endif //CAR_H
