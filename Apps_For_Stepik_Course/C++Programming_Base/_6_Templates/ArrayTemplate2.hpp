#ifndef _LEARNING_C_CPP_ARRAY_TEMPLATE_HPP
#define _LEARNING_C_CPP_ARRAY_TEMPLATE_HPP

#include <cstddef>
//#include <new>

/* operator= and T() are not defined - only copying constructor is defined for T
 * besides there is no guarantee that we have predefined ~T() also
 * so all memory management has to be done by ourselves
 */
template<typename T>
class Array {
private:
    size_t size_;
    T *data_;
    void allocateNewMemoryForDataWithNewChar() {
        data_ = (T *) new char[size_ * sizeof(T)];
//        data_ = (T *) operator new[](size_ * sizeof(T));
    }
    void initializeOneObject(size_t const i, T const &value) {
        new(data_ + i) T(value);
    }
    void initializeMemoryForData(T const &value) {
        for (size_t i = 0; i < size_; ++i)
//            new(data_ + i) T(value);
            initializeOneObject(i, value);
    }
    void copyMemoryFromOther(Array const &other) {
        for (size_t i = 0; i < size_; ++i)
            initializeOneObject(i, other.data_[i]);
    }
    void deleteAllocatedMemory() {
        for (size_t i = 0; i < size_; ++i)
//            data_[i].~T();
            delete (data_ + i);
//            (data_ + i)->~T(); // the same segmentation fault as with data_[i].~T();
//        delete[] data_;
//        operator delete[](data_);
    }
public:
    explicit Array(size_t const size, T const &value) {
        size_ = size;
        allocateNewMemoryForDataWithNewChar();
        initializeMemoryForData(value);
    }
    Array() {
        size_ = 0;
//        data_ = (T *) operator new[](0);
//        data_ = (T *) new char[0];
//        new(data_) T(0);
    }
    Array(Array const &other) {
        size_ = other.size_;
        allocateNewMemoryForDataWithNewChar();
        copyMemoryFromOther(other);
    }
    Array &operator=(Array const &other) {
        if (this != &other) {
            size_ = other.size_;
            deleteAllocatedMemory();
            allocateNewMemoryForDataWithNewChar();
            copyMemoryFromOther(other);
        }
        return *this;
    }
    ~Array() {
        deleteAllocatedMemory();
    }
    size_t size() const { return size_; }
    T &operator[](size_t i) { return *(data_ + i); }
    const T &operator[](size_t i) const { return *(data_ + i); }
};

#endif //_LEARNING_C_CPP_ARRAY_TEMPLATE_HPP