#include <iostream>
using namespace std;

// 1
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 2
void fillArrayWithProportion(int *array, int size, int shift)
{
    for (int *p = array; p < array + size; ++p) // p is like i for iterating but we use pointers instead of values
    {
        *p = (p - array) + shift; // this formula is about getting the value to be written by the address p
    }
}
void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

// 3
int findMaxValue(int *array, int size)
{
    int max = *array;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}
int findMaxValue(int *array, int *next)
{
    int max = *array;
    for (; array != next; array++)
        if (*array > max)
            max = *array;
    return max;
}
int *findPMax(int *array, int *next)
{
    int *pmax = array;
    for (; array != next; array++)
        if (*array > *pmax)
            pmax = array;
    return pmax;
}
bool detectMax(int *array, int *next, int *result)
{
    if (array == next) // this means that given array is empty
        return false;
    *result = *array;
    for (; array != next; array++)
        if (*array > *result)
            *result = *array;
    return true;
}
bool detectMax(int *array, int *next, int **result)
{
    if (array == next)
        return false;
    *result = array;
    for (; array != next; array++)
        if (*array > **result)
            *result = array;
    return true;
}

// 4
bool contains(int *array, int size, int value)
{
    for (int i = 0; i != size; i++)
        if (array[i] == value) // classical access to array element - hides addition operation inside
            return true;
    return false;
}
bool contains(int *array, int *next, int value) // using address of the element right after array
{
    for (; array != next; array++)
        if (*array == value) // faster than previous form with array[i] <-> *(array + i) -> we do not add here
            return true;
    return false;
}

int main()
{
    // 1 - swapping values
    cout << "please enter two numbers: ";
    int a, b;
    cin >> a >> b;
    swap(&a, &b);
    cout << "numbers in reverse order: " << a << ' ' << b << endl;

    // 2 - filling array
    cout << "enter the dimension of an array: ";
    int size;
    cin >> size;
    int array[size];
    cout << "enter desired value of the first element: ";
    int firstValue;
    cin >> firstValue;
    fillArrayWithProportion(array, size, firstValue);
    printArray(array, size);

    // 3 - finding max element
    cout << "max value of this array is: " << findMaxValue(array, size) << endl;

    return 0;
}