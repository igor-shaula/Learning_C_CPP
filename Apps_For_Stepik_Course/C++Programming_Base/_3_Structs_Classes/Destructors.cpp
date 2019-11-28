#include <iostream>
using namespace std;

struct IntArray
{
    size_t size;
    int *data;
    explicit IntArray(size_t size) : size(size), data(new int[size]) {}
    ~IntArray() // no need to pass any parameters here
    {
        // destructor is invoked automatically at the closing bracket "}"
        delete[] data; // without that memory leak would appear
        cout << "data in array is cleaned" << endl;
    }
};

int main()
{
    IntArray a = IntArray(5);
    cout << "array is created" << endl;
    return 0;
}