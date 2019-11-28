#include "iostream"

using namespace std;

int main() { return 0; }

// reloaded version of operator () - we're doing this to use object like function later
struct Less {
    bool operator()(int a, int b) { return a < b; } // has priority over plain function invocation
};

bool less_(int a, int b) { return a < b; } // has lower priority than reloaded operator

template<class T, class Comp>
void sort(T *p, T *q, Comp less_) {} // there are many forms of using this template function
// we can pass object less_ with overloaded operator () and also pointer to function less()

void test() {
    Less less_; // if we remove this line - there will be no less_ object and plain less_() function will be used
    if (less_(10, 20)) { // operator is actually a method and its type is bool - so we can use it here
        cout << "10 < 20" << endl;
    } else {
        cout << "10 >= 20" << endl;
    }
    // in the sample above overloaded operator () on object is used over plain invocation of function with the same name

    int m[3] = {1, 2, 3};
    sort(m, m + 3, Less()); // by default sending instance of class Less
    sort(m, m + 3, less_); // sending pointer to function less_() if the object is absent
    // additional form allowed in C++11 or 14:
    sort(m, m + 10, [](int x, int y) { return x < y; });
}