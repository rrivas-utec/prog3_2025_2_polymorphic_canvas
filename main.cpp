#include <iostream>
#include <memory>

#include "shape.h"
#include "circle.h"
#include "rectangle.h"

void objeto_polimorfico() {
    Shape* shape = new Circle(10); // Shape se comporta como circulo
    std::cout << shape->area() << std::endl; // 314.159...
    delete shape;
    shape = new Rectangle(20, 20);  // Se comporta como rectangulo
    std::cout << shape->area() << std::endl; // 400
    delete shape;
}

void objeto_polimorfico_unique_smart() {
    std::unique_ptr<Shape> shape = std::make_unique<Circle>(10);
    std::cout << shape->area() << std::endl; // 314.159...
    shape = std::make_unique<Rectangle>(20, 20);
    std::cout << shape->area() << std::endl; // 400
    const auto shape2 = std::move(shape);
    // std::cout << shape->area() << std::endl; // 400 // Dangling point
    std::cout << shape2->area() << std::endl; // 400
}

void objeto_polimorfico_shared_smart() {
    std::shared_ptr<Shape> shape = std::make_shared<Circle>(10);
    std::cout << shape->area() << std::endl; // 314.159...
    shape = std::make_shared<Rectangle>(20, 20);
    std::cout << shape->area() << std::endl; // 400
    const auto shape2 = shape;
    std::cout << shape->area() << std::endl; // 400
    std::cout << shape2->area() << std::endl; // 400
}

int main() {
    // objeto_polimorfico();
    // objeto_polimorfico_unique_smart();
    objeto_polimorfico_shared_smart();
    return 0;
}
