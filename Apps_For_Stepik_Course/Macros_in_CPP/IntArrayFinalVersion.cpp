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

    size_t size() const { return size_; } // remember that getter has to be const

    int get(size_t i) const { return data_[i]; } // again getter and again const

    int &get(size_t i) { return data_[i]; } // this time returns a link - so we can read & write using it

    void resize(size_t newSize)
    {
        IntArray t(newSize); // creating new instance using constructor from above
        size_t n = size_ < newSize ? size_ : newSize;
        for (size_t i = 0; i != n; ++i)
            t.data_[i] = data_[i];
        swap(t); // to use 't' instead of 'this', on which we in fact invoke this 'swap' method;
        // above line is the same as '*this.swap(t);' or 't.swap(*this);'
    }
    // about possible memory leak here - 't' instance has to be deleted automatically on '}' above

private:
    size_t size_;
    int *data_;
};