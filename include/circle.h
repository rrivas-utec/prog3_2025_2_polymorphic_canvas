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

    [[nodiscard]] double area() const override;
    void scale(double f) override;

    [[nodiscard]] Shape* clone() const override;
};

#endif //CIRCLE_H
