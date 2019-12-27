#include <array>
#include <iostream>

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

int main() {
    showArray();
    return 0;
}