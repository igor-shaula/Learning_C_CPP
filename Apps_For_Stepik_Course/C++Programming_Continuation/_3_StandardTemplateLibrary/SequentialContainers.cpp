#include <iostream>

#include <array>
#include <vector>

using namespace std;

template<class T>
void println(T const &value) {
    cout << value << endl;
}

/* common methods for all containers except 'array':
 * constructor from two arguments,
 * constructor from 'count' and 'defVal',
 * constructor from std::initializer_list<T>,
 * front(), back(),
 * push_back(), emplace_back(),
 * assign(),
 * insert(),
 * emplace(),
 * erase() from 1 or 2 iterators
 */

void showArray() {
    // std::array<T> is a wrapper over standard array with addition of STL container's API
    array<string, 2> a = {"one", "two"};
    println(a.size());
    println(a.data());
    println(a[1]);
    string s = "three";
    a = {"three", "four"};
    *(a.data()) = s; // <- how to set a new pointer into with non-const data()
    println(a.at(0));
}

void showVector() {
    // std::vector<T> is a dynamic array with auto-resize during addition of new elements
    vector<string> v = {"one", "two"};
    println(v.size());
    println(v.capacity());
    println("at 1: " + v.at(1));
    v.resize(4);
    println(v.size());
    println(v.capacity());
    println("at 3: " + v.at(2));
    v.reserve(9);
    println(v.size());
    println(v.capacity());
    println(v.data());
}

int main() {
    showArray();
    showVector();
    return 0;
}