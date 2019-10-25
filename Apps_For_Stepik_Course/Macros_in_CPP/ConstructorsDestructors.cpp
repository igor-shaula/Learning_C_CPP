#include <iostream>
using namespace std;

// classic approach for constructors declaration:
struct Point
{
    double x, y;
    Point()
    {
        x = y = 0;
    }
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};

// using initialization lists in constructors:
struct PointIL
{
    double x, y;
    PointIL() : x(0), y(0) {}
    PointIL(double x, double y) : x(x), y(y) {}
};

// using default values in constructor:
struct PointDV
{
    double x, y;
    PointDV(double x = 0, double y = 0) {}
};

void useAllStructs()
{
    Point p0 = Point();
    Point p2 = Point(1.2, 3.4);
    PointIL pil2 = PointIL(1.2, 3.4);
    PointDV pdv0 = PointDV();
    PointDV pdv1 = PointDV(1.2);
    PointDV pdv2 = PointDV(1.2, 3.4);
    PointDV pdv0 = PointDV(5, 6);
}

int main()
{
    useAllStructs();
    return 0;
}