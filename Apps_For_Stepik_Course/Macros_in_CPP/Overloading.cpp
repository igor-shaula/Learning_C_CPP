#include <iostream>
using namespace std;

double f(double d) { return d * d; }

int f(int i) { return i * i; }

struct Vector2d
{
    double x, y;
    Vector2d(double x, double y) : x(x), y(y) {}

    Vector2d mult(double d) const { return Vector2d(x * d, y * d); }

    double mult(Vector2d const &p) const { return x * p.x, y * p.y; }
};

int main()
{
    // primitives:
    int a = f(4);       // f(int)
    double b = f(3.14); // f(double)
    double c = f(5);    // f(int) - and result of f(...) is casted from int to double
    int d = f(b);       // f(double) - remember that 'b' is double - and result is shrinked to int
    float e = f(2.71f); // f(double) - at first 2.71f is casted to double, than result - back to float

    // structures:
    Vector2d p(1, 2);
    Vector2d q = p.mult(10); // returns Vector2d(10, 20) & copies created object to 'q' - copying constructor works
    double r = p.mult(q);    // overloaded method works this time

    return 0;
}