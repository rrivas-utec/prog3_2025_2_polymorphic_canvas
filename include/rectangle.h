//
// Created by rrivas on 4/09/2025.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle final : public Shape {
    double height = 0;
    double width = 0;
public:
    Rectangle() = default;
    explicit Rectangle(double height, double width);

    [[nodiscard]] double area() const override;
    void scale(double f) override;

    [[nodiscard]] Shape* clone() const override;
};

#endif //RECTANGLE_H
