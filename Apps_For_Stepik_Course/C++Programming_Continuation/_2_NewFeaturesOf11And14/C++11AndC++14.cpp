#include <cstddef>
#include <type_traits>
int main() {
    return 0;
}
/* what's new in C++11 & C++14
 * 1. fixed problem with <<>> which previously required to write < < > > (with a space between >>)
 * now T<U<int>> is correct (>> is treated like > > and not like operator >>)
 *
 * 2. per-byte copying is available not only for structures, but for classes as well \
 * added definition of 'trivial class' and 'class with standard placement' \
 * now it's easier to predict how class'es data is organized in memory
 *
 * 3. added 'explicit' for casting operator - instead of safe-bool idiom
 *
 * 4. added 'template typedef' - in fact adding synonym for a template:
 * template<class A, class B, class C>
 * class SomeType;
 * template <typename B>
 * using TypedefName = SomeType<double, B, 5>;
 *
 * in fact we move from older 'typedef' with complicated syntax to 'using' with simpler syntax:
 * typedef void(*OtherType)(double);
 * using OtherType = void (*)(double);
 */
struct Class {};
typedef int *(Class::*Foo)(int, double) const; // old style
using Foo = int *(Class::*)(int, double) const; // new style

/* what else new:
 *
 * added type 'long long int'
 *
 * added type traits - via #include <type_traits>
 *
 * added operators: alignof & alignas:
 * alignas(float) unsigned char c[sizeof(float)];
 *
 * added static assert:
 */
template<class T>
// now we'll check if this type is signed or unsigned or non-numerical at all
void run(T *data, size_t n) {
    static_assert(std::is_signed<T>::value, "T is not signed"); // works during compile time
}

// checking how 'explicit/ for casting operator works in new standard:
#include <iostream>
using std::string;
struct String {
    String(const string &) {}
    explicit operator char const *() const {}
};
void checkAllVariants() { // if we remove upper 'explicit' - all commented code here begin to compile
    String s("Hello");
//    delete s;
//    if (s) {}
//    char const *p1 = s;
    char const *p2 = (char const *) s;
    char const *p3 = static_cast<char const *>(s);
//    char const *s2 = s + 4;
}

// a new type std::nullptr_t was added - it contains only one literal 'nullptr' \
// it was done to eliminate inconsistency of using 0 value for pointers - because it's int anyway:
int f(int a) { return 1; }
int f(int *p) { return 2; } // think that we'd like to call this particular function
void use() {
    f(0); // explicit call of f(int a);
    // but what if we passed a pointer value there - not int - then we have to cast it to pointer:
    f((int *) 0); // now correct function is called - this syntax is used in C++98/03
    f(nullptr); // the same as before but looks better and much more predictable
}
// note that 'nullptr' can be implicitly casted to pointer of any type