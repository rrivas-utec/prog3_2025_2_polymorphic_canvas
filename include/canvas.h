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
};

#endif //CANVAS_H
