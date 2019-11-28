#include <iostream>
using namespace std;

class IntArray
{
    // private by default - until public modifier is not set explicitly
    size_t size;
    int *data;

public:
    explicit IntArray(size_t size) : size(size), data(new int[size]) {}

    ~IntArray() { delete[] data; }

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

class IntArrayAlt
{              // different inner organization but its API for outer usage is the same
    int *data; // the only container - holds size in itself on the first position
public:
    explicit IntArrayAlt(size_t size) : data(new int[size + 1]) { data[0] = size; };

    ~IntArrayAlt() { delete[] data; }

    size_t size() { return data[0]; }

    int &get(size_t i) { return data[i + 1]; }
};

int main()
{
    return 0;
}