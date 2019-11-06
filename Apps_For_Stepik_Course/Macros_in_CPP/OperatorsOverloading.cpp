#include <iostream>
using namespace std;

struct Vector
{
    int x, y;
    Vector(int x, int y) : x(x), y(y) {}

    // samples of overloading operators in methods - having implicit link to 'this' object //
    Vector operator-() const { return Vector(-x, -y); }
    Vector operator-(Vector const &p) const { return Vector(x - p.x, y - p.y); }
    Vector &operator*=(int n) // overloading operator *=
    {
        x *= n;
        y *= n;
        return *this;
    }
    int operator[](size_t i) const { return (i == 0) ? x : y; } // overloading operator []
    bool operator()(int i) const {}                             // now this operator will behave like a function
    bool operator()(int i1, int i2) {}                          // wil act like another function with 2 parameters
};

void useAllOverloadedOperators()
{
}

int main()
{
    useAllOverloadedOperators();
    return 0;
}