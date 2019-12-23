// type deduction or type detection - of course during compilation time

// meaning of keyword 'auto' is different in old and new standards! - here the API of C++ is changed!
// new standard's 'auto' allows us to declare variables and helps with getting its type from Rvalue \
// 'decltype' figures out the type not by right value but for given expression or variable \\

#include <cstddef>
template<class Unit> // if we remove this - struct Array will not be compilable
//struct Unit {}; // it is too early to define this structure - we can live with templating
struct Array {
//    Array(Unit **pUnit) {}
    Unit **units_; // array of pointers to Unit objects
    size_t size() const { return 42; }
    Unit *operator[](size_t i) const { return units_[i]; }
    Array<Unit> &getArrayOfUnits() const {} // i don't know how to implement it correctly - and sample is absent
};
//template<class Item>
class Unit;
//class Unit {
//    Array<Item> items_;
//    Array<Item> &items() const { return items_; };
//}; // if we remove this - next line will not be compilable
Array<Unit *> units;

void f() {
    for (size_t i = 0; i != units.size(); ++i) {

        auto u = units[i]; // deduced type is: Unit * - this element will be COPIED
        decltype(units[i]) unit = units[i]; // type is Unit * const - NO COPYING HERE
        // so 'auto' and 'decltype' give different output - auto reduces 'const' and '&'

        // but constant reference can be obtained in this way:
        const auto &v = units[i]; // deduced type is: Unit * const &

        auto a = units.getArrayOfUnits(); // type is: Array<Unit>
        decltype(units.getArrayOfUnits()) b = a; // type: is Array<Unit> const &
        decltype(a) c = a; // type is: Array<Unit>
        decltype((a)) d = a; // type is: Array<Unit> & - special form - we give a variable here
        decltype(b) e = b; // type is: Array<Unit> const &
        decltype((b)) f = b; // type is: Array<Unit> const & - just outputs type of given variable
    }
}

// decltype does not evaluate given expression - it evaluates ONLY ITS TYPE

/* почему decltype от переменной возвращает тип этой переменной,
 * а decltype от выражения, содержащего переменную, возвращает ссылку на тип переменной?
 * На примере decltype(a) и decltype((a))
 * - разные версии decltype - одна для переменной, вторая для выражения
 */
#include <iostream>
#include <type_traits>

void test() {
    std::string s = "Compiler";
    auto sz = s.size();
    auto c1 = s[0];
    decltype(s[0]) c2 = s[7];
    decltype(s[0] + s[7]) c3 = s[1];
    decltype(s) sa = s;
    decltype((s)) sb = s;
    c1 = 'K';
    c2 = '!';
    std::cout << s << std::endl;
    std::cout << std::is_reference<decltype(sb)>::value << "\n";
}

int main() {
    test();
    return 0;
}