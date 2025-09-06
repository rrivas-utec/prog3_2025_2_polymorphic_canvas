//
// Created by rrivas on 4/09/2025.
//

#include "canvas.h"

#include <iostream>

Canvas::Canvas(const Canvas &other) {
    for (const auto &s : other.shapes) {
        shapes.emplace_back(s->clone());
    }
}

Canvas::Canvas(Canvas &&other) noexcept {
    shapes = std::move(other.shapes);
}

Canvas & Canvas::operator=(const Canvas &other) {
    if (this != &other) {
        shapes.clear();
        for (const auto &s : other.shapes) {
            shapes.emplace_back(s->clone());
        }
    }
    return *this;
}

Canvas & Canvas::operator=(Canvas &&other) noexcept {
    if (this != &other) {
        shapes = std::move(other.shapes);
    }
    return *this;
}

void Canvas::add_shape(const Shape &shape) {
    shapes.emplace_back(shape.clone());
}

std::ostream & operator<<(std::ostream &os, const Canvas &c) {
    for (const auto &s : c.shapes) {
        std::cout << s->area() << std::endl;
    }
    return os;
}
