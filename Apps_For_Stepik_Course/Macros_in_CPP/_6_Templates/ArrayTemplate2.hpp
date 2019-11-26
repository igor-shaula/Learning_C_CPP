#ifndef _LEARNING_C_CPP_ARRAY_TEMPLATE_HPP
#define _LEARNING_C_CPP_ARRAY_TEMPLATE_HPP

#include <cstddef>

/* operator= and T() are not defined - only copying constructor is defined for T
 */
template<typename T>
class Array {
private:
    size_t size_;
    T *data_;
public:
    explicit Array(size_t size, const T &value = T()) {
        size_ = size;
        data_ = (T *) operator new[](size_ * sizeof(T));
        for (size_t i = 0; i < size_; ++i)
            new(data_ + i) T(value);
    }
    Array() {
        size_ = 0;
//        data_ = (T *) operator new[](0);
//        new(data_) T(nullptr);
    }
    Array(Array const &other) {
        size_ = other.size_;

        data_ = (T *) operator new[](size_ * sizeof(T));
        for (size_t i = 0; i < size_; ++i)
            new(data_ + i) T(other.data_[i]);
    }
    ~Array() {
        for (size_t i = 0; i < size_; ++i)
//            data_[i].~T();
            (data_ + i)->~T(); // the same segmentation fault as with data_[i].~T();
        delete[] data_;
    }
    Array &operator=(Array const &otherE) {
        if (this != &otherE) {
            size_ = otherE.size_;

            for (size_t i = 0; i < size_; ++i)
                data_[i].~T();
            delete[] data_;

            data_ = (T *) operator new[](size_ * sizeof(T));
            for (size_t i = 0; i < size_; ++i)
                new(data_ + i) T(otherE.data_[i]);
        }
        return *this;
    }
    size_t size() const { return size_; }
    T &operator[](size_t i) { return data_[i]; }
    const T &operator[](size_t i) const { return data_[i]; }
};

#endif //_LEARNING_C_CPP_ARRAY_TEMPLATE_HPP