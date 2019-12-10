// RTTI = Runtime Type Information \
// there are two ways of getting RTTI (or there are 2 components of RTTI) \
// 1 - operator 'typeid' and type std::type_info  - reviewed here \
// 2 - operator 'dynamic_cast' - reviewed some later \\

/* type_info =
 * it is a class declared in 'typeinfo' system header (what is it ?)
 * contains information about type
 * has methods: == , != , name , before (set by compiler)
 * has no public constructors and assignment operators
 * link to type_info for given type or value can be got from operator 'typeid'
 * new standard has additional method 'hashcode' for type_info
 */

#include <iostream>
#include <typeinfo>
using namespace std;

struct Unit {
    virtual ~Unit() {};
    // without virtual function table it's impossible to get information about children of this class
};
struct Elf : Unit {
//    Elf();
//    ~Elf() {}
};

int main() {

    Elf e;
    Unit &uRef = e;
    Unit *uPtr = &e;

    cout << typeid(uRef).name() << endl;
    cout << typeid(*uPtr).name() << endl;
    cout << typeid(uPtr).name() << endl;
    cout << typeid(e).name() << endl;
    cout << typeid(Elf).name() << endl;
    cout << (typeid(uRef) == typeid(Elf)) << endl;

    return 0;
}