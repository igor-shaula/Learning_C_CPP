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

struct BaseFile
{
    void write(char const *s);
};
struct FormattedFile : BaseFile
{
    void write(int i);
    void write(double d);
    using BaseFile::write; // allows this method set from base class to be included to a list of overloaded methods
};

struct String
{
    String(char *c) : str(c) {}
    /* ... */
    char &at(size_t idx) { return str[idx]; }
    char at(size_t idx) const { return str[idx]; }
    /* ... */
    size_t size;
    char *str;
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

    // solving puzzle:
    String greet("Hello");
    char ch1 = greet.at(0);
    cout << ch1 << endl;

    String const const_greet("Hello, Const!");
    char const &ch2 = const_greet.at(0);
    cout << ch2 << endl;

    return 0;
}