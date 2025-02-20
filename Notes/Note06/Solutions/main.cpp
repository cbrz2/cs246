#include "Polygon.h"

int main()
{
    dsn::RegularPolygon r(6,3);
    dsn::Square s(8);
    s.increment();
    r.increment();

    std::cout << r << " " << s << "\n";
    return 0;
}