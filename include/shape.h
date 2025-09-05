//
// Created by rrivas on 4/09/2025.
//

#ifndef SHAPE_H
#define SHAPE_H

struct Shape {
    virtual double area() = 0;
    virtual void scale(double f) = 0;
    virtual ~Shape() = default;
    virtual Shape *clone() = 0;
};

#endif //SHAPE_H
