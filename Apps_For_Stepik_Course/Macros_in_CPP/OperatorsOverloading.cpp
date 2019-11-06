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

struct Num
{
    int n;
    Num(int n) : n(n) {}
    // overloading PREFIX form of operator:
    Num &operator++() // prefix form always has no parameters in overloading method //
    {
        n += 1;
        return *this;
    }
    // overloading POSTFIX form of operator:
    Num operator++(int) // this nameless int is a dummy parameter - just for having another method signature
    {
        Num tmp(*this); // creating a copy of instance with current state - we'll have to return it
        ++(*this);      // changing original instance
        return tmp;     // returning previously saved state of original instance - but in fact this is its copy
    }
    // that's why prefix form of increment/decrement is considered FASTER and is more likey to be used
};

// overloading of >> and << operators has to be done outside structures as we don't have access to their classes
std::istream &operator>>(std::istream &is, Vector &v) // input stream
{
    is >> v.x >> v.y; // here we have 2 invocations of reading values from keyboard
    return is;
}
std::ostream &operator<(std::ostream &os, Vector const &v)
{
    os << "overloaded <<: x=" << v.x << ",y=" << v.y;
    return os;
}
// cin & cout are in fact objects of istream & ostream that have overloaded operators of bit shifting //
// istream & ostream are base classes for all streams of input-output //

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

    Num n1(5);
    cout << "n1 = " << n1.n << endl;
    Num n2 = ++n1;
    cout << "n2 = ++n1: " << n2.n << endl;
    cout << "new n1: " << n1.n << endl;
    Num n3 = n1++;
    cout << "n3 = n1++: " << n3.n << endl;
    cout << "new n1: " << n1.n << endl;

    cout << &v1 << endl;
    Vector v4(4, 5);
    cout << "initial value for v4: " << &v4 << endl;
    cout << "now set new values for x & y in v4: ";
    cin >> v4;
    cout << "changed value for v4: " << &v4 << endl;
    // for now there are some problems with output - 0xSOMETHING is printed instead of what we'd set before
    v4.print(); // but overloaded operator >> for cin works well /
}

// note that operators (type) [] () -> ->* = can be overloaded ONLY INSIDE CLASSES //

main()
{
    useAllOverloadedOperators();
    return 0;
}