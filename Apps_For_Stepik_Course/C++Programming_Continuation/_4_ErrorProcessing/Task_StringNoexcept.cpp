#include <iostream>
using std::cout;
using std::endl;
using std::string;

void testString() {
    string s("a string");
    string a;
    cout << noexcept(string()) << endl;
    cout << noexcept(string(a)) << endl;
//    cout << noexcept(string("move")) << endl;
    cout << noexcept(std::move(string("move"))) << endl; // in result it seem to work via copying
    cout << noexcept(s.operator=(a)) << endl;
//    cout << noexcept(s.operator=("==")) << endl;
    cout << noexcept(std::move(s.operator=("=="))) << endl; // in result it seem to work via copying
    cout << noexcept(s.~string()) << endl;
    cout << noexcept(s.size()) << endl;
    cout << noexcept(s.clear()) << endl;
}

int main() {
    testString();
    return 0;
}