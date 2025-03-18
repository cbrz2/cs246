#include "Polygon.h"

void Stats(const dsn::RegularPolygon& obj)
{
    std::cout << "Length: " << obj.length() << "\n";
    std::cout << "Sides: " << obj.sides() << "\n";
    std::cout << "Perimeter: " << obj.perimeter() << "\n";
    std::cout << "Area: " << obj.area() << "\n";
    std::cout << obj << "\n";
}

int main()
{
    dsn::Square s;
    dsn::EquilateralTriangle t;

    Stats(s);
    Stats(t);
    return 0;
}