#include <iostream>

using namespace std;

void reverseInAndOut()
{
    unsigned n;
    cin >> n;
    if (n == 0)
    {
        return;
    }
    reverseInAndOut();
    cout << n << ' ';
}

int main()
{
    reverseInAndOut();
    return 0;
}