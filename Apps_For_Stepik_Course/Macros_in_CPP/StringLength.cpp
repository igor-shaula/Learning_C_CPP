#include <iostream>
using namespace std;

// would be nice to write tests for this function
unsigned strlen(const char *str)
{
    unsigned length = 0;
    for (; *str != '\0'; str++)
        length++;
    return length;
}

int main()
{
    // cout << "enter a string to evaluate its length:\n";
    char str[] = "test-string"; // length is 11
    cout << strlen(str) << endl;

    return 0;
}