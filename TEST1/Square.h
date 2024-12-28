//
// Created by Radek on 05.12.2023.
//

#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"


class Square : public Shape {

    float a;
    float area;
    float circumference;

public:
    void setA(float a);
    friend void PrintResults(Square square);

};



#endif //SQUARE_H
