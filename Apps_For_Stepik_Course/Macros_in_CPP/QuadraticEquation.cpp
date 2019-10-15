#include <iostream>
#include <cmath>

#define NRR "No real roots"

using namespace std;

int main()
{
    int a, b, c;

    cout << "enter coefficients (a, b, c) of quadratic equation (ax^2 + bx + c = 0): ";
    cin >> a >> b >> c;

    int d = b * b - 4 * a * c; // first of all we have to evaluate discriminant

    if (d < 0)
    {
        cout << NRR;
        return 0;
    }

    double x1 = (double)(-1 * b + sqrt(d)) / (2 * a);
    double x2 = (double)(-1 * b - sqrt(d)) / (2 * a);

    cout << x1 << ' ' << x2 << endl;

    return 0;
}