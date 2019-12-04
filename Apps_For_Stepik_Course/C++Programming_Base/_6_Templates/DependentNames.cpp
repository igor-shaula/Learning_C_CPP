#include <cstddef>
#include <iostream>
using namespace std;

template<class T>
struct Array {
// ...
    typedef T value_type; // explicitly creating this synonym for later use as an element's type
    explicit Array(int size) : size_(size), data_(new T[size_]) {}
    size_t size() const { return size_; }
    T const &operator[](size_t i) const { return *(data_ + i); }
private:
    size_t size_;
    T *data_;
};
// we want a function that detects if a value of unknown type is present in this type container:
template<class Container>
bool contains(Container const &c, typename Container::value_type const &v) {
    // 'typename' is required for compiler to detect 'value_type' as a type - not as a static field
    for (size_t i = 0; i != c.size(); ++i)
        if (c[i] == v)
            return true;
    return false;
}

int main() {
    Array<int> a(10);
    cout << contains(a, 0) << endl; // by default array has to have zeroes inside -> 1 as output
    cout << contains(a, 1) << endl; // here we have to receive 0 in cout - because we get false
    return 0;
}