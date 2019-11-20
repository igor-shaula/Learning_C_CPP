#ifndef _LEARNING_C_CPP_SIMPLESTSMARTPOINTER_HPP
#define _LEARNING_C_CPP_SIMPLESTSMARTPOINTER_HPP

#include "iostream"

using namespace std;

class SimplestSmartPointer {

public:
    SimplestSmartPointer(string *ptr) {
        ptr_ = ptr;
        cout << "constructor worked" << endl;
    }

    ~SimplestSmartPointer() {
        delete ptr_;
        cout << "destructor worked" << endl;
    }

    string &operator*() {
        return *ptr_;
    }

private:
    string *ptr_;
};

#endif //_LEARNING_C_CPP_SIMPLESTSMARTPOINTER_HPP