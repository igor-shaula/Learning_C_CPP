#ifndef _LEARNING_C_CPP_ARRAY_TEMPLATE_HPP
#define _LEARNING_C_CPP_ARRAY_TEMPLATE_HPP

#include <cstddef>

/* operator= and T() are not defined - only copying constructor is defined for T
 * besides there is no guarantee that we have predefined ~T() also
 * so all memory management has to be done by ourselves
 */
template<typename T>
class Array {
private:
    size_t size_;
    T *data_;
    void allocateMemoryForData() {
//        data_ = (T *) new char[size_ * sizeof(T)];
        data_ = (T *) operator new[](size_ * sizeof(T));
    }
    void initializeOneObject(size_t const i, T const &value) {
        new(data_ + i) T(value);
    }
    void initializeMemoryForData(T const &value) {
        for (size_t i = 0; i < size_; ++i)
//            new(data_ + i) T(value);
            initializeOneObject(i, value);
    }
    void clearAllocatedMemory() {
        for (size_t i = 0; i < size_; ++i)
            data_[i].~T();
//            (data_ + i)->~T(); // the same segmentation fault as with data_[i].~T();
//        delete[] data_;
        operator delete[](data_);
    }
public:
    explicit Array(size_t const size, T const &value = T()) {
        size_ = size;
        allocateMemoryForData();
        initializeMemoryForData(value);
    }
    Array() {
        size_ = 0;
//        data_ = (T *) operator new[](0);
//        new(data_) T(nullptr);
    }

    Array(Array const &other) {
        size_ = other.size_;
        allocateMemoryForData();
        for (size_t i = 0; i < size_; ++i)
            initializeOneObject(i, other.data_[i]);
    }
    ~Array() {
        clearAllocatedMemory();
    }
    Array &operator=(Array const &otherE) {
        if (this != &otherE) {
            size_ = otherE.size_;
            clearAllocatedMemory();
            allocateMemoryForData();
            for (size_t i = 0; i < size_; ++i)
                initializeOneObject(i, otherE.data_[i]);
        }
        return *this;
    }
    size_t size() const { return size_; }
    T &operator[](size_t i) { return data_[i]; }
    const T &operator[](size_t i) const { return data_[i]; }
};

#endif //_LEARNING_C_CPP_ARRAY_TEMPLATE_HPP