#include <iostream>
using namespace std;

int gcd(int a, int b)
// i decided to use classic math method of Euclid: a > b > c > d > ... > r > 0 where r is our GCD
{
    // 0 - first of all we have to ensure that a > b and a is on the first place
    if (a < b)
    {
        int tmp; // there is a way to exchange values without additional variable - with XOR
        tmp = a;
        a = b;
        b = tmp;
    }
    // 1 - try to reduce complexity
    if (a % b == 0)
    {
        return b;
    }
    // 2 - if not reduced - launch next attempt
    return gcd(b, a % b);
}

int main()
{
    cout << "enter any integer number: ";
    int a, b;
    cin >> a >> b;

    cout << "greatest common divisor for given numbers is: " << gcd(a, b) << endl;
    return 0;
}