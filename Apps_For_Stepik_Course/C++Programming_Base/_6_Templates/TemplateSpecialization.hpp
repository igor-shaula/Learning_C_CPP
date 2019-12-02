#ifndef C_PROGRAMMING_BASE_TEMPLATE_SPECIALIZATION_HPP
#define C_PROGRAMMING_BASE_TEMPLATE_SPECIALIZATION_HPP

#include <cstddef>

/* FULL SPECIALIZATION FOR CLASS */
template<class T>
struct Array {
private:
    T *data_; // every T object has at least 1 byte but what if we want to store booleans in 1 bit ???
public:
    T &operator[](size_t i) { return data_[i]; } // plain setter returning reference to the value
    // ...
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

/* PARTIAL SPECIALIZATION FOR CLASSES - for many of them - not for only one */
template<class T>
struct Array<T *> { // all variants of arrays of pointers - for many types actually
private:
    size_t size_;
    T **data_; // just an array of pointers to type T
public:
    explicit Array(size_t size) : size_(size), data_(new T *[size_]) {} // creating array of pointers to T
    T &operator[](size_t i) { return *data_[i]; } // returning value instead of pointer in this case
};

/* FULL SPECIALIZATION FOR FUNCTION */
template<class T>
void swap(T &a, T &b) { // this is default approach - but there are some exclusions like shown underneath
    T tmp(a);
    a = b;
    b = tmp;
}
// let we have class Database which is big and heavy - so it has no copying constructor and operator =
struct Database {
    void swap(Database &other) {} // we have to have this method defined in this class
};
template<>
void swap<Database>(Database &a, Database &b) { a.swap(b); } // so we're not using 'tmp' for Database objects
// partial specialization for functions DO NOT EXIST at all

/* OVERLOADING INSTEAD OF TEMPLATE SPECIALIZATION */
template<class T>
// we see that there is no specialization here because template type is defined
void swap(Array<T> &a, Array<T> &b) { a.swap(b); } // method 'swap' has to be defined in class Array
// it's better to use overloading instead of specialization for functions

#endif //C_PROGRAMMING_BASE_TEMPLATE_SPECIALIZATION_HPP