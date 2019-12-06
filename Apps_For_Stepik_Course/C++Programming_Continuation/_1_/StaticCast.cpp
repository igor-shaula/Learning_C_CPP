#include <iostream>
using namespace std;

/* static_cast is used for related types casting ,
 * works during compilation time only ,
 * allows to perform 4 types of conversion:
 * 1 - standard: number-types, ref/ptr to ref/ptr to base class, T* -> void* \
 * 2 - custom: for user-created type - goes via invocation of constructor and use of operator = \
 * 3 - reverse: ref/ptr to base class -> ref/ptr to child class (downcast) and void* -> T* \
 * 4 - casting to void \
 */

int main() {

    double d1 = 2 / 3 * 100;
    cout << d1 << endl;
    double d2 = static_cast<double>(2) / 3 * 100;
    cout << d2 << endl;
    // as we see from output - the result from d1 and d2 is completely different - 0 and 66.(6)

    d2 = static_cast<int>(1.2); // result is obvious here
    cout << d2 << " size in bytes: " << sizeof(d2) << endl;

    struct Person {
        Person(const char string[5]);
    };
    Person p = static_cast<Person>("Ivan"); // constructor will definitely be invoked here

    return 0;
}