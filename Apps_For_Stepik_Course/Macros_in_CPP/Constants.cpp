#include <iostream>
using namespace std;

double const pi = 3.1416;

unsigned const secondsInDay = 24 * 60 * 60;

unsigned const daysInAllMonths[12] = {31, 28, 31, 30, 331, 30, 31, 31, 30, 31, 30, 31};

void testEverything()
{
    unsigned *february = (unsigned *)&daysInAllMonths[1]; // in fact here we attempt to cast pointers: const unsigned* -> unsigned*
    *february = 42;                                       // this could be possible but const before array definition prevents this
    cout << *february << endl;

    int a = 10;

    // pointer to constant:
    const int *p1 = &a; // int is constant - not pointer to this int
    int const *p2 = &a; // the same as before
    // *p1 = 0; // this will break - as we're trying to change constant
    p2 = 0; // this will work as pointer itself is not a constant

    // constant pointer:
    int *const p3 = &a;
    *p3 = 30; // this works because value a is not constant here
    // p3 = 0; // impossible to change constant pointer

    // constant pointer to constant:
    int const *const p4 = &a;
    // *p4 = 30; // cannot change constant under pointer
    // p4 = 30; // cannot change constant pointer itself
}

int main()
{
    testEverything();
    return 0;
}