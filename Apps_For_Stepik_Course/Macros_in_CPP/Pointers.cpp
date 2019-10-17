#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    // 1 - swap
    cout << "please enter two numbers: ";
    int a, b;
    cin >> a >> b;
    swap(&a, &b);
    cout << "numbers in reverse order: " << a << ' ' << b << endl;
    return 0;
}