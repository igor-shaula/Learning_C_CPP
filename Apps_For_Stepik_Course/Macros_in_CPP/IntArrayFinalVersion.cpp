struct IntArray
{
    // it's decided to have no default constructor
    explicit IntArray(size_t size) : size_(size), data_(new int[size]) // preventing from assigning over '={n}'
    {
        for (size_t i = 0; i != size_; ++i)
            data_[i] = 0; // initialization by default to prevent any garbage inside array elements
    }
    // we need our custom copying constructor:
    IntArray(IntArray const &a) : size_(a.size_), data_(new int[size_])
    {
        for (size_t i = 0; i != size_; ++i)
            data_[i] = a.data_[i]; // in fact this is the only real difference from previous constructor
    }
    // as we have custom constructors - we need custom destructor as well:
    ~IntArray() { delete[] data_; }
    // if we have custom copying constructor - we have to customize assigning operator:
    IntArray &operator=(IntArray const &a)
    {
        if (this != &a)
            IntArray(a).swap(*this);
        return *this;
    }
    void swap(IntArray &a)
    {
        std::swap(size_, a.size_);
        std::swap(data_, a.data_);
    }

private:
    size_t size_;
    int *data_;
};