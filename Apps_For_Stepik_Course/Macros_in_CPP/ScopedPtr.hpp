#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-use-equals-delete"
#ifndef _LEARNING_C_CPP_SCOPEDPTR_HPP
#define _LEARNING_C_CPP_SCOPEDPTR_HPP

#include <iostream>

using namespace std;

struct Expression;
struct Number;
struct BinaryOperation;

struct ScopedPtr {
    explicit ScopedPtr(Expression *ptr = nullptr) {
        cout << "constructor : counter was: " << counter << endl;
        if (ptr != nullptr) {
            ptr_ = ptr;
            counter++;
            cout << "constructor : counter is: " << counter << endl;
        }
    }

    ~ScopedPtr() {
        counter--;
        cout << "destructor : counter is: " << counter << endl;
        if (counter <= 0) {
            delete ptr_; // memory leak emerges if this deletion is absent
            ptr_ = nullptr;
            cout << "destructor : nullified ptr_" << endl;
        }
    }

    Expression *get() const {
        return ptr_;
    }

    Expression *release() {  // as i understand, counter has to remain untouched here
        Expression *tmp = ptr_;
        ptr_ = nullptr;
        return tmp;
    }

    void reset(Expression *ptr = nullptr) {
        delete ptr_; // memory leak emerges if this deletion is absent
        ptr_ = ptr;
    }

    Expression &operator*() const {
        return *ptr_;
    }

    Expression *operator->() const {
        return ptr_;
    }

private:
    ScopedPtr(const ScopedPtr &);

    ScopedPtr &operator=(const ScopedPtr &);

    Expression *ptr_;
    int counter = 0;
};

#endif //_LEARNING_C_CPP_SCOPEDPTR_HPP
#pragma clang diagnostic pop