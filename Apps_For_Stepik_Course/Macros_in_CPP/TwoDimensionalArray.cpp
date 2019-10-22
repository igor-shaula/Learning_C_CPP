#include <iostream>
using namespace std;

int **create2dArray(size_t a, size_t b)
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

int **create2dArrayQuick(size_t a, size_t b)
{
    int **array = new int *[a];
    array[0] = new int[a * b];
    for (size_t i = 1; i != a; i++)
        array[i] = array[i - 1] + b; // here we're writing pointers to inner 1d arrays
}

// void free2dArrayQuick(int **array, size_t a, size_t b)
void free2dArrayQuick(int **array, size_t a, size_t b) // no need in passing dimensions
{
    delete[] array[0]; // cleaning all memory of a * b dimensions
    delete[] array;
}

int main()
{
    return 0;
}