#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n < 2)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    cout << "enter positive number: ";
    int n;
    cin >> n;
    cout << "Fibonacci number for " << n << " is " << fibonacci(n) << endl;
    return 0;
}