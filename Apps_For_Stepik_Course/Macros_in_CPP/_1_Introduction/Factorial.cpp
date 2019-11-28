#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    cout << "enter any positive number: ";
    int n;
    cin >> n;
    cout << "factorial for " << n << " is " << factorial(n) << endl;
    return 0;
}