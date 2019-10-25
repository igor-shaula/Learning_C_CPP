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

int main()
{
    return 0;
}