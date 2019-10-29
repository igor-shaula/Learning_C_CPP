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
    int get(size_t i) const { return data[i]; } // does not modify anything
    int &get(size_t i) { return data[i]; }      // returns a link with which we can modify content under it
private:
    size_t size;
    int *data;
};

// constant methods cannot change fields of structure - because their "this" points to const

// only constant methods can be invoked on constant objects:
IntArray const *p = createConst();
p->resize(); // error here

// constant methods seem useful to serve like getters in my opinion