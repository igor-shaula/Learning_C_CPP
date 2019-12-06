#include <iostream>
using namespace std;

/* static_cast is used for RELATED types casting ,
 * works during compilation time only ,
 * allows to perform 4 types of conversion:
 * 1 - standard: all built-in number types, ref/ptr to ref/ptr to base class, T* -> void* \
 * 2 - custom: for related types - goes via invocation of constructor and use of operator = \
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
        Person(const char *);
    };
    struct User : Person {
        User(struct Person person);
    };
//    Person p = static_cast<Person>("Ivan"); // constructor will definitely be invoked here
//    User u1 = (User) p; // how is it possible ?
//    User u2 = static_cast<User>(p);

    // expanding of type:
    float f = 3.14F;
    double d = static_cast<double>(f);
    cout << d << " size in bytes: " << sizeof(d) << endl;

    return 0;
}