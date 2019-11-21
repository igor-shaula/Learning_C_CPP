#ifndef _LEARNING_C_CPP_SIMPLESTSMARTPOINTER_HPP
#define _LEARNING_C_CPP_SIMPLESTSMARTPOINTER_HPP

#include "iostream"

using namespace std;

class SimplestSmartPointer {

public:
    explicit SimplestSmartPointer(int *ptr) {
        ptr_ = ptr;
//        cout << "constructor worked" << endl;
    }

    ~SimplestSmartPointer() {
        delete ptr_;
//        cout << "destructor worked" << endl;
    }

    int &operator*() {
        return *ptr_;
    }

private:
    int *ptr_;
};

#endif //_LEARNING_C_CPP_SIMPLESTSMARTPOINTER_HPP