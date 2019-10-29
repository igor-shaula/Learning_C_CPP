// methods can be constant as well:
struct IntArray
{
    size_t size() const // this method has implicit "this" of type "IntArray const* "
    // "const" is a part of signature of a method - but the type of returning value is not!
    {
        return size;
    }
    void resize();                 // will be of use a bit later
    IntArray *createConst() const; // fix in declaration needed

    // we can define two versions of a method - usual and const:
    int get(size_t i) const // does not modify anything
    {
        return data[i]; // data is a pointer and it's constant here - we cannot change this value
        counter++;      // keyword "mutable" allows us to change this value even inside constant method!
    }
    int &get(size_t i) { return data[i]; } // returns a link with which we can modify content under it
private:
    size_t size;
    int *data;
    mutable size_t counter; // changing of this value is allowed inside constant method
    // but be careful with mutable - it should not influence on logical constancy!
};

// constant methods cannot change fields of structure - because their "this" points to const

// only constant methods can be invoked on constant objects:
IntArray const *p = createConst();
p->resize(); // error here

// constant methods seem useful to serve like getters in my opinion