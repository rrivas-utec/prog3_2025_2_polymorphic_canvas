#include <canvas.h>
#include <iostream>
#include <memory>

#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "canvas.h"

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

class Point {
    int x;
    int y;
public:
    Point(int x, int y) : x(x), y(y) {}
    int get_x() const { return x; }
    int get_y() const { return y; }   // metodo no esta disponible para objetos constantes
};

void generar_objeto_constante() {
    Point p1(5, 10);            // Objeto variable
    const Point p2(15, 30);     // Objeto constante
    std::cout << p1.get_x() << ", " << p1.get_y() << std::endl;
    std::cout << p2.get_x() << ", " << p2.get_y() << std::endl;
}

void generar_canvas() {
    Canvas c1;
    c1.add_shape(Circle(10));
    c1.add_shape(Rectangle(5, 10));

    Canvas c2 = c1;                 // copia

    c2.add_shape(Circle(20));
    // std::cout << c1 << std::endl;
    // std::cout << c2 << std::endl;

    Canvas c3 = c2;                 // copia
    Canvas c4 = std::move(c3);      // move
    // std::cout << "---" << std::endl;
    // std::cout << c3 << std::endl;
    // std::cout << "---" << std::endl;
    // std::cout << c4 << std::endl;
    // std::cout << "---" << std::endl;

    Canvas c5;                      // default
    c5 = c4;                        // asignacion copia
    c5.add_shape(Rectangle(10, 10));
    // std::cout << "---" << std::endl;
    // std::cout << c4 << std::endl;
    // std::cout << "---" << std::endl;
    // std::cout << c5 << std::endl;
    // std::cout << "---" << std::endl;

    Canvas c6 = c2;                 // copia
    Canvas c7;                      // default
    c7 = std::move(c6);             // asignacion move
    std::cout << "---" << std::endl;
    std::cout << c6 << std::endl;
    std::cout << "---" << std::endl;
    std::cout << c7 << std::endl;
    std::cout << "---" << std::endl;
}

int main() {
    // objeto_polimorfico();
    // objeto_polimorfico_unique_smart();
    // objeto_polimorfico_shared_smart();
    // generar_objeto_constante();
    // generar_canvas();
    return 0;
}
