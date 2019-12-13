#ifndef C_PROGRAMMING_BASE_TASK_TEMPLATE_MINIMUM_HPP
#define C_PROGRAMMING_BASE_TASK_TEMPLATE_MINIMUM_HPP

#include <cstddef>
#include <array>

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

bool less(int a, int b) { return a < b; }
struct Greater {
    bool operator()(int a, int b) const { return a > b; }
};

template<typename T, typename C>
T minimum(Array<T> &array, C comparator) {
    T min = array[0];
    for (size_t i = 1; i != array.size(); ++i)
        if (comparator(array[i], min))
            min = array[i];
    return min;
} // and yes it works and is accepted by the platform - now i have my certificate with distinction :)

#endif //C_PROGRAMMING_BASE_TASK_TEMPLATE_MINIMUM_HPP