#include <iostream>
using namespace std;

void leftShiftByOne(int array[], int size)
{
    int save = array[0];
    for (int i = 0; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    array[size - 1] = save;
}

void rightShiftByOne(int array[], int size)
{
    int save = array[size - 1];
    for (int i = size - 1; i > 0; i--)
    {
        array[i] = array[i - 1];
    }
    array[0] = save;
}

void rotate(int array[], unsigned size, int shift)
{
    shift = shift % (int)size; // if size remains unsigned - it affects possible negative values of shift
    cout << shift << endl;
    if (shift == 0)
    {
        return;
    }
    else if (shift > 0)
    {
        for (int i = 0; i < shift; i++)
        {
            leftShiftByOne(array, size);
        }
    }
    else // shift < 0
    {
        for (int i = 0; i > shift; i--)
        {
            rightShiftByOne(array, size);
        }
    }
}

void fillArrayWithSequence(int array[], unsigned size)
{
    for (int *p = array; p < array + size; p++)
    {
        *p = (p - array) + 1;
    }
}

void printArray(int array[], int size)
{
    for (unsigned i = 0; i < size; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

int main()
{
    cout << "enter size of arithmetic sequence array: ";
    int size;
    cin >> size;
    int array[size];

    cout << "enter shift of elements in array: ";
    int shift;
    cin >> shift;

    fillArrayWithSequence(array, size);
    printArray(array, size);
    rotate(array, size, shift);
    printArray(array, size);

    return 0;
}