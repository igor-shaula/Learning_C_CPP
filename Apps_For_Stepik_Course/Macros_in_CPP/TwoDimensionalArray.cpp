#include <iostream>
using namespace std;

int **create2dArray1(size_t a, size_t b)
{
    int **array = new int *[a];
    for (size_t i = 0; i != a; i++)
        array[i] = new int[b];
    return array;
}

// void free2dArray(int **array, size_t a, size_t b)
void free2dArray(int **array, size_t a) // we don't need second dimension
{
    for (size_t i = 0; i != a; i++)
        delete[] array[i];
    delete[] array;
}

int main()
{
    return 0;
}