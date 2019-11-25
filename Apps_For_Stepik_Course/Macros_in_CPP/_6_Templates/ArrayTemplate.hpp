#ifndef _LEARNING_C_CPP_ARRAY_TEMPLATE_HPP
#define _LEARNING_C_CPP_ARRAY_TEMPLATE_HPP

#include <cstddef>

template<typename T>
class Array {
private:
    size_t size_;
    T *data_;
public:
    explicit Array(size_t size = 0, const T &value = T()) : size_(size), data_(new T[size_]) {
        for (size_t i = 0; i < size_; ++i)
            data_[i] = value;
    }
    Array(const Array &other) {
        size_ = other.size_;
        data_ = new T[size_];
        for (size_t i = 0; i < size_; ++i)
            data_[i] = other.data_[i];
    }
    ~Array() {
        /* for some reason this deletion of every object is not needed by the task */
//        for (size_t i = 0; i < size_; ++i)
//            delete &data_[i]; // & because data_[i] is actually an object - and we need ptr to it
        delete[] data_;
    }
    Array &operator=(Array const &other) {
        if (this != &other) {
            size_ = other.size_;
            /* here we skip deletion of every inner object as well as in destructor */
//            for (size_t i = 0; i < size_; ++i)
//                delete &data_[i]; // & because data_[i] is actually an object - and we need ptr to it
            delete[] data_;
            data_ = new T[size_];
            for (size_t i = 0; i < size_; ++i)
                data_[i] = other.data_[i];
        }
        return *this;
    }
    size_t size() const { return size_; }
    T &operator[](size_t i) { return data_[i]; }
    const T &operator[](size_t i) const { return data_[i]; }
};

#endif //_LEARNING_C_CPP_ARRAY_TEMPLATE_HPP