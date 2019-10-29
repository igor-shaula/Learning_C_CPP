// methods can be constant as well:
struct IntArray
{
    size_t size() const;           // this method has implicit "this" of type "IntArray const* "
    void resize();                 // will be of use a bit later
    IntArray *createConst() const; // fix in declaration needed
};

// constant methods cannot change fields of structure - because their "this" points to const

// only constant methods can be invoked on constant objects:
IntArray const *p = createConst();
p->resize(); // error here

// constant methods seem useful to serve like getters in my opinion