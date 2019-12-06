#include <iostream>
using namespace std;

void checkOldWaysOfTypeCasting();

int main() {
    checkOldWaysOfTypeCasting();
    return 0;
}

template<typename T>
void println(T const &value) {
    cout << value << endl;
}

void checkOldWaysOfTypeCasting() {
    int a = 2, b = 3;

    // int -> double
    double d1 = a / 3; // losing precision and getting 0 in result - so obviously casting is needed
    println(d1);
    double d2 = (double) a / 3; // result is correct
    println(d2);
    auto d3 = (double) a / 3; // result is also correct
    println(d3);

    // double -> int
    double d = 2.13; // in all cases here we receive 2 as the answer - because we loose precision
    int i1 = d;
    println(i1);
    int i2 = (int) d; // not necessary when we're about to loose precision
    println(i2);
    auto i3 = (int) d; // not necessary when we're about to loose precision
    println(i3);
}