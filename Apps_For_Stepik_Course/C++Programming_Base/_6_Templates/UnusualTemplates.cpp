/* template parameters can be:
 * types, - that's already well known
 * int values, - must be defined during compilation time - that's why setting a dimension to an array begin to matter
 * pointers or references with external linking, - must be either global variables or static field of class
 * other templates - we can just wrap one template into another like a type
 */

#include <cstddef>
#include <iostream>

using namespace std;

// sample of using integer values as parameters - matrix multiplication:
template<class T, size_t N, size_t M> // N and M must be already known at compile time
struct Matrix {
    // ...
    T &operator()(size_t i, size_t j) { return data_[M * j + i]; }
private:
    T data_[N * M];
};
// as we know - only matrix with equal dimensions can be multiplied - so we define this rule by setting types (M)
template<class T, size_t N, size_t M, size_t K>
Matrix<T, N, K> operator*(Matrix<T, N, M> const &a, Matrix<T, M, K> const &b);

// using refs as template types - having different files as templating parameters for a logger
template<ostream &log>
struct FileLogger {
    FileLogger() { log << "Logging started.\n"; }
    ostream &PutRecord(string const &record) { return log << record; }
    ~FileLogger() { log << "Logging finished.\n"; }
};

// using templates as parameters
string toString(int i);

// SAMPLE 1 - we have an existing class Array: and we must define template type every time:
template<typename T>
struct Array {
    explicit Array(size_t size) : size_(size), data_(new T[size_]) {}
    size_t size() const { return size_; }
    T get(size_t i) const { return *(data_ + i); }
private:
    size_t size_;
    T *data_;
};
// this function works only with Array<> - not with lists, vectors, maps and other containers
Array<string> toStrings(Array<int> const &intArray) { // we must specify <type> every time here
    Array<string> stringArray(intArray.size());
    for (size_t i = 0; i != intArray.size(); ++i)
        stringArray.get(i) = toString(intArray.get(i));
    return stringArray;
}
// SAMPLE 2 - specifying complex template for processing all suitable types:
template<template<class> class Container>
Container<string> toStrings(Container<int> const &cInt) {
    Container<string> cString(cInt.size()); // this function works with ALL TYPES OF CONTAINERS
    for (size_t i = 0; i != cInt.size(); ++i)
        cString.get(i) = toString(cInt.get(i));
    return cString;
}

int main() {
    FileLogger<cout> fl1;
    FileLogger<cout> fl2;
    // here we using only one cout as parameter - but it's better anyway than nothing
    fl1.PutRecord("Logging to fl1\n");
    fl1.PutRecord("Logging to fl2\n");
    return 0;
}