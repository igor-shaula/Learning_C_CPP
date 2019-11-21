#ifndef _LEARNING_C_CPP_SIMPLEPOINTER_HPP
#define _LEARNING_C_CPP_SIMPLEPOINTER_HPP

#include "iostream"

using namespace std;

class SimplePointer {

public:
    explicit SimplePointer(int *ptr) {
        ptr_ = ptr;
//        cout << "constructor worked" << endl;
    }

    ~SimplePointer() {
        delete ptr_;
//        cout << "destructor worked" << endl;
    }

    int &operator*() {
        return *ptr_;
    }

private:
    int *ptr_;
};

#endif //_LEARNING_C_CPP_SIMPLEPOINTER_HPP