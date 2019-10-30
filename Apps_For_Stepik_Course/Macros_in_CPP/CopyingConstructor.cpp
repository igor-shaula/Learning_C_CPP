struct IntArray
{
    IntArray(size_t i) : size(i) { data = new int[size]; }

private:
    size_t size;
    int *data;
};

int main()
{
    IntArray a1(10);  // array is created in memory
    IntArray a2(20);  // creating another region in memory
    IntArray a3 = a1; // here in fact COPYING occurs: size and data are copied from a1 to a3
    a2 = a1;          // MEMORY LEAK here - because we lost any way of accessing previous region of memory for a2
    return 0;
    // 1 - destructor for a3 is invoked - it clears size 10 and array under *data
    // 2 - destructor for a2 is invoked - but as a1 and a2 are the same - this region of memory is already cleared
    // 3 - destructor for a1 is invoked - but again we have error here as memory cannot be cleared more than once
}