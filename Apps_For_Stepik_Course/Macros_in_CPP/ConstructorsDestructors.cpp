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

// restricting of implicit initialization usage:
struct PointE
{
    double x, y;
    explicit PointE(double x = 0, double y = 0) {}
};

// nuances with default constructor:
struct PointDC
{
    double x, y;
    // no constructor at all here - but it will be generated
};
struct PointDCA
{
    double x, y;
    // default constructor will not be created as we have an alternative constructor
    PointDCA(double x, double y) : x(x), y(y) {}
};

void useAllStructs()
{
    Point p0 = Point();
    Point p0_ = {};
    // Point p1 = Point(1.2); // not possible
    // Point p1_ = 1.2; // not compilable - we have no constructors with only 1 argument
    Point p2 = Point(1.2, 3.4);
    Point p2_ = {1.2, 3.4}; // possible way

    PointIL pil0 = PointIL();
    PointIL pil0_ = {};
    // PointIL pil1 = PointIL(1.2); // not possible
    // PointIL pil1_ = 1.2; // same situation as we lack needed constructor
    PointIL pil2 = PointIL(1.2, 3.4);
    PointIL pil2_ = {1.2, 3.4};

    PointDV pdv0 = PointDV();
    PointDV pdv0_ = {};
    PointDV pdv1 = PointDV(1.2); // possible! - x is initialized
    PointDV pdv1_ = {1.2};       // this value goes into x field
    PointDV pdv2 = PointDV(1.2, 3.4);
    PointDV pdv2_ = {1.2, 3.4};

    PointE pe0 = PointE();
    // PointE pe0_ = {}; // now that form of initialization is forbidden
    PointE pe1 = PointE(1.2);
    // PointE pe1_ = {1.2};
    PointE pe2 = PointE(1.2, 3.4);
    // PointE pe2_ = {1.2, 3.4};

    PointDC pdc = PointDC();
    PointDC pdc_ = {};

    // PointDCA pdca0 = PointDCA(); // not possible - default constructor is absent here
    // PointDCA pdca0_ = {};        // not possible as well
    // PointDCA pdca1 = PointDCA(1.2); // not possible again - no constructor with 1 parameter
    // PointDCA pdca1_ = {1.2};        // not possible as we even have no default values in 2p constructor
    PointDCA pdca2 = PointDCA(1.2, 3.4); // only constructor with 2 parameters are required and compilable
    PointDCA pdca2_ = {1.2, 3.4};        // this form is also possible as we do not use "explicit" in constructor
}

int main()
{
    useAllStructs();
    return 0;
}