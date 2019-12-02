#ifndef C_PROGRAMMING_BASE_TEMPLATE_SPECIALIZATION_HPP
#define C_PROGRAMMING_BASE_TEMPLATE_SPECIALIZATION_HPP

#include <cstddef>

template<class T>
struct Array {
    // ...
    T *data_; // every T object has at least 1 byte but what if we want to store booleans in 1 bit ???
};
template<> // absence of type means that we deal with full specialization of class
struct Array<bool> { // here we adapt our template class Array to work with exact type
    /* it's not specified how many bytes are used for storing one bool value - but it's 1 byte at least
     * but we'd like to save memory and store every bool value in every bit - that's our purpose here \
     * but as always there is one rule - if we gain in memory - we loose in performance
     */
private:
    size_t size_;
    int *data_; // we'll store booleans inside bits of ints and save memory using this specialization
public:
    static int const BITS_IN_INT = 8 * sizeof(int);
    explicit Array(size_t size) : size_(size), data_(new int[size_ / BITS_IN_INT + 1]) {} // magic...
    bool operator[](size_t i) const { // we could return non-const reference - but it's much harder
        return data_[i / BITS_IN_INT] & (1 << (i % BITS_IN_INT)); // again some magic here
    }
    /* here we have only getter, similarly we can write a setter - i'll do it but some later */
};

#endif //C_PROGRAMMING_BASE_TEMPLATE_SPECIALIZATION_HPP