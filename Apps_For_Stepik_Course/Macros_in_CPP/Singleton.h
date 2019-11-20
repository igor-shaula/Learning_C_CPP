#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-use-equals-delete"
#pragma ide diagnostic ignored "hicpp-use-equals-default"

#ifndef _LEARNING_C_CPP_SINGLETON_H
#define _LEARNING_C_CPP_SINGLETON_H

#include "iostream"

using namespace std;

class Singleton {
    /* the main get-method must be static - as it is invoked when we might not have an object */
    static Singleton &instance() { // returning a link is the only possible output here
        static Singleton s; // default constructor will be invoked during first pass of this line
        return s; // this static local variable will live forever from the first invocation
    }

    string &data() { return data_; }

private:
    Singleton() {} // this constructor or any other must work only once during the app life
    Singleton(Singleton const &); // copying constructor doesn't need to be defined here
    Singleton &operator=(Singleton const &); // assignment operator is not needed for a singleton

    string data_;
};

#endif //_LEARNING_C_CPP_SINGLETON_H
#pragma clang diagnostic pop