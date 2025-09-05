//
// Created by rrivas on 4/09/2025.
//

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle final : public Shape {
    double radius = 0;
public:
    Circle() = default;
    explicit Circle(double radius);
    double area() override;
    void scale(double f) override;
    Shape* clone() override;
};

#endif //CIRCLE_H
