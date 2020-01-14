#include <iostream>
using std::cout;
using std::endl;
using std::string;

void testString() {
    string s("a string");
    cout << noexcept(string()) << endl;
    cout << noexcept(string("copy")) << endl;
    cout << noexcept(string(std::move("move"))) << endl;
    cout << noexcept(s.operator=("=")) << endl;
//    cout << noexcept(s.operator=("==")) << endl; // i don't know how to write moving assignment operator
    cout << noexcept(s.~string()) << endl;
    cout << noexcept(s.size()) << endl;
    cout << noexcept(s.clear()) << endl;
}

int main() {
    testString();
    return 0;
}