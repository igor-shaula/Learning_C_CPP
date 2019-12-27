#include <array>
#include <iostream>

using namespace std;

void showArray() {
    // std::array<T> is a wrapper over standard array with addition of STL container's API
    array<string, 2> a = {"one", "two"};
    cout << a.size() << endl;
    cout << a.data() << endl; // how to set a new pointer into with non-const data() ???
    cout << a[1] << endl;
    string s = "three";
    a = {"three", "four"};
    *(a.data()) = s;
    cout << a[0] << endl;
}

int main() {
    showArray();
    return 0;
}