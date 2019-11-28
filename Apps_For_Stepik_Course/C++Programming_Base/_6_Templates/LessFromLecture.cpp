#include "iostream"

using namespace std;

int main() { return 0; }

// reloaded version of operator () - we're doing this to use object like function later
struct Less {
    bool operator()(int a, int b) { return a < b; } // has priority over plain function invocation
};

bool less_(int a, int b) { return a < b; } // has lower priority than reloaded operator

void test() {
    Less less_; // if we remove this line - there will be no less_ object and plain less_() function will be used
    if (less_(10, 20)) { // operator is actually a method and its type is bool - so we can use it here
        cout << "10 < 20" << endl;
    } else {
        cout << "10 >= 20" << endl;
    }
    // in the sample above overloaded operator () on object is used over plain invocation of function with the same name
}