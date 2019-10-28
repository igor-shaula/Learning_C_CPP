#include <iostream>
using namespace std;

double const pi = 3.1416;

unsigned const secondsInDay = 24 * 60 * 60;

unsigned const daysInAllMonths[12] = {31, 28, 31, 30, 331, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    unsigned *february = (unsigned *)&daysInAllMonths[1]; // in fact here we attempt to cast pointers: const unsigned* -> unsigned*
    *february = 42;                                       // this could be possible but const before array definition prevents this
    cout << *february << endl;
    return 0;
}