#include <iostream>
using namespace std;

class IntArray
{
    // private by default - until public modifier is not set explicitly
    size_t size;
    int *data;

public:
    explicit IntArray(size_t size) : size(size), data(new int[size]) {}

    ~IntArray()
    {
        delete[] data;
    }

    size_t size() { return size; }

    int &get(size_t i) { return data[i]; }

    // sample of invariant for this class:
    void resize(size_t newSize)
    {
        int *newData = new int[newSize];
        size_t limit = newSize < size ? newSize : size;
        for (size_t i = 0; i != limit; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        size = newSize;
    }
};

int main()
{
    return 0;
}