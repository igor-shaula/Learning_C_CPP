#include <iostream>
using namespace std;

#define MAX(x, y, r) (r = ((x) > (y)) ? (x) : (y))

int main()
{
    int a = 1, b = 2, c;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl;
    cout << "must be 2:" << MAX(a, b, c) << endl;
    a = 1;
    b = 2;
    cout << "must be 2:" << MAX(++a, b, c) << endl;
    a = 1;
    b = 2;
    cout << "must be 3:" << MAX(a, ++b, c) << endl;
    a = 1;
    b = 2;
    cout << "must be 3:" << MAX(++a, ++b, c) << endl;
    a = 1;
    b = 2;
    cout << "must be 2:" << MAX(a++, b, c) << endl;
    a = 1;
    b = 2;
    cout << "must be 3:" << MAX(a, b++, c) << endl;
    a = 1;
    b = 2;
    cout << "must be 3:" << MAX(a++, b++, c) << endl;
    return 0;
}