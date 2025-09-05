//
// Created by rrivas on 4/09/2025.
//

#include "circle.h"
#include <numbers>

Circle::Circle(const double radius): radius(radius) {}

double Circle::area() {
    return std::numbers::pi * radius * radius;
}

void Circle::scale(double f) {
    radius *= f;
}

Shape * Circle::clone() {
    return new Circle(*this);
}
