#ifndef _LEARNING_C_CPP_SIMPLE_SAMPLE_HPP
#define _LEARNING_C_CPP_SIMPLE_SAMPLE_HPP

#include "iostream"

/* solution in C-style - templating via macros */
#define ARRAY_OVER_MACRO(Name, Type) \
struct Name { \
    explicit Name(size_t size) : data_(new Type[size]), size_(size) {} \
    ~Name() { delete[] data_; } \
    size_t size() const { return size_; } \
    Type operator[](size_t i) const { return data_[i]; } \
    Type & operator[](size_t i) { return data_[i]; } \
    /* something else */ \
private: \
    Type * data_; \
    size_t size_; \
}; // all this must be one line - backslashes serve only for this purpose
/* this approach has great minus - debugging is complicated  */

#endif //_LEARNING_C_CPP_SIMPLE_SAMPLE_HPP

/* solution in C++ style - creating real templates */
template<class Type>
struct Array {
private:
    Type *data_;
    size_t size_;
public:
    explicit Array(size_t size) : data_(new Type[size]), size_(size) {}
    ~Array() { delete[] data_; }
    size_t size() const { return size_; }
    Type operator[](size_t i) const { return data_[i]; }
    Type &operator[](size_t i) { return data_[i]; }
};