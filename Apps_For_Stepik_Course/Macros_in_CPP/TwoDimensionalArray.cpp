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

void fill2dArrayWithOneValue(int array[][5], size_t a, size_t b)
{
    for (size_t i = 0; i < a; i++)
        for (size_t j = 0; j < b; j++)
            *((int *)array + i * b + j) = 1; // the same as sArray[i][j] = 1;
}

int **create2dArrayOnStack(size_t a, size_t b)
{
    int **sArray = {}; // creating array in stack - not in dynamic memory
    // linear structure of this two-dimensional array in stack accepts the following:
    fill2dArrayWithOneValue((int(*)[5])sArray, a, b);
    return (int **)sArray;
}

// void print1dArray(int *array, size_t size)
void print1dArray(int array[], size_t size) // this declaration is the same as commented above
{
    for (size_t i = 0; i < size; i++)
        cout << array[i] << ' ';
    cout << endl;
}

void print2dArray(int array[][5], size_t a, size_t b) //
{
    for (size_t i = 0; i < a; i++)
    {
        for (size_t j = 0; j < b; j++)
            cout << array[i][j] << ' ';
        cout << endl;
    }
}

int main()
{
    size_t a = 3, b = 5;
    int array[3][5] = {
        {2, 2, 2, 2, 2},
        {3, 3, 3, 3, 3},
        {4, 4, 4, 4, 4}};
    print1dArray(*array, a);
    print2dArray(array, a, b);
    fill2dArrayWithOneValue(array, a, b);
    print2dArray(array, a, b);

    return 0;
}