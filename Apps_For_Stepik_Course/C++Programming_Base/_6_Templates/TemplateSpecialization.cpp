#include "TemplateSpecialization.hpp"
#include <iostream>

using namespace std;

/* DIFFERENCE BETWEEN OVERLOADING AND SPECIALIZATION */

template<class T>
void foo(T a, T b) { cout << "first for same types" << endl; }
// in fact only this variant will be used in given sample of invocation in main() - because it uses only 1 type

template<class T, class V>
void foo(T a, V b) { cout << "overloaded for different types" << endl; }
// overloaded variant of our first function 'foo' - the main point here is that it uses 2 different types

template<>
void foo<int, int>(int a, int b) { cout << "specialized only for ints" << endl; }
// specialization for our function 'foo' - but note that for first variant as it uses only one type int like T

int main() {
    foo(3, 4); // IDE points to specialized function but IN FACT IT WILL NOT BE SELECTED BY COMPILER
    /* OVERLOADING WORKS FIRST in compilation process - that's why selection might not be easily visible */
    return 0;
}