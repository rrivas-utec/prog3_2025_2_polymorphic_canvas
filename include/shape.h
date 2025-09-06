//
// Created by rrivas on 4/09/2025.
//

#ifndef SHAPE_H
#define SHAPE_H

struct Shape {
    [[nodiscard]] virtual double area() const = 0;
    virtual void scale(double f) = 0;
    virtual ~Shape() = default;
    [[nodiscard]] virtual Shape *clone() const = 0;   // Si creo un objeto constante este metodo
                                        // esta disponible
};

#endif //SHAPE_H
