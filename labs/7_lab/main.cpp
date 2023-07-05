#include <iostream>
#include <shape.h>
#include <vector>
#include <string>
#include <cmath>

int main() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Circle("Red", 0, 0, 5.0));
    shapes.push_back(new Triangle("Blue", 1, 1, 3.0, 4.0, 5.0));
    shapes.push_back(new Rectangle("Green", 2, 2, 4.0, 6.0));

    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->getArea() << std::endl;
        delete shape;
    }

    shapes.clear();

    return 0;
}