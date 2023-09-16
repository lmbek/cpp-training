#include <iostream>
#include <cmath>

int main() {
    double radius;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    if (radius < 0) {
        std::cout << "Error: Radius cannot be negative.";
        return 1;
    }

    double area = M_PI * std::pow(radius, 2);

    std::cout << "Area of the circle with radius " << radius << " = " << area;

    return 0;
}
