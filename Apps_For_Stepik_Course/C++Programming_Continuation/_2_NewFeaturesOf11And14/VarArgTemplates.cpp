// in C we can pass variable number of arguments into a function using ... for arguments' list \
// the same story is added but for templates \

// in this sample we'll use template varargs for recursive C++ 'printf()' realization:

#include <iostream>
using std::cout;
using std::endl;

// base of recursion:
void printf(char const *s) {
    while (*s) { // till the end of the string
        if (*s == '%' && *(++s) != '%') // we need only one '%' and check for the next symbol
            cout << "error - found one %" << endl;
        cout << *s++; // printing one symbol and preparing to the next loop iteration
    }
}
template<typename T, typename ...Args>
void printf(char const *s, T value, Args... args) {
    while (*s) {
        if (*s == '%' && *(++s) != '%') {
            cout << value;
            printf(++s, args...);
            return;
        }
        cout << *s++;
    }
    cout << "error" << endl;
}