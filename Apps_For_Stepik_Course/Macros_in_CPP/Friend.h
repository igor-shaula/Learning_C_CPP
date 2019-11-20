#ifndef _LEARNING_C_CPP_FRIEND_H
#define _LEARNING_C_CPP_FRIEND_H

#include <cstddef>
#include <iostream>

using namespace std;

struct StringWithFriend {
    // all possible content needed

    friend struct Friend; // now class Friend has full access to private fields of this struct
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

#endif //_LEARNING_C_CPP_FRIEND_H