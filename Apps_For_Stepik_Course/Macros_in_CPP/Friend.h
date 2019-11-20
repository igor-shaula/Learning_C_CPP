#ifndef _LEARNING_C_CPP_FRIEND_H
#define _LEARNING_C_CPP_FRIEND_H

#include <cstddef>
#include <iostream>

using namespace std;

struct StringWithFriend {
    // all possible content needed

    friend struct Friend; // now class Friend has full access to private fields of this struct

    /* making function/method/operator of outer class able to work with this class */
    friend ostream &operator<<(std::ostream &os, StringWithFriend const &s) {
        return os << s.data_; // able to access private fields of this class
    } // declared & defined at once - in fact this friend function is 'inline'

private:
    char *data_;
    size_t size;
};

class Friend {
    static void append(StringWithFriend const &s) {
        append(s.data_); // MAIN THING HERE - we got access to private field of outer class
    }

    static void append(char const *data) {
        cout << "StringWithFriend -> append invoked" << endl;
    }
};

//--------------------------------------------------------------------------------------------------

struct A; // declaring here to be able to use it in the following struct B

struct B {
    void functionOfB(A const &aRef); // only declaring here as there is no definition of struct A
    /* that's needed to be able to compile using 'friend' in struct A */
};

struct A {
    /* here we can immediately define this method but it's better to do it outside later */
    friend void B::functionOfB(A const &aRef); // only allowed to use this method in struct B
    /* declaration of functionOfB must be done before this */
private:
    char *data;
};

/* if we write this in header - inline is a must to avoid duplication of this method in cpp files */
inline void B::functionOfB(A const &aRef) {
    cout << aRef.data << endl; // can access private data from A via friend function opened for B
}
/* another reason of using 'inline' here is that this method is defined outside of its class */

#endif //_LEARNING_C_CPP_FRIEND_H