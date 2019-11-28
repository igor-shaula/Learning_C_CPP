#ifndef _LEARNING_C_CPP_COMPLEX_TEMPLATE_HPP
#define _LEARNING_C_CPP_COMPLEX_TEMPLATE_HPP

#include "iostream"

template<class Type, // from now on we can use Type as existing normal type in any place of template
        class SizeT = size_t,
        class ConstRet = Type> // using already known type which will be set on compilation time
/* arguments can have default values - similarly to default parameters in a function declaration */
struct Array {
private:
    Type *data_;
    SizeT size_;
public:
    explicit Array(SizeT size = 0) : data_(new Type[size]), size_(size) {}
    ~Array() { delete[] data_; }
    SizeT size() const { return size_; }
    ConstRet operator[](SizeT i) const { return data_[i]; }
    Type &operator[](SizeT i) { return data_[i]; }
};

#endif //_LEARNING_C_CPP_COMPLEX_TEMPLATE_HPP