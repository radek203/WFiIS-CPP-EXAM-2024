//
// Created by Radek on 05.12.2023.
//

#include "Square.h"
#include "iostream"

void Square::setA(float a) {
    this->a = a;
    this->area = a*a;
    this->circumference = 4*a;
}