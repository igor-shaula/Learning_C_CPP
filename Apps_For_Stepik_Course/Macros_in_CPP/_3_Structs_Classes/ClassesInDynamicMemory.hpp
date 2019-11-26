#ifndef _LEARNING_C_CPP_CLASSES_IN_DYNAMIC_MEMORY_HPP
#define _LEARNING_C_CPP_CLASSES_IN_DYNAMIC_MEMORY_HPP

#include <cstddef>

/* standard example of simplest class ever */
struct IntArray {
    explicit IntArray(size_t size) : size_(size) {}
//    IntArray() : size_(-1) {} // gives 18446744073709551615 in cout
//    IntArray() : size_(1) {} // OK
//    IntArray() { size_ = -1; } // gives 18446744073709551615 in cout
    IntArray() { size_ = 1; } // OK
    ~IntArray() { delete[] data_; }
    size_t size() const { return size_; }
private:
    size_t size_ = 2;
    int *data_;
};

#endif //_LEARNING_C_CPP_CLASSES_IN_DYNAMIC_MEMORY_HPP