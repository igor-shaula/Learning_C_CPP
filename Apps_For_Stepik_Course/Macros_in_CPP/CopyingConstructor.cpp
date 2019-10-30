struct IntArray
{
    IntArray(size_t i) : size(i) { data = new int[size]; }

    // when we need completely new instance with its own memory:
    IntArray(IntArray const &a) : size(a.size), data(new int[size]) // our custom COPYING constructor
    // note that const & is present in method signature - to avoid passing object by its value
    {
        for (size_t i = 0; i != size; i++)
            data[i] = a.data[i]; // we in fact are creating another copy of data in memory
    }
    // if we haven't declared copying constructor ourselves - it would be created automatically

    // when we already have an instance but need to repoint it to a new region of memory:
    IntArray &operator=(IntArray const &a) // we need this because default behavior of "=" is different
    {
        if (this != &a)
        {
            delete[] data;        // preparing the place for data to be copied from "a" instance
            size = a.size;        // of course new size can be different
            data = new int[size]; // this memory is new and now is about to be initialized:
            for (size_t i = 0; i != size; i++)
                data[i] = a.data[i];
        }
        return *this; // taking object under "this" pointer
    }

    // useful method:
    void swap(IntArray &a) // just replaces fields of this and given object
    {
        size_t const t1 = size;
        size = a.size;
        a.size = t1;
        int *const t2 = data;
        data = a.data;
        a.data = t2;
    }
    void swapStd(IntArray &a) // does the same as previous custom swap
    {
        std::swap(size, a.size);
        std::swap(data, a.data);
    }
    // second variant of overriding operator '=' using method 'swap':
    IntArray &operator=(IntArray const &a) // in fact same functionality as in previous realization
    {
        // serves for memory efficiency - but there will be no mistakes this time if checking is absent
        if (this != &a)
            IntArray(a).swap(*this); // IntArray(a) gives us temporary instance
        return *this;
    }

private:
    size_t size;
    int *data;
};

int main()
{
    // samples & consequences for using DEFAULT (absent) copying constructor
    IntArray a1(10);  // array is created in memory
    IntArray a2(20);  // creating another region in memory
    IntArray a3 = a1; // here in fact COPYING occurs: size and data are copied from a1 to a3
    a2 = a1;          // MEMORY LEAK here - because we lost any way of accessing previous region of memory for a2
    return 0;
    // 1 - destructor for a3 is invoked - it clears size 10 and array under *data
    // 2 - destructor for a2 is invoked - but as a1 and a2 are the same - this region of memory is already cleared
    // 3 - destructor for a1 is invoked - but again we have error here as memory cannot be cleared more than once
}