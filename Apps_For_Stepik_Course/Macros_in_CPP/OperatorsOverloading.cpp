#include <iostream>
using namespace std;

struct Vector
{
    int x, y;
    Vector(int x, int y) : x(x), y(y) {}
    void print()
    {
        cout << "x=" << x << ",y=" << y << endl;
    }

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
    Vector v(1, 2);
    cout << "initial v: ";
    v.print();
    Vector v1 = -v;
    cout << "v1 = -v: ";
    v1.print();
    Vector v2(3, 4);
    cout << "v2 initial: ";
    v2.print();
    cout << "v2 = v1 - v: ";
    v2 = v1 - v;
    v2.print();
    cout << "v2 *= 2: ";
    v2 *= 2;
    v2.print();
    cout << "v2[0]: " << v2[0] << endl;
    cout << "v2(2):" << v2(2) << endl;
    cout << "v2(3, 4):" << v2(3, 4) << endl;
}

// note that operators (type) [] () -> ->* = can be overloaded ONLY INSIDE CLASSES

int main()
{
    useAllOverloadedOperators();
    return 0;
}