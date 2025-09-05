//
// Created by rrivas on 4/09/2025.
//

#include "rectangle.h"

Rectangle::Rectangle(const double height, const double width): height(height), width(width) {}

double Rectangle::area() {
    return width * height;
}

void Rectangle::scale(const double f) {
    width *= f;
    height *= f;
}

Shape * Rectangle::clone() {
    return new Rectangle(*this);
}
