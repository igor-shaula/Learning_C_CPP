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

int main()
{
    // 1 - swap
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
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;

    return 0;
}