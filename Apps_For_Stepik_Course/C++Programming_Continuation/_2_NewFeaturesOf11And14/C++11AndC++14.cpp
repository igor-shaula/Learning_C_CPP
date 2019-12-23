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
