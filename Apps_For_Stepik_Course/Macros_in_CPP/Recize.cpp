#include <iostream>
using namespace std;

char *resize(const char *str, unsigned size, unsigned new_size)
{
    char *newRegion = new char[new_size];

    unsigned limit = size < new_size ? size : new_size;
    for (unsigned i = 0; i < limit; i++)
        newRegion[i] = str[i];

    delete[] str;

    return newRegion;
}

int main()
{
    char *before = new char[8];
    before[0] = 'p';
    before[1] = 'l';
    cout << "innitial string: " << before << endl;
    cout << "enter new size of the string - any integer: ";
    int newSize;
    cin >> newSize;
    char *after = resize(before, 8, newSize);
    cout << "result: " << after << endl;
    delete[] after;
    return 0;
}