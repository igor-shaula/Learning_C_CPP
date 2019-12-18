#include <iostream>

struct Number {};

struct BigInt : Number {
    BigInt(int x);
};

struct String {
    explicit String(char const *s);
};

int main() {
    // checking all cases where use of static_cast<> is inevitable:
    int a = static_cast<int>(3.5);
    double b = static_cast<double>(7);
    BigInt c = static_cast<BigInt>(100500); // undefined reference to `BigInt::BigInt(int)'
    String d = static_cast<String>("Stepik"); // undefined reference to `String::String(char const*)'
    Number *e = static_cast<Number *>(&c);
    BigInt *f = static_cast<BigInt *>(e); // i checked this but it compiles
    void *g = static_cast<void *>(f);
    BigInt *h = static_cast<BigInt *>(g); // i checked this but it compiles as well
    // in fact my results (accepted by Stepik) differ from local compilation results - that's strange!
}