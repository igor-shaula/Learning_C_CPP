#ifndef C_PROGRAMMING_BASE_TASK_FLATTEN_ARRAY_HPP
#define C_PROGRAMMING_BASE_TASK_FLATTEN_ARRAY_HPP

#include <cstddef>
#include "iostream"

template<typename T>
class Array {
private:
    size_t size_;
    T *data_;
public:
    explicit Array(size_t = 0, const T &value = 0);
    Array(const Array &other);
    ~Array();
    Array &operator=(Array other);
    void swap(Array &other);
    size_t size() const;
    T &operator[](size_t i);
    const T &operator[](size_t i) const;
};

template<typename T>
void flatten(const Array<T> &array, std::ostream &out) {
    for (size_t i = 0; i != array.size(); ++i)
        out << array[i] << ' ';
}
template<typename T>
void flatten(const Array<Array<T>> &polyArray, std::ostream &out) {
    for (size_t i = 0; i != polyArray.size(); ++i)
        flatten(polyArray[i], out);
}

#endif //C_PROGRAMMING_BASE_TASK_FLATTEN_ARRAY_HPP