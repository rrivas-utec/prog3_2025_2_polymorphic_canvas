//
// Created by rrivas on 4/09/2025.
//

#ifndef CANVAS_H
#define CANVAS_H

#include <memory>
#include <vector>
#include "shape.h"

class Canvas {
    std::vector<std::unique_ptr<Shape>> shapes;
public:
    Canvas() = default;
    Canvas(const Canvas & other);
    Canvas(Canvas && other) noexcept;
    Canvas & operator=(const Canvas & other);
    Canvas & operator=(Canvas && other) noexcept;
    void add_shape(const Shape& shape);

    // Declaracion de la relacion de friend
    friend std::ostream & operator<<(std::ostream & os, const Canvas & c);
};

// Declaracion de la sobrecarga del operador << como funcion
std::ostream & operator<<(std::ostream & os, const Canvas & c);

#endif //CANVAS_H
