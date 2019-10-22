#include <iostream>
using namespace std;

int **create2dArray1(size_t a, size_t b)
{
    int **array = new int *[a];
    for (size_t i = 0; i != a; i++)
        array[i] = new int[b];
    return array;
}

int main()
{
    return 0;
}