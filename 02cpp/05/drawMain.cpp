#include "draw.hpp"

int main() {
    Circle circle;
    Square square;
    Triangle triangle;

    Drawable* shapes[] = { &circle, &square, &triangle };

    for (Drawable* shape : shapes) {
        shape->draw(); // Using polymorphism to draw different shapes
    }

    return 0;
}